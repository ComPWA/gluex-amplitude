
GLUEXAMPLITUDE := $(shell pwd)/src/GlueXAmplitude
ifndef AMPTOOLS_HOME
  AMPTOOLS_HOME := $(shell pwd)/extern/AmpTools
endif
AMPTOOLS := $(AMPTOOLS_HOME)/AmpTools
AMPPLOTTER := $(AMPTOOLS_HOME)/AmpPlotter

export

.PHONY: default clean

default:
	@echo "=== Building src directory ==="
	@$(MAKE) -C src/GlueXAmplitude
	@echo "=== Building script directory ==="
	@$(MAKE) -C script

clean:
	@$(MAKE) -C src/GlueXAmplitude clean
	@$(MAKE) -C scripts clean
