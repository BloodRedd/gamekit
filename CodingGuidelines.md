#Some rules to follow for committers and contributers.

# Introduction #

Based on the coding Style guide of Bullet by Erwin Coumans and John McCutchan.

# General #

Those rules must never be violated:

  * Only contribute code under the ZLib license (or MIT, BSD), and **never** (L)GPL
  * CMake build system should work out-of-the-box, without requiring external dependencies
  * Cross-platform build for Windows, Linux and Mac OSX, 32 and 64 bit

# Coding Style #

  * Do not use BOOST, STL or exception handling
  * Use tabs and not spaces.
  * `CamelCase` instead of `under_scores`
  * Class names start with `gk` like `gkSomeClass`
  * Methods start with lower case like `gkSomeClass::someMethods`
  * One class per header file, smaller structures can be combined in a single file.
  * Member variables start with m_and go first at the top of the class declaration.
  * No use of global variables and namespaces.
  * Don't include `#include <stdio.h>` or similar include files
  * Try to use `const` when possible
  * Make sure to comment out `printf`, used while debugging
  * Avoid circular dependencies of classes.
  * Use forward declaration whenever possible instead of including other header files
  * The Zlib license header goes at the top of each source file
  * Pass by const reference where applicable.
  * The pointer and reference symbols are attached to the type, not to the variable: `const gkType& pointer`._

# Example Header File #
```
/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 Xavier T.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#ifndef _gkCodingStyle_h_
#define _gkCodingStyle_h_

class gkVariable;

class gkCodingStyle
{
private:

    int      m_somePrivateMember;
    gkString m_someString;

public:

    gkCodingStyle();
    virtual ~gkCodingStyle();

    ///doxygen comment starts with 3 slashes and should provide useful info
    ///not just copying the method name
    ///someFunction will compute the updated position of this object
    void someFunction(void);

    void someFunction(const gkVariable& value);

    const int getMember() const { return m_somePrivateMember; }

};

#endif // _gkCodingStyle_h_

```

# Example Source File #
```
/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 Xavier T.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#include "gkCodingStyle.h"
#include "gkVariable.h"

gkCodingStyle::gkCodingStyle()
:    m_somePrivateMember(0)

{
}

gkCodingStyle::~gkCodingStyle()
{
}

void gkCodingStyle::someFunction(void)
{
    int i;
    for (i=0;i<m_somePrivateMember;i++)
    {
        m_someString += "MoreText";
    }
}

void gkCodingStyle::someFunction(const gkVariable& value)
{
    m_someString += value;
}

```