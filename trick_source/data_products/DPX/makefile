#
# $Id: makefile 1831 2011-07-27 21:34:24Z lin $
#
include ${TRICK_HOME}/makefiles/Makefile.common

RM = rm -rf

DPX_DIR = `pwd`
LIBDIR = ${DPX_DIR}/lib_${TRICK_HOST_CPU}

LIBDIRS = DPM \
          DPC \
          DPV/UTILS

APPDIRS = APPS/GXPLOT

ifneq ("$(wildcard ${TRICK_HOME}/trick_source/data_products/fermi-ware)","")
APPDIRS += APPS/FXPLOT
endif

all: $(LIBDIRS) $(APPDIRS) xml_catalog 

.PHONY: $(LIBDIRS) $(APPDIRS)

always_make:

docs: always_make
	@echo "===== Making DOCS ====="
	doxygen DPX.doxygen

testing: $(LIBDIRS)
	@echo "===== Making TESTING ====="
	$(MAKE) -C TESTING

xml_catalog: always_make
	@echo "===== Making XML CATALOG ====="
	$(MAKE) -C XML

$(LIBDIRS):
	@ echo ; echo "==: Compile $@"
	@ $(MAKE) -C $@

$(APPDIRS): $(LIBDIRS)
	@echo "===== Making APPS ====="
	@ echo ; echo "==: Compile $@"
	@ $(MAKE) -C $@

clean:
	@ for i in $(LIBDIRS) ; do \
	       $(MAKE) -C $$i clean ; \
          done
	@ for i in $(APPDIRS) ; do \
	       $(MAKE) -C $$i clean ; \
          done
	${RM}  -rf DOCS
	${RM} ${LIBDIR}
	$(MAKE) -C TESTING spotless
	$(MAKE) -C APPS spotless
	$(MAKE) -C XML clean
	${RM} *~
	${RM} *.o

real_clean: clean

