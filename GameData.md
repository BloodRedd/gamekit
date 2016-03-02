# Graphics and Animation Data #

Most authoring tools, such as Maya, Max, Cinema4D and Blender can output triangle meshes, texture coordinates, animation data. This data is very common and can be transported using a .FBX or .DAE COLLADA file.

  * triangle meshes, vertices with position and texture-coordinates
  * texture images, pixel and vertex shaders
  * animation data, skeleton bones, skinning binding to the mesh

If we want to play games, we need some additional data for physics, sound and game logic. This is all available from the .blend file.

# Collision and Physics Data #

Blender has a built-in game engine, and all the necessary information is stored in a .blend file. As a starting point we can get all this information from a .blend file and use it in GameKit. This includes:

  * texture images (.jpg, .png, .tga pictures can be embedded/packed in a .blend file
  * collision detection information is also available for objects: it describes the collision shape/boundary representation. For some objects we might want to collide with the actual triangle mesh but for other objects we might want to use a different representation, such as a box, sphere, cylinder or convex hull.

Blender includes the Bullet physics library, and many of the settings can be configured within Blender. For example you can assign:

  * Rigid body information such as mass, friction and restitution
  * Rigid constraints such as point to point (ball-socket), hinges and a generic constraint where each of the 6 degrees of freedom and its limits can be configured separately.
  * Soft bodies can be assigned and parameters are exposed

# Game Logic Data #

The Blender game engine defines the behaviour of game objects using logic bricks. You can connect a collection of sensors, actuators and controllers to a game object:

Sensors such as:

  * keyboard sensor
  * mouse sensor
  * always sensor
  * collision sensor
  * timing sensor
  * property sensor
  * and so on

Actuators such as:

  * sound actuator
  * object actuator to create and delete objects
  * animation actuator
  * scene actuator to add or remove new scenes
  * motion actuator to apply a force, impulse
  * and many more

The sensors are linked to actuators through controllers that decide triggering logic.

  * AND controller, requires all sensors to be active to trigger the actuator
  * OR controller, requires one of the sensors to be active
  * Expression controller evaluates an expression that decides wether an actuator is triggered
  * Python controller runs a python script

# Occlusion Culling Data #

  * Apart from view frustum culling, Blender also allows to assign occluders for occlusion culling. Bullet has some acceleration structures that can perform occlusion culling based on this information.

All this information is available in the .blend file.