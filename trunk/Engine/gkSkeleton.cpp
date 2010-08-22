/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 Charlie C.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#include "OgreEntity.h"
#include "OgreBone.h"
#include "OgreSkeleton.h"
#include "OgreSkeletonInstance.h"
#include "OgreSkeletonManager.h"
#include "OgreSkeleton.h"
#include "OgreSceneNode.h"

#include "gkSkeleton.h"
#include "gkAction.h"
#include "gkLogger.h"


// ----------------------------------------------------------------------------
gkBone::gkBone(const gkString &name)
	:    m_name(name), m_bone(0), m_bind(), m_parent(0)
{
	m_bind.setIdentity();
	m_pose.setIdentity();
}


// ----------------------------------------------------------------------------
gkBone::~gkBone()
{
}


// ----------------------------------------------------------------------------
void gkBone::setRestPosition(const gkTransformState &st)
{
	m_bind = st;
}



// ----------------------------------------------------------------------------
void gkBone::setParent(gkBone *bone)
{
	if (!bone)
		return;

	if (!m_parent)
	{
		m_parent = bone;
		m_parent->m_children.push_back(this);
	}
}



// ----------------------------------------------------------------------------
void gkBone::setOgreBone(Ogre::Bone *bone)
{
	m_bone = bone;
}




// ----------------------------------------------------------------------------
gkSkeleton::gkSkeleton(gkScene *scene, const gkString &name)
	:    gkGameObject(scene, name, GK_SKELETON),
	     m_controller(0),
	     m_skelLoader(0)
{
}


// ----------------------------------------------------------------------------
gkSkeleton::~gkSkeleton()
{
	Actions::Iterator iter = m_actions.iterator();
	while (iter.hasMoreElements())
		delete iter.getNext().second;

	Bones::Iterator biter = m_bones.iterator();
	while (biter.hasMoreElements())
		delete biter.getNext().second;

	if (m_skelLoader != 0)
		delete m_skelLoader;
}



// ----------------------------------------------------------------------------
void gkSkeleton::loadImpl(void)
{
	gkGameObject::loadImpl();

	createSkeleton();
	if (m_baseProps.isInvisible())
		m_node->setVisible(false);
}

// ----------------------------------------------------------------------------
void gkSkeleton::unloadImpl(void)
{
	gkGameObject::unloadImpl();
}


// ----------------------------------------------------------------------------
void gkSkeleton::setEntity(Ogre::Entity *ent)
{
	if (ent->hasSkeleton())
	{
		Ogre::SkeletonInstance *inst = ent->getSkeleton();

		if (!m_boneList.empty())
		{
			for (UTsize i=0; i<m_boneList.size(); ++i)
			{
				gkBone *bone = m_boneList.at(i);
				if (inst->hasBone(bone->getName()))
				{
					bone->setOgreBone(inst->getBone(bone->getName()));
					bone->getOgreBone()->setManuallyControlled(true);
				}
			}
		}
	}
}


// ----------------------------------------------------------------------------
gkBone *gkSkeleton::createBone(const gkString &name)
{
	if (hasBone(name))
		return 0;

	gkBone *manual = new gkBone(name);
	m_bones.insert(name, manual);
	m_boneList.push_back(manual);
	return manual;
}


// ----------------------------------------------------------------------------
gkAction *gkSkeleton::createAction(const gkHashedString &name)
{
	if (m_actions.find(name) != GK_NPOS)
	{
		gkPrintf("Skeleton: Duplicate action '%s'\n", name.str().c_str());
		return 0;
	}

	gkAction *act = new gkAction(name.str());

	m_actions.insert(act->getName(), act);
	return act;
}



// ----------------------------------------------------------------------------
gkAction *gkSkeleton::getAction(const gkHashedString &name)
{
	size_t pos;
	if ((pos = m_actions.find(name)) == GK_NPOS)
		return 0;

	return m_actions.at(pos);
}


// ----------------------------------------------------------------------------
gkBone *gkSkeleton::getBone(const gkHashedString &name)
{
	size_t pos;
	if ((pos = m_bones.find(name)) == GK_NPOS)
		return 0;
	return m_bones.at(pos);
}


// ----------------------------------------------------------------------------
gkBone::BoneList &gkSkeleton::getRootBoneList(void)
{
	if (m_rootBoneList.empty())
	{
		for (UTsize i=0; i<m_boneList.size(); ++i)
		{
			gkBone *bone = m_boneList.at(i);

			if (bone->getParent() == 0)
				m_rootBoneList.push_back(bone);
		}
	}
	return m_rootBoneList;
}


// ----------------------------------------------------------------------------
gkGameObject *gkSkeleton::clone(const gkString &name)
{
	gkSkeleton *cl= new gkSkeleton(m_scene, name);

	// TODO, call clone on all bones

	gkGameObject::cloneImpl(cl);
	return cl;

}


// ----------------------------------------------------------------------------
class gkSkeletonLoader : public Ogre::ManualResourceLoader
{
public:

	gkSkeletonLoader(gkSkeleton *skel);
	virtual ~gkSkeletonLoader() {}

	void loadResource(Ogre::Resource *resource);

private:
	void recurseBone(Ogre::Skeleton *skel, gkBone *cur, gkBone *par);

	gkSkeleton *m_skeleton;

};


// ----------------------------------------------------------------------------
void gkSkeleton::createSkeleton(void)
{
	if (m_skelLoader != 0)
		return;

	Ogre::SkeletonPtr oskel = Ogre::SkeletonManager::getSingleton().getByName(m_name);
	if (oskel.isNull())
	{

		m_skelLoader = new gkSkeletonLoader(this);
		oskel = Ogre::SkeletonManager::getSingleton().create(m_name, "<gkBuiltin>", true, m_skelLoader);
		oskel->load();
	}

}

// ----------------------------------------------------------------------------
gkSkeletonLoader::gkSkeletonLoader(gkSkeleton *skel)
	:   m_skeleton(skel)
{
}


// ----------------------------------------------------------------------------
void gkSkeletonLoader::recurseBone(Ogre::Skeleton *skel, gkBone *cur, gkBone *par)
{

	Ogre::Bone *obone = skel->createBone(cur->getName());
	cur->setOgreBone(obone);


	if (par != 0)
		par->getOgreBone()->addChild(obone);

	const gkTransformState &rest = cur->getRest();
	obone->setPosition(rest.loc);
	obone->setOrientation(rest.rot);
	obone->setScale(rest.scl);
	obone->setBindingPose();
	obone->setManuallyControlled(true);


	gkBone::BoneList &bl = cur->getChildren();
	for (UTsize i=0; i<bl.size(); ++i)
		recurseBone(skel, bl[i], cur);
}


// ----------------------------------------------------------------------------
void gkSkeletonLoader::loadResource(Ogre::Resource *resource)
{
	Ogre::Skeleton *oskel = static_cast<Ogre::Skeleton *>(resource);

	gkBone::BoneList &bl = m_skeleton->getRootBoneList();
	for (UTsize i=0; i<bl.size(); ++i)
	{
		gkBone *gbone = bl[i];
		recurseBone(oskel, gbone, 0);
	}
}