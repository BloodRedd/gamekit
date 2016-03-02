

# Introduction #


The logic brick module in OgreKit may be thought of as a series of toggles and pulses.
Each brick has either an ON or OFF toggle which will be it's current state. An ON state represents an open link where pulses are free to flow through. An OFF state represents a closed link where pulses are blocked. Bricks may be grouped into a finite number of states. Where each group represents a context in which they may execute. These groups may be mixed, allowing two or more contexts to execute at the same time.


A brick is classified as a sensor, controller or actuator. Each class may be sub classed to perform various different activities.



---

# Sensor #


The job of a sensor is to process it's assigned event type then choose to open or close a link. The sensor's event value becomes the pulse between a sensor and a controller.
If the given event has taken place, the pulse value will be positive, otherwise the pulse will be negative. Actuators do not care about the actual pulse, it's concern is whether or not it has an open or closed link. The ultimate goal is to find a path to an actuator and constantly update it.


## Sensor Header ##

Each sensor has an attached header which determines how a link may be opened or closed.
This header also has an inverse function to invert the positive or negative pulse.
By default a sensor will want to close it's link after any evaluation. It is up to the header to determine whether or not this happens.



### IDLE Mode ###

IDLE Mode opens links in a toggle mode.
First it will open a link allowing one pulse to flow through, close the link, then wait for the event to change.
When the event changes it will reopen the link allowing another pulse to flow through, then close.




### ON Mode ###


ON Mode opens links and keeps them open until an event change happens.
This allows a constant positive pulse to flow through the link each game tick.
When the event changes it will allow a single negative pulse through, then close the link.



### OFF Mode ###

OFF Mode is identical to ON Mode, except that everything is inverted.
Where as ON Mode allows positive pulses each game tick, OFF mode only allows negative pulses.



### Frequency ###

Frequency determines the rate of update between calls to the header evaluation.
A frequency of zero will mean always evaluate. Each value above zero is the number of game ticks to wait between evaluation calls.




### Level ###

Level allows a sensor to reset itself to its original state each time its owing group is activated.


### Tap ###

Tap will open and close a link in the span of two game ticks.
It will wait for the original start condition before starting over.
Until this start condition is met, it will block any updates.



### Invert ###
Invert, inverts positive or negative pulses sent between open links.



---

# Controller #

The job of a controller is to take sum of incoming pulses, then choose whether it should open or close a link to connected actuators.
It chooses based on a fixed set of logical operations how it should handle pulses.
If the sum of its operation is 1, links to actuators are opened.
In contrast, If the sum of its operation is 0, links to actuators are closed.



---

# Actuator #


The job of an actuator is to sit and wait for an open link.
Once a link has been opened, it will constantly update each game tick.
When the link is closed, It will remove itself from constant updates and wait for another link to be opened.



---

# Notes #

## Sensor Dispatchers ##

Sensors are grouped into a set of dispatchers holding the same type of sensor.
The purpose of a dispatcher is to efficiently test for, and sort events.
Currently all events are tested per sensor which is highly inefficient. What needs to be done is to sort and group identical sensors, and do the event test on the dispatcher level. Then for each identical sensor, pass the results of that event to it.


## Disclaimer ##

This module is based on the logic brick module found in the Blender game engine.
It has been written based on careful observations to the execution behavior of blender bricks. Therefore it is not a complete copy. It's more based on the above derived theory than anything else. However, much attention has been made to make the two compatible.


---

# Current Blender Compatibility Status #

All logic bricks not marked by N/A will be extracted from the current blend file. Bricks are automatically setup and linked durring load. If a brick marked by N/A is found, it will be skipped and all links in or out will not be evaluated.

## Sensors ##

| **Name** | **Gamekit Class** | **Remarks** |
|:---------|:------------------|:------------|
| Always   | gkAlwaysSensor    |             |
| Delay    | gkDelaySensor     |             |
| Keyboard | gkKeyboardSensor  |             |
| Mouse    | gkMouseSensor     |             |
| Touch    | gkCollisionSensor |             |
| Collision | gkCollisionSensor |             |
| Near     | gkNearSensor      |             |
| Radar    | gkRadarSensor     |             |
| Property | gkPropertySensor  |             |
| Random   | gkRandomSensor    |             |
| Ray      | gkRaySensor       |             |
| Message  | gkMessageSensor   |             |
| Joystick | gkJoystickSensor  | No support for joystick's hat yet. |
| Actuator | gkActuatorSensor  |             |

## Controllers ##

| **Name** | **Gamekit Class** | **Remarks** |
|:---------|:------------------|:------------|
| And      | gkLogicOpController |             |
| Or       | gkLogicOpController |             |
| Xor      | gkLogicOpController |             |
| Nand     | gkLogicOpController |             |
| Nor      | gkLogicOpController |             |
| Xnor     | gkLogicOpController |             |
| Expression | gkExpressionController | Expression parser in Blender have compatible license with Gamekit  |
| Python   | gkScriptController |             |

## Actuators ##

| **Name** | **Gamekit Class** | **Remarks** |
|:---------|:------------------|:------------|
| Motion   | gkMotionActuator  | No servo mode. |
| Shape Action | _N/A_             |             |
| Action   | gkActionactuator  |             |
| Constraint | _N/A_             |             |
| IPO      | _N/A_             |             |
| Camera   | _N/A_             |             |
| Sound    | gkSoundActuator   |             |
| Property | gkPropertyActuator | Does not support expressions. |
| Edit Object | gkEditObjectActuator |             |
| Scene    | gkSceneActuator   | No Supend/Resume |
| Random   | gkRandomActuator  |             |
| Message  | gkMessageActuator |             |
| Game     | gkGameActuator    | No Start New nor Save/Load. |
| Visibility | gkVisibilityActuator |             |
| 2D Filter | _N/A_             |             |
| Parent   | gkParentActuator  | No Compound/ghost. |
| State    | gkStateActuator   |             |


---

# Related Links #

http://blenderartists.org/forum/showthread.php?t=207640

http://gameblender.wikia.com/wiki/Sensors

http://wiki.blender.org/index.php/Doc:2.4/Books/GameKit_2/13.Reference