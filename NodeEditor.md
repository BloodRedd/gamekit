# Introduction #
The node editor is an experimental front end for nodal logic within GameKit. It uses wxWidgets as the platform independent graphical user interface and OpenGL for the node canvas.

The ultimate goal of this editor is to turn C++ only nodes into an easy to use asset that may be used by anyone.


## Initial Requirements ##
  * Translate C++ types to an add menu for editing.
  * Copy, Paste and, Delete nodes including links.
  * Support Undo, Redo options.
  * Form groups of nodes, as well as groups of groups.
  * Output node trees into a human readable / editable file format (.ntree).
  * .ntree should have the ability to be created by hand in Blender's text editor.
  * .ntree should have the ability to be exported from the editor and placed Blender's text editor.
  * GameKit should parse text files ending with .ntree and build node trees for use in games.


## Current Status ##
  * Can translate C++ types to an add menu for editing.
  * Can Copy, Paste and, Delete nodes including links.
  * Can Copy, Paste between trees.
  * Cannot Undo, Redo.
  * Cannot form groups of nodes, or groups of groups.
  * Cannot output node trees into easily readable file format (XML currently).
  * GameKit cannot parse text files ending with .ntree yet.
  * The wxWidgets CMake build system currently only supports Win32 and Linux GTK2 building.
  * All node support in GameKit must be accomplished through the C++ interface.


## Possible Additions ##
  * Use a custom bParse file format for load/save functionality (.blend, .bullet, .ntree)
  * Use export functionality to export node trees to human readable text format.


### Example Export ###
```
NodeTree MouseLook {

	Node m_mouseMotion {

		type = NT_MOUSE_MOTION;

		Inputs {

			Socket Scale_X { value = -0.25;  }
			Socket Scale_Y { value = -0.25;  }
		}
	}

	Node m_xRotMotion  {

		object = "xRot";
		type   = NT_OBJECT_MOTION;

		Inputs {

			Socket Update { value = m_mouseMotion.Motion;  }
			Socket X      { value = m_mouseMotion.Rel_Y;   }
		}
	}

	Node m_zRotMotion  {

		object = "zRot";
		type   = NT_OBJECT_MOTION;

		Inputs {

			Socket Update { value = m_mouseMotion.Motion;  }
			Socket Z      { value = m_mouseMotion.Rel_X;   }
		}
	}
}
```