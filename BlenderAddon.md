# Introduction #

Blender 2.5 has an add-on mechanism, that allows this gamekit to be started directly from within Blender.

Further explanation is in the Blender wiki here: http://wiki.blender.org/index.php/Extensions:2.5/Py/Scripts/Game_Engine/Gamekit_Engine


# Quickstart Guide #

  * Download Blender and the gamekit addon. We provide a Windows zipfile that contains both in the [Downloads section](http://code.google.com/p/gamekit/downloads/list)
  * Enable the gamekit using the 'preferences / add-on' tab
  * Open a .blend file. Above zipfile includes a working sample blend in the OgreKit subdirectory
  * Search and scroll down to a gamekit panel and press the START key. Note that 'P' key still runs the internal BGE engine.

# Re-assign the P key #

By default the P key starts the internal BGE game engine. If you want to start the gamekit you have to press the 'Start' button in the appropriate panel (screenshot).

Here is how you can re-assign the P key:

  * After enabling the Gamekit addon, go to "User Preferences->Input"
  * Go to "3DView->ObjectMode" and click the "Edit" button
  * Uncheck the "Start Game Engine" keymap entry.
  * At the end of the list of the keymaps entry for "Object Mode", click the "Add New" button.
  * In the new keymap entry, set the operator to "scene.gamekit\_start\_game" and the key to "P"

# Compatibility #

  * See this wiki page for [logic brick compatibility](http://code.google.com/p/gamekit/wiki/LogicBrickDesign)
  * Make sure that your textures are compatibile, see this [Texture wiki page](http://code.google.com/p/gamekit/wiki/Blender_Textures)
  * When using OgreKit compiled with RTSS, it may be necessary to change the shadow mode from _additive_ to _modulative_. This is necessary for such pre-lit environments as seen in the momo\_ogre.blend example file.

# Further reading #

  * See also the [gamekit quickstart guide](http://code.google.com/p/gamekit/wiki/QuickstartGuide) and check out this [forum topic on Blender Artists](http://blenderartists.org/forum/showthread.php?t=155310)