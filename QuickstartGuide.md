# Introduction #

Gamekit is a cross-platform 3D game engine using Ogre and Bullet for Windows, Linux, Mac and iPhone. It has tight integration with Blender by reading and extracting any data from .blend files. Future support to read .FBX and .bullet files is planned.
We use the name OgreKit for the implementation that uses Ogre for graphics, this is the default. There is also a graphics binding with Irrlicht, called IrrKit. This work is currently suspended, but you can download working source code in the SVN branches/IrrKit.

# Getting Started #

Testing the OgreKit demo

  * Download a binary OgreKit from the Downloads section or build OgreKit yourself.
  * Run the executable and pay around

# Programming your own game #

> There are several ways to develop game logic for gamekit:

  * Directly using C++ together with Node logic trees. See [LogicNodeDesign](LogicNodeDesign.md) or the OgreKit/Runtime and AppVehicleDemo examples
  * Using Lua, see the [LuaBindings](LuaBindings.md) page
  * Using a Logic Bricks system that is mostly compatible with Blender logic bricks, see [LogicBrickDesign](LogicBrickDesign.md)

# Blender integration #

  * There is an integration for Blender 2.5 using the add-on mechanism. Check out the [details here](BlenderAddon.md).

# License #

Gamekit and OgreKit exclusively uses very permissive software licenses, either BSD, ZLib or MIT. Those licenses are great for development of commercial applications or when used with proprietary technology and platforms.