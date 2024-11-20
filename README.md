# BKeeper
A [Grid](https://github.com/paboyle/Grid) benchmark for the Conjugate Gradient solver under multiple gauge groups and representations.

## Compiling
1) Run `bootstrap.sh`
2) Create and `cd` into a build directory as `mkdir build; cd build`
3) Run `../configure --prefix=<path/to/install/directory> --with-grid=<path/to/grid/install> CC=<grid CC> CXX=<grid CXX> \[options\]`
4) `make && make install`

The `options` parameters stands in place for the options used to enable or disable compilation for individual gauge groups. These options are:
```
--enable-all     [Enables compilation for all benchmarks not explicitly specified]
--enable-su2fund [Explicitly enables compilation for SU(2) fundamental]
--enable-su2adj  [Explicitly enables compilation for SU(2) adjoint]
--enable-su2tis  [Explicitly enables compilation for SU(2) two-index symmetric]
--enable-su2tias [Explicitly enables compilation for SU(2) two-index antisymmetric]
--enable-su3fund [Explicitly enables compilation for SU(3) fundamental]
--enable-su3adj  [Explicitly enables compilation for SU(3) adjoint]
--enable-su3tis  [Explicitly enables compilation for SU(3) two-index symmetric]
--enable-su3tias [Explicitly enables compilation for SU(3) two-index antisymmetric]
--enable-su4fund [Explicitly enables compilation for SU(4) fundamental]
--enable-su4adj  [Explicitly enables compilation for SU(4) adjoint]
--enable-su4tis  [Explicitly enables compilation for SU(4) two-index symmetric]
--enable-su4tias [Explicitly enables compilation for SU(4) two-index antisymmetric]
--enable-sp4fund [Explicitly enables compilation for Sp(4) fundamental]
--enable-sp4tis  [Explicitly enables compilation for Sp(4) two-index symmetric]
--enable-sp4tias [Explicitly enables compilation for Sp(4) two-index antisymmetric]
```
The 'disable' versions of the above do the opposite. All benchmarks are enabled by default, unless all are disabled by passing `--disable-all`, or by disabling individual benchmarks. The setting for individual benchmarks therefore takes priority over the global default.
Here are a few example options:
- `--disable-all --enable-su2adj`: Only compile support for SU(2) adjoint.
- `--disable-su2adj` Compile all benchmarks except SU(2) adjoint.
- ` `: No options: compile all benchmarks.
- `--enable-su2adj`: Compile all benchmarks. `--enable-su2adj` is redundant.
- `--disable-all --disable-su2adj`: Disable all benchmarks. `--disable-su2adj` is redundant.

## Running
To run the benchmark, execute
`/path/to/BKeeper /path/to/params/file [grid options]`
In the argument list, 'path/to/params/file' is a path to a BKeeper parameter file. This is an XML file with the following structure:
```
<?xml version="1.0"?>
<grid>
  <benchmarks>
    <elem>benchmark ID 1</elem>
    <elem>benchmark ID 2</elem>
    ...
  </benchmarks>
  <iterations>...</iterations>
  <mass...</mass>
</grid>
```
where
- `benchmark ID X` should be replaced with a benchmark ID that BKeeper was compiled for. 
- `iterations` is the number of iterations to run the CG solver for.
- `mass` is the mass of the fermion propagator being solved for in lattice units.

For example, a parameter file that runs the SU(2) adjoint benchmark and SU(3) fundamental benchmark for 50 iterations for m=0.1 would be:
```
<?xml version="1.0"?>
<grid>
  <benchmarks>
    <elem>su2adj</elem>
    <elem>su3fund</elem>
  </benchmarks>
  <iterations>50</iterations>
  <mass>0.1</mass>
</grid> 
```

There are three errors that may occur:
- If no recognised benchmarks are included in the parameters file, the program will gracefully exit without spinning up Grid.
- If the desired gauge group was not included when compiling the program, you will receive an error message stating this, which is resolved by re-compiling with support for that gauge group included in the `configure` step.
- If you pass an combination for which BKeeper does not define a benchmark, you will instead receive a message informing you of this. If [Grid](https://github.com/paboyle/Grid) in principle supports the group you want to run, make a pull request adding support to BKeeper, following the existing implementation as a reference. If Grid does not support the gauge group you want to run, you will first need to have this functionality merged into Grid, and then support can be added to BKeeper.

## To-do
- Address some bugs in the performance metrics (FlOps reports total FLOp count, not FLOp/s; communications metric does not scale with the decomposition)
- Make the benchmark spack-compatible
