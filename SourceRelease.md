  * Export trunk using svn export
  * Remove NodeEditor in Tools/ and follow thees steps again, if building a source release for it.
  * Open top level CMakeLists.txt, uncomment:
  * CMAKE\_SUPPRESS\_REGENERATION
  * CMAKE\_USE\_RELATIVE\_PATHS
  * INTERNAL\_CREATE\_DISTRIBUTABLE\_MSVC\_PROJECTFILES
  * Run cmake-gui and make source and build directory the same
  * Disable all Direct3D render systems
  * Enable OGREKIT\_OIS\_WIN32\_NATIVE
  * Generate project files
  * Remove generated files ALL\_BUILD.vcproj, INSTALL.vcproj, cmake\_install.cmake, CMakeCache.txt from the top level directory
  * Open top level project and remove ALL\_BUILD and INSTALL, then save
  * Zip current directory
  * Rename current directory and test build for consistency.
