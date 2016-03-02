#Overview of the animation system.

# Introduction #

![http://www.pasteall.org/pic/show.php?id=6770&nonsense=something_that_ends_with.png](http://www.pasteall.org/pic/show.php?id=6770&nonsense=something_that_ends_with.png)


# Playing animations #

## Basic ##
  * gkActionManager (singleton) contains all actions of all objects.
  * gkGameObject contain a ActionBlender that can prioritize animations and blend after a transition.
  * you must first call gkGameObject::addAction("action\_name");
  * then gkGameObject::playAction("action\_name", blend, mode, priority);

## Advanced ##
  * you can get the action player corresponding to a specific action with gkGameObject::getActionPlayer("action\_name");
  * and jumping across the action with gkActionPlayer::setTimePosition(time);
  * you can can also check if an gkActionPlayer isDone() or change its mode (loop,reverse).

# Creating animations #
  * To create an animation (not linked to any object), call gkActionManager::getSingleton().createKeyedAction("action\_name"); or gkActionManager::getSingleton().creatActionSequence("action\_name");

## keyedAction ##
  * Contains a bunch of channels each containing a bunch of keyframed curves.

## ActionSequence ##
  * Contains a bunch of ActionStrip with custom end start time for non linear action.
  * Action Strip can correspond to any type of action (keyframed or other sequences)

```
// COMBO: Kick + Run + Whip
m_comboAttack = gkActionManager::getSingleton().createActionSequence("Momo_ComboAttack");
m_comboAttack->addItem("Momo_Kick",      gkVector2(0.f,  17.f), gkVector2(0.f,  3.f));
m_comboAttack->addItem("Momo_Run",       gkVector2(15.f, 32.f), gkVector2(2.f,  4.f));
m_comboAttack->addItem("Momo_TailWhip",      gkVector2(25.f, 45.f), gkVector2(7.f,  0.f));
m_animations[GK_ANIM_COMBO_ATTACK] = m_skeleton->addAction(m_comboAttack);
m_animations[GK_ANIM_COMBO_ATTACK]->setMode(GK_ACT_END); //not LOOP
```


# Notes #
  * NLA action are not converted to gkActionSequence yet.
  * Only Bone and Object (loc/rot/scale) for now.