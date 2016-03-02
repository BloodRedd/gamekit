# Introduction #
Lua may be executed in a number of different ways.
If you are using the application AppLuaRuntime then full setup and support is in the works.
If you are using an embedded script in Blenders text editor, then support is limited to running or modifying
the current blend file.

Some terms used in this document,
  * Standalone, meaning the application AppLuaRuntime
  * Embedded, meaning the application AppOgreKit, with an OnInit.lua text file inside.


#### Notes ####
The most up to date API documentation may be download here ([HTML](http://gamekit.googlecode.com/svn/trunk/Docs/LuaAPI/local/OgreKitLua.zip) | [CHM](http://gamekit.googlecode.com/svn/trunk/Docs/LuaAPI/local/OgreKitLuaHTMLHelp.zip))




---


## Hello World Embedded ##

In an embedded application, the entry point is in a predefined script named OnInit.lua.
What this script does is execute every time the scene is initialized. Allowing a one time setup to connect event listeners, create logic bricks, etc. The following example shows how to use this setup to connect to the main loop and print a debug message on screen.

### OnInit.lua ###
```
Demo = BaseClass(OgreKit.Engine)


function Demo:constructor()

end


function Demo:OnUpdate(delta)

  OgreKit.DebugPrint("Hello World")

end

demo = Demo()
demo:connect(OgreKit.EVT_TICK, demo, Demo.OnUpdate)
```

Execute with the following command line: AppOgreKit yourFileWithOnInit.blend





---


## Hello World Standalone ##

Creating a standalone application requires setting up the OgreKit.Engine class from scratch. You are responsible for setting window parameters, user defined variables, loading a blend file, and adding exit hooks.


### HelloWorld.lua ###

```
HelloWorldApp = BaseClass(OgreKit.Engine)

function HelloWorldApp:constructor()


    self.prefs              = self:getUserDefs()
    self.prefs.winTitle     = "Hello World Demo"
    self.prefs.verbose      = false
    self.prefs.grabInput    = false
    self.prefs.blenderMat   = true
    self.prefs.debugFps     = true
    self.prefs.winx         = 800
    self.prefs.winy         = 600
    self.keyboard           = OgreKit.Keyboard()


    -- Call internal engine setup.
    self:initialize()


    self.scene = self:loadBlendFile("HelloWorld.blend")


    -- Initaialize the scene.
    self.scene:createInstance()

end


function HelloWorldApp:OnUpdate(delta)

    OgreKit.DebugPrint("Hello World")

    if self.keyboard:isKeyDown(OgreKit.KC_ESCKEY) then
        self:requestExit()
    end

end



-- Create the application.
local app = HelloWorldApp()

-- Connect Events.
app:connect(OgreKit.EVT_TICK, app, HelloWorldApp.OnUpdate)

-- Start the main loop.
app:run()

```

Execute with the following command line: AppLuaRuntime HelloWorld.lua