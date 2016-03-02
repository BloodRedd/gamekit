OgreKit supports two types of GameLogic systems.


## Logic bricks. ##

Logic bricks are a boolean based system, of sensors, controllers and actuators. Links between bricks send pulse values of true or false.


## Node Logic. ##

Node logic is a value based system, where each node contains inputs, and optional outputs. Links between nodes pass predefined values.
Some example IO values would be, bool, int, float, float3, strings, and objects.



### How nodes differ from bricks. ###
Both Nodes and Bricks are meant to be used like pseudo code.


An example node statement might be something like this fragment:
```
if (space key and left mouse button is down)
    rotate object around z by mouse coordinate x
else
    translate object in x by mouse coordinate y
```

The same fragment in bricks would result to:
```
if (space key and left mouse button is down)
    rotate object around z by a fixed value
else
    translate object in x by a fixed value
```


Node based logic offers up a finer degree of control to game logic.
More complex actions can be achieved without writing every thing inside a script environment.