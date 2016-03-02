Building gamekit is supported on Windows, Linux, Mac OSX and iPhone using CMake. Alternatively, you can download a source package that contains ready-to-go Visual Studio project files.

# Building using the visual studio solution #

The source package `OgreKit-*.zip` in the Downloads section is self-contained and it includes Microsoft Visual Studio project files that work out-of-the-box. This version uses OpenGL to avoid a dependency to the DirectX SDK. Just open OGREKIT.sln, select 'Release' build and hit F5.

The visual studio project files have been generated with relative paths using cmake, as described in the [SourceRelease](SourceRelease.md)


# Building using cmake #

  * Download cmake 2.6 or later from http://cmake.org

## Windows ##

  * cmake-gui

Then select the source directory, binary directory and hit the 'Configure' button. Choose your build system, such as Visual Studio 2008. A red block of options will appear. You can customize the build or hit 'Configure' again and then 'Generate'. From there you can open the OGREKIT.sln project solution.

Alternatively:

  * cmake . -G "Visual Studio 9 2008"

Then open the project solution using Visual Studio. CMake can generate project/solution for other version of Visual Studio but 2008 is more tested. You need to have Visual Studio installed before using CMake. Free version (Express) are available free of charge.

## Mac OSX ##

  * cmake-gui

Then select the source directory, binary directory and hit the 'Configure' button. Choose your build system, such as Xcode or Unix Makefile. A red block of options will appear. You can customize the build

  * Turn on OGREKIT\_BUILD\_GLRS
  * Turn off OGREKIT\_BUILD\_GLESRS

Then hit 'Configure' again and then 'Generate'. Navigate with Xcode to your build folder and load the xcode-project. (Or if using Unix Makefile just change to the build-directory and type 'make')

Alternatively

  * cmake . -G Xcode
  * cmake . -G Xcode (you have to call the same command a 2nd time)

Then open the generated Xcode project using Xcode


## iOS(iPhone/iPad/iPod Touch) ##

  * cmake . -G Xcode
  * cmake . -G Xcode -DOGREKIT\_BUILD\_IPHONE=1
> > (yes, it is right to call cmake a 2nd time)

NOTE: You should use the CMake 2.8.3 or higher version for the iOS build with CMake command line tool.

Then open the generated Xcode project using Xcode

Alternatively you can use cmake-gui, similar to the Windows version.

  * Turn on OGREKIT\_BUILD\_IPHONE
  * Turn on OGREKIT\_BUILD\_GLESRS
  * Turn off OGREKIT\_BUILD\_GLRS

NOTE: You should use the CMake 2.8.2 or higher version for the iOS build.

Good iOS build tutorial by kruzer - [blenderartists.org](http://blenderartists.org/forum/showpost.php?p=1701697&postcount=371)

Notice: At the moment ( 28/03/2012 ) you have to hard-code the resolution.
( Gamekit/Samples/IPhoneDemo/Main.mm

## Unix/Linux ##

  * cmake . -G "Unix Makefiles"

Then run

  * make

You can also generate an IDE project.
  * `cmake . -G "CodeBlocks - Unix Makefiles"`

## Android ##

  * Set environment-variable ANDROID\_NDK to the root of your NDK-Directory

  * Windows (Use the visual studio command line)
    1. set ANDROID\_NDK=D:\gamekit\android-ndk-r8c
    1. configure-android.bat c:\where\_to\_where\_to\_build\_gamekit
    1. cd c:\where\_to\_where\_to\_build\_gamekit
    1. nmake
> > > (Use jom instead of nmake for multicore build - http://http://qt-project.org/wiki/jom)

  * Linux/Mac:
    1. export ANDROID\_NDK=/home/dertom/libs/android-ndk-r8c
    1. ./configure-android /where\_to\_where\_to\_build\_gamekit
    1. cd /where\_to\_where\_to\_build\_gamekit
    1. make -j4

  * Get Requirements:
    1. Install JDK, not JRE.
> > > http://www.oracle.com/technetwork/java/javase
    1. Install Android NDK (Recommand version is **r8c**)
> > > https://developer.android.com/tools/sdk/ndk/index.html
    1. Install Eclipse ide & Android sdk plugins bundle(ADT).
> > > http://developer.android.com/sdk/index.html
    1. Update Android sdk in Eclipse. (Menu Windows/Android SDK Manager)
> > > Android SDK Tools
> > > Android SDK Platform-tools
> > > Android SDK Build-tools
> > > Android 2.3.3 (API 10) SDK Platform

  * Run Eclipse & Create a Android project & Build.
    1. Select 'Menu File/Import/General/Exisiting Project'
> > > `Next> Root-Location <build-dir>/AndroidDemo`
    1. Optional: Replace blend-file ( assets/momo\_ogre\_i.blend )
    1. Right-Click on your Android-Project > Run-as > Android Application
    1. Optional: Open Logcat-View to see log-information from the phone
> > > Window>Show View>Other...>Android>LogCat


> For more info: [Have a look here in the Forum](http://gamekit.org/forum/viewtopic.php?f=9&t=29)

> If something went wrong, please ask with some additional information in the [forum](http://www.gamekit.org) including a logcat-output.

## See also ##

There is also a readme.txt in the root of GameKit with some help.