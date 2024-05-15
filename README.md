# BKeeper
A Grid benchmark for the Conjugate Gradient solver under multiple gauge groups and representations.

## Compiling
1) Run `bootstrap.sh`
2) Create and `cd` into a build directory as `mkdir build; cd build`
3) Run `../configure --prefix=<path/to/install/directory> --with-grid=<path/to/grid/install> CC=<grid CC> CXX=<grid CXX> group=[SU|Sp] Nc=[2|3|4|6] representation=[fundamental|adjoint|twoindexsymmetric|twoindexantisymmetric]`
4) `make && make install`

