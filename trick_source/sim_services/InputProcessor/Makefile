
# $Id: Makefile 3634 2014-08-14 14:41:45Z alin $

include ${TRICK_HOME}/makefiles/Makefile.common

# override the trick lib file for this directory.
TRICK_LIB := $(TRICK_LIB_DIR)/libtrick_pyip.a
include ${TRICK_HOME}/makefiles/Makefile.tricklib

TRICK_CFLAGS += $(PYTHON_INCLUDES)
TRICK_CXXFLAGS += $(PYTHON_INCLUDES)

-include Makefile_deps

