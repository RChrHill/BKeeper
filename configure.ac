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

########### All ###########
AC_ARG_ENABLE([all], [Enable compilation for all targets by default.], [:], [enable_all=yes])
if test "x${enable_all}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_ALL], [], [Enable all targets])
    AC_MSG_NOTICE(Enabling all targets by default)
elif test "x${enable_all}" = "xno"; then
    AC_MSG_NOTICE(Disabling all targets by default)
else
    AC_MSG_NOTICE(Unrecognised enable-all option '${enable_all}'; disabling all targets by default)
fi

########### SU(2) Fund ###########
AC_ARG_ENABLE([su2fund], [Enable compilation for SU(2) Fundamental.], [:], [enable_su2fund=auto])
if test "x${enable_su2fund}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU2FUND], [], [Enable SU(2) Fundamental])
    AC_MSG_NOTICE(Enabling SU(2) fundamental)
elif test "x${enable_su2fund}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU2FUND], [], [Disable SU(2) Fundamental])
    AC_MSG_NOTICE(Disabling SU(2) fundamental)
fi

########### SU(2) Adj ###########
AC_ARG_ENABLE([su2adj], [Enable compilation for SU(2) Adjoint.], [:], [enable_su2adj=auto])
if test "x${enable_su2adj}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU2ADJ], [], [Enable SU(2) Adjoint])
    AC_MSG_NOTICE(Enabling SU(2) adjoint)
elif test "x${enable_su2adj}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU2ADJ], [], [Disable SU(2) Adjoint])
    AC_MSG_NOTICE(Disabling SU(2) fundamental)
fi

########### SU(2) TwoIndexSymm ###########
AC_ARG_ENABLE([su2tis], [Enable compilation for SU(2) Two-Index Symmetric.], [:], [enable_su2tis=auto])
if test "x${enable_su2tis}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU2TIS], [], [Enable SU(2) Two-Index Symmetric])
    AC_MSG_NOTICE(Enabling SU(2) two-index symmetric)
elif test "x${enable_su2tis}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU2TIS], [], [Disable SU(2) Two-Index Symmetric])
    AC_MSG_NOTICE(Disabling SU(2) two-index symmetric)
fi

########### SU(2) TwoIndexAntiSymm ###########
AC_ARG_ENABLE([su2tias], [Enable compilation for SU(2) Two-Index AntiSymmetric.], [:], [enable_su2tias=auto])
if test "x${enable_su2tias}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU2TIAS], [], [Enable SU(2) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Enabling SU(2) two-index antisymmetric)
elif test "x${enable_su2tias}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU2TIAS], [], [Disable SU(2) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Disabling SU(2) two-index antisymmetric)
fi

########### SU(3) Fund ###########
AC_ARG_ENABLE([su3fund], [Enable compilation for SU(3) Fundamental.], [:], [enable_su3fund=auto])
if test "x${enable_su3fund}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU3FUND], [], [Enable SU(3) Fundamental])
    AC_MSG_NOTICE(Enabling SU(3) fundamental)
elif test "x${enable_su3fund}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU3FUND], [], [Disable SU(3) Fundamental])
    AC_MSG_NOTICE(Disabling SU(3) fundamental)
fi

########### SU(3) Adj ###########
AC_ARG_ENABLE([su3adj], [Enable compilation for SU(3) Adjoint.], [:], [enable_su3adj=auto])
if test "x${enable_su3adj}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU3ADJ], [], [Enable SU(3) Adjoint])
    AC_MSG_NOTICE(Enabling SU(3) adjoint)
elif test "x${enable_su3adj}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU3ADJ], [], [Disable SU(3) Adjoint])
    AC_MSG_NOTICE(Disabling SU(3) adjoint)
fi

########### SU(3) TwoIndexSymm ###########
AC_ARG_ENABLE([su3tis], [Enable compilation for SU(3) Two-Index Symmetric.], [:], [enable_su3tis=auto])
if test "x${enable_su3tis}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU3TIS], [], [Enable SU(3) Two-Index Symmetric])
    AC_MSG_NOTICE(Enabling SU(3) two-index symmetric)
elif test "x${enable_su3tis}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU3TIS], [], [Disable SU(3) Two-Index Symmetric])
    AC_MSG_NOTICE(Disabling SU(3) two-index symmetric)
fi

########### SU(2) TwoIndexAntiSymm ###########
AC_ARG_ENABLE([su3tias], [Enable compilation for SU(3) Two-Index AntiSymmetric.], [:], [enable_su3tias=auto])
if test "x${enable_su3tias}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU3TIAS], [], [Enable SU(3) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Enabling SU(3) two-index antisymmetric)
elif test "x${enable_su3tias}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU3TIAS], [], [Disable SU(3) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Disabling SU(3) two-index antisymmetric)
fi

########### SU(4) Fund ###########
AC_ARG_ENABLE([su4fund], [Enable compilation for SU(4) Fundamental.], [:], [enable_su4fund=auto])
if test "x${enable_su4fund}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU4FUND], [], [Enable SU(4) Fundamental])
    AC_MSG_NOTICE(Enabling SU(4) fundamental)
elif test "x${enable_su4fund}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU4FUND], [], [Disable SU(4) Fundamental])
    AC_MSG_NOTICE(Disabling SU(4) fundamental)
fi

########### SU(4) Adj ###########
AC_ARG_ENABLE([su4adj], [Enable compilation for SU(4) Adjoint.], [:], [enable_su4adj=auto])
if test "x${enable_su4adj}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU4ADJ], [], [Enable SU(4) Adjoint])
    AC_MSG_NOTICE(Enabling SU(4) adjoint)
elif test "x${enable_su4adj}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU4ADJ], [], [Disable SU(4) Adjoint])
    AC_MSG_NOTICE(Disabling SU(4) adjoint)
fi

########### SU(4) TwoIndexSymm ###########
AC_ARG_ENABLE([su4tis], [Enable compilation for SU(4) Two-Index Symmetric.], [:], [enable_su4tis=auto])
if test "x${enable_su4tis}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU4TIS], [], [Enable SU(4) Two-Index Symmetric])
    AC_MSG_NOTICE(Enabling SU(4) two-index symmetric)
elif test "x${enable_su4tis}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU4TIS], [], [Disable SU(4) Two-Index Symmetric])
    AC_MSG_NOTICE(Disabling SU(4) two-index symmetric)
fi

########### SU(4) TwoIndexAntiSymm ###########
AC_ARG_ENABLE([su4tias], [Enable compilation for SU(4) Two-Index AntiSymmetric.], [:], [enable_su4tias=auto])
if test "x${enable_su4tias}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_SU4TIAS], [], [Enable SU(4) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Enabling SU(4) two-index antisymmetric)
elif test "x${enable_su4tias}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_SU4TIAS], [], [Disable SU(4) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Disabling SU(4) two-index antisymmetric)
fi

########### Sp(4) Fund ###########
AC_ARG_ENABLE([sp4fund], [Enable compilation for Sp(4) Fundamental.], [:], [enable_supfund=auto])
if test "x${enable_sp4fund}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_Sp4FUND], [], [Enable Sp(4) Fundamental])
    AC_MSG_NOTICE(Enabling Sp(4) fundamental)
elif test "x${enable_sp4fund}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_Sp4FUND], [], [Disable Sp(4) Fundamental])
    AC_MSG_NOTICE(Disabling Sp(4) fundamental)
fi

########### Sp(4) TwoIndexSymm ###########
AC_ARG_ENABLE([sp4tis], [Enable compilation for Sp(4) Two-Index Symmetric.], [:], [enable_sp4tis=auto])
if test "x${enable_sp4tis}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_Sp4TIS], [], [Enable Sp(4) Two-Index Symmetric])
    AC_MSG_NOTICE(Enabling Sp(4) two-index symmetric)
elif test "x${enable_sp4tis}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_Sp4TIS], [], [Disable Sp(4) Two-Index Symmetric])
    AC_MSG_NOTICE(Disabling Sp(4) two-index symmetric)
fi

########### Sp(4) TwoIndexAntiSymm ###########
AC_ARG_ENABLE([sp4tias], [Enable compilation for Sp(4) Two-Index AntiSymmetric.], [:], [enable_sp4tias=auto])
if test "x${enable_sp4tias}" = "xyes"; then
    AC_DEFINE_UNQUOTED([BKEEPER_ENABLE_Sp4TIAS], [], [Enable Sp(4) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Enabling Sp(4) two-index antisymmetric)
elif test "x${enable_sp4tias}" = "xno"; then
    AC_DEFINE_UNQUOTED([BKEEPER_DISABLE_Sp4TIAS], [], [Disable Sp(4) Two-Index AntiSymmetric])
    AC_MSG_NOTICE(Disabling Sp(4) two-index antisymmetric)
fi

########### GRID DEPENDENCY ###########
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
