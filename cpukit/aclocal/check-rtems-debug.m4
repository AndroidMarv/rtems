## $Id$

AC_DEFUN([RTEMS_CHECK_RTEMS_DEBUG],
[AC_REQUIRE([RTEMS_ENABLE_RTEMS_DEBUG])
AS_IF([test x"${enable_rtems_debug}" = x"yes"]
  [AC_DEFINE_UNQUOTED(RTEMS_DEBUG,1,[if RTEMS_DEBUG is enabled])])
])
