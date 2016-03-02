#AnimKit internals, status and roadmap

# Intro #
AnimKit is a free skeletal-based 3d character animation library written in C++ in a platform/graphic-API independent way.

# License #
AnimKit is available under the permissive zlib license, just like the rest of gamekit.

# Download source code #

You can check out AnimKit using a Subversion client, using
svn http://gamekit.googlecode.com/svn/branches/AnimKit

Alternatively, you can also browse the AnimKit source code online:
http://code.google.com/p/gamekit/source/browse/branches/AnimKit/

# AnimKit classes #

### akAnimationClip ###

A basic keyframed animation


### akAnimationChannel ###

Can be of type BONE/TRANSFORM/MORPH/META. It is mostly organisational (to group curves inside a clip) and give hints on how to apply the result (type and name)


### akAnimationCurve ###

A keyframed curve with linear or bezier interpolation. It animates only one float value.


### akAnimationPlayer ###

Link to a clip and recall the positon inside the clip (local clock) and the playing speed. Each object have a player for each animation clip it can play (so animation clip are shared between objects). It also contain the weight of the animation for animation blending.


### akAnimationPlayerSet ###

A set of players to facilitate handling the multitude of players an object can have.


### akSkeleton ###

Describe the hierarchy of the joints skeleton as well as its binding pose.


### akSkeletonPose ###

Quite self explanatory. Can be in different "spaces": Model, Local or Binding.

For blending it better be in a space where the parent position does not affect the child position. So do not blend in model space but only in local or binding space. For generating a matrix palette for skinning however it should be in model space.
Some methods are available to convert between spaces.


### akPose ###

Has a akSkeletonPose but stores also the result of animated float channels (and other non "Bone" channels).


### akGeometryDeformer ###

Simple class used to apply skining/morphing on a mesh. It is not dependent of the rest of AnimKit source. You can use it with whatever triangle mesh or memory organisation you want. The only thing you need is to describe your data pointer and stride value.


### akBufferInfo an akMesh ###

Those are included in AnimKit source even tough they are only needed by the demo. You can use the animation and the skinning/morphing part of animkit with your own mesh object/structure instead of akMesh.
The mesh is decomposed in submeshes each of which have arrays containing the mesh data (indices/vertices). Those arrays are more or less optimized to:
  * Interleave vertex data
  * Separate static and dynamic data
  * Take care of alignement
  * Do not waste memory (unlike the gkMesh which alocate 8 UV layers for each vertex)
To avoid the user to know the memory organisation of the mesh data, each submesh use 2 akBufferInfo, one to describe the vertex buffer and the other to describe the index buffer.

An akBufferInfo contains several "Elements". Each element have a data type (uint32, int32, 4uint8, 1float, 2float, 3float, 4float, ... ), a data usage (vertex position, vertex color, indices, uv coord, ...), a data pointer and a stride value.

Note: To quickly render using VBO it is still better to know the exact memory organisation.

## How to evaluate animation (and animation blending) ##

The most straigth forward procedure to do that is to have all the
Players in a PlayerSet with the correct weights and directly evaluate
the result of all the blended animation in a Pose.

For that you have to reset the pose to 0 then evaluate the PlayerSet. AnimKit will evaluate each Player part of the PlayerSet in an additive way:
```
pose = pose + weight * animation effect
```

Alternatively, you can evalute a separated animation clip or a subset
of the clips in a single pose and then mix/blend several poses
togheter using the API provided by the PoseBlender. Linear, additive
and substractive blending is supported.

# AnimKit Status #

  * Linear blend skinning
  * Dual quaternion skinning http://isg.cs.tcd.ie/projects/DualQuaternions/
  * Morphing (shape keys)
  * Arbitary float value animation
  * Animation Blending: By hand or flat weighted average (normalized or not)
  * LERP, additive and substractive blending.
  * SSE2 optimized
  * Data organisation optimized to avoid cache misses.
  * Partial body blending

# AnimKit Roadmap (in no special order) #

  * Retargeting
  * Mirroring
  * Quatization
  * BlendController
    1. BlendTree
    1. Animation State Machine
  * IK
  * Serialization
  * GUI

## BlendController ##

The goals of the Blend controller would be to facilitate complex animation blending and avoid the hurdle of calculating/settings weight manually and/or blending pose manually.

The idea for the blend controller is just a interface that different blend controller type can fulfill. The basic idea is to have 2 methods in the interface:
  * FlattenToPlayerSet: It sets the weight of each player in the set so that when evaluating the PlayerSet after that, the result will be the one expected. This is quick and low memory but limited in some ways.
  * EvaluateToPose: It evaluates each animation (at least those which the weights are not null) in a pose, then blends the pose together. It surely will be slower and more memory consuming than the flatten method but more robust when mixing with IK and procedural animation.

For example if the blend controller is a node tree that contains an IK node: We can flatten the tree without taking care of the branch of the IK node except calculating its weight. Than apply all the flat weighted animation to a single pose. Calculate the IK pose than blend the 2 poses together. Nothing really wrong here except if the IK node had inputs that where supposed to be used as start pose to calculate the IK. In this case evaluating the tree instead of flattening it (making pose circulating between the nodes instead of just weights) is the only way to go. The same thing happen when dealing with procedural animation node.

Example of different blend controller types:
  * A simple animation player
  * An animation player set
  * A queue/prioritizer that only plays one animation at a  time but blend when switching animation (to mimic BGE)
  * A animation blend node tree
  * A nested state machine


### BlendTree ###

A node tree where each leaf node is another blend controller (could be a simple animation player, or an ASM or another blend tree).

Links:

http://www.gamasutra.com/view/feature/3456/animation_blending_achieving_.php

http://www.ogre3d.org/forums/viewtopic.php?t=45260

### Animation State machine ###

A finite state machine where each state is another blend controller (could be a simple animation player, or another ASM or a blend tree)


### Notes ###

  * This should be sufficient to produce very complex blend. For example you can have a very simple node tree to "layer" an ASM for the hair of a character (with states like Wet/Dry) with another ASM for the skeleton pose with states like Walking/Swimming/CloseCombat each of which would be a complex blend tree.

  * Care should be taken to be multi-threading proof: A single blend controller could be evaluated simultaneously but for 2 different objects in different states.

# Demo Status #

  * Skinning
  * Morphing
  * Simple animation (positon rotation)
  * VBO
  * Shaded/Shadeless/Wireframe
  * Draw normals
  * DualQuaternion/Matrix skinning
  * UV textures (TexFace and packed raw Targa textures are loaded from the blend file)


# Limitations #

  * One vertex can only be deformed by 4 bones, if deformed by more the less deforming bone is excluded and weights are renormalized. It is generally admitted that the difference is not visible to human eye.
  * Maximum 256 bones in a skeleton.


# Future work #

  * Another demo with Idle/Walk/Run with akAnimationPlayer synchronization.
  * Integrate with Ogre and Irrlicht graphics renderers (trunk)
  * Have a basic demo for each functionality
  * Show how to load animation data from a FBX or COLLADA file
  * Integrate AnimKit with Bullet
  * Add an inverse kinematics system
  * Add OpenGL ES2 demo working on Android and iPhone/iPad, see  http://opengles20study.blogspot.com/2011/12/using-animkit-for-pose-and-skeleton.html