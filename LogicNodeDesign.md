


# Introduction #

Logic nodes are made up of input sockets, a node, and output sockets.
Each node receives data through it's inputs, does predefined operations, then passes any processed data to it's outputs.
Node trees may be as simple as a single node operating on it's default input values, or a complex graph in order to achieve program like operations.




---

## Sockets ##

Sockets form the link between nodes. They open a channel where a predefined data type may pass between nodes.
In OgreKit sockets are in template form, meaning any C/C++ data type can be passed between connected sockets.

For example, some common types that may be used are:
  * bool
  * int
  * float
  * Vector3
  * Quaternion,
  * Matrix4
  * GameObject
  * GameObject Property

OgreKit limits connecting sockets to the same data type at each start and end point.

For example:
  * float connects to float
  * GameObject connects to GameObject




---

## Nodes ##

A node uses it's input values as parameters to it's function. Then returns the result to its outputs.


Nodes should consist of low level operations:

  * Converting from a Quaternion to an Euler.
  * Extracting individual components to math structures (vector3.x).
  * Joining individual components to math structures (x,y,z to vector3).
  * Extracting position/rotation/velocity from a game object.
  * Extracting game object properties.


Nodes should also consist of higher level operations:
  * Camera tracking
  * State machine access
  * Rotating, translating, applying linear/angular velocity.
  * Tree grouping
  * Ray casting
  * Collision detection
  * Create and destroy objects
  * Sound playback
  * Skeletal animation




---

# Current Status #

Logic trees are only supported in C++ created applications.

## Planed Support ##

The NodeEditor will be used to create nodal logic assets.

The C++ API is planed be bound to Lua and accessible scripts.


## Current nodes ##

| **Name**  | **Gamekit Class** |
|:----------|:------------------|
| KeyNode   | gkButtonNode      |
| MouseButtonNode | gkButtonNode      |
| CameraNode | gkCameraNode      |
| CharacterNode | gkCharacterNode   |
| CollisionNode | gkCollisionNode   |
| CursorNode | gkCursorNode      |
| ExitNode  | gkExitNode        |
| FunctionNode | gkFunctionNode    |
| GrabNode  | gkGrabNode        |
| GroupNode | gkGroupNode       |
| IfNode    | gkIfNode          |
| MathNode  | gkMathNode        |
| MotionNode | gkMotionNode      |
| MouseMotionNode | gkMouseNode       |
| MultiplexerNode | gkMultiplexerNode |
| ObjectNode | gkObjectNode      |
| ParticleNode | gkParticleNode    |
| PickNode  | gkPrintNode       |
| PulseNode | gkPulseNode       |
| RandomNode | gkRandomNode      |
| RayTestNode | gkRayTestNode     |
| ScreenRayTestNode | gkScreenRayTestNode |
| ShowPhysicsNode | gkShowPhysicsNode |
| StateMachineNode | gkStateMachineNode |
| TimerNode | gkTimerNode       |
| ValueNode | gkValueNode       |
| VariableNode | gkVariableNode    |
| QuaternionToEulerNode | gkQuaternionToEulerNode |
| EulerToQuaternionNode | gkEulerToQuaternionNode |
| VectorComposeNode | gkVectorComposeNode |
| VectorDecomposeNode | gkVectorDecomposeNode |
