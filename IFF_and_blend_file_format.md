#.blend and IFF file format internals

# Introduction #

.blend is a chunk based file format, loosely based on EA-IFF. It adds support for 32/64bit and little/big endian architectures. Also it includes a full descriptions of all structures, so it can be backwards and forwards compatible.

We are experimenting with 2 different parsers for the .blend format: readblend and bParse. The plan is to either go for bParse or write a small new exporter/importer for .blend and IFF files in general based on what we learned from readblend and bParse.

# readblend #

Readblend was written around 2003 by Adam Moss.

  * supports 32bit, little endian .blend files
  * backwards and forwards compatible with .blend versions
  * has built-in support to extract meshes, materials and objects
  * difficult to maintain/change code base

# bParse #

bParse can extract the structures (DNA) and structs. The original version was written by Charlie C for the now defunct echo-plugin.

  * supports 32/64bit and little/big endian files
  * autogenerates headerfiles from the .blend DNA structures for fast access (no conversion)
  * written in C++, it can be extended to support arbitrary "IFF" files not just .blend
  * backwards and forwards compatible with .blend versions
  * can extract data in-place.
  * seems a bit slower than readblend, needs some optimization work
  * uses STL library, this dependency will be removed

# further information #

  * the .blend format has been documented here:
http://www.atmind.nl/blender/mystery_ot_blend.html
  * the EA IFF 85 format is documented here:
http://www.martinreddy.net/gfx/2d/IFF.txt