AC_PREREQ([2.63])
AC_INIT(BKeeper,[v0.1-dev],[ryan.hill@ed.ac.uk],[bkeeper])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_MACRO_DIR([.buildutils/m4])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AM_EXTRA_RECURSIVE_TARGETS([tests benchmarks])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])


AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB
AM_PROG_AR
AC_LANG([C++])

########### Group #############
AC_ARG_VAR([group],
    [Sets the gauge group.])

if test "${group}" == "SU"; then
    AC_DEFINE_UNQUOTED([BKEEPER_GAUGEGROUP], [Grid::GroupName::SU], [Gauge group])
elif test "${group}" == "Sp"; then
    AC_DEFINE_UNQUOTED([BKEEPER_GAUGEGROUP], [Grid::GroupName::Sp], [Gauge group])
elif test "x${group}" == "x"; then
    AC_MSG_ERROR([No value for 'group' configure option provided. Use one of [SU|Sp].])
else
    AC_MSG_ERROR([Invalid value for 'group' configure option provided. Use one of [SU|Sp].])
fi

########### N Colours #############
AC_ARG_VAR([Nc],
    [Sets the size of the gauge group.])

if test "x${Nc}" != "x"; then
    AC_DEFINE_UNQUOTED([BKEEPER_NC], [$Nc], [Number of colours])
else
    AC_MSG_ERROR([No value for 'Nc' configure option provided. Provide the number of colours in the gauge group.])
fi

########### Representation #############
AC_ARG_VAR([representation],
    [Sets the number of basis vectors.])

if test "${representation}" == "fundamental"; then
    AC_DEFINE_UNQUOTED([BKEEPER_REPRESENTATION], [RepresentationName::Fundamental], [Gauge Group Representation])
elif test "${representation}" == "adjoint"; then
    AC_DEFINE_UNQUOTED([BKEEPER_REPRESENTATION], [RepresentationName::Adjoint], [Gauge Group Representation])
elif test "${representation}" == "twoindexsymmetric"; then
    AC_DEFINE_UNQUOTED([BKEEPER_REPRESENTATION], [RepresentationName::TwoIndexSymmetric], [Gauge Group Representation])
elif test "${representation}" == "twoindexantisymmetric"; then
    AC_DEFINE_UNQUOTED([BKEEPER_REPRESENTATION], [RepresentationName::TwoIndexAntiSymmetric], [Gauge Group Representation])
elif test "x${representation}" == "x"; then
    AC_MSG_ERROR([No value for 'representation' configure option provided. Use one of [fundamental|adjoint|twoindexsymmetric|twoindexantisymmetric].])
else
    AC_MSG_ERROR([Invalid value for 'representation' configure option provided. Use one of [fundamental|adjoint|twoindexsymmetric|twoindexantisymmetric].])
fi


AC_ARG_WITH([grid],
    [AS_HELP_STRING([--with-grid=<prefix>],
    [try this for a non-standard install prefix of Grid])],
    [PATH="$with_grid/bin$PATH_SEPARATOR$PATH"]
    [CXXFLAGS="$CXXFLAGS -I$with_grid/include"]
    [LDFLAGS="$LDFLAGS -L$with_grid/lib"])

AC_CHECK_PROG([GRIDCONF],[grid-config],[yes])
if test x"$GRIDCONF" != x"yes" ; then
    AC_MSG_ERROR([grid-config not found])
fi
if test x"$CXX" == x ; then
    CXX="`grid-config --cxx`"
elif test "$CXX" != "`grid-config --cxx`" ; then
    GRID_CXX="`grid-config --cxx`"
    AC_MSG_WARN([CXX differs from that reported by grid-config: "$CXX" vs "$GRID_CXX"])
fi
if test x"$CXXLD" == x ; then
    CXXLD="`grid-config --cxxld`"
elif test "$CXXLD" != "`grid-config --cxxld`" ; then
    GRID_CXXLD="`grid-config --cxxld`"
    AC_MSG_WARN([CXXLD differs from that reported by grid-config: "$CXXLD" vs "$GRID_CXXLD"])
fi
CXXFLAGS="$CXXFLAGS `grid-config --cxxflags`"
CXXFLAGS="$AM_CXXFLAGS $CXXFLAGS"

LDFLAGS="$LDFLAGS `grid-config --ldflags`"
LDFLAGS="$AM_LDFLAGS $LDFLAGS"
LIBS=" -ldl -lGrid $LIBS `grid-config --libs`"

AC_MSG_CHECKING([that a minimal Grid program compiles]);
AC_LINK_IFELSE(
	[AC_LANG_SOURCE([[
    #include <Grid/Grid.h>
    
    using namespace Grid;
    
    int main(int argc, char *argv[])
    {
        Grid_init(&argc, &argv);
        Grid_finalize();
        
        return 0;
    }
    
    ]])],
	[AC_MSG_RESULT([yes])],
    [AC_MSG_RESULT([no])]
    [AC_MSG_ERROR([impossible to compile a minimal Grid program])])

BKEEPER_CXX="$CXX"
BKEEPER_CXXLD="$CXXLD"
BKEEPER_CXXFLAGS="$CXXFLAGS"
BKEEPER_LDFLAGS="$LDFLAGS"
BKEEPER_LIBS="$LIBS"
BKEEPER_SHA=`git rev-parse HEAD`
BKEEPER_BRANCH=`git rev-parse --abbrev-ref HEAD`

AC_SUBST([CXXLD])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([BKEEPER_CXX])
AC_SUBST([BKEEPER_CXXLD])
AC_SUBST([BKEEPER_CXXFLAGS])
AC_SUBST([BKEEPER_LDFLAGS])
AC_SUBST([BKEEPER_LIBS])
AC_SUBST([BKEEPER_SHA])
AC_SUBST([BKEEPER_BRANCH])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
