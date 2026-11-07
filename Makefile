GLUEXAMPLITUDE := $(CURDIR)/src/GlueXAmplitude
ifndef AMPTOOLS_HOME
  AMPTOOLS_HOME := $(CURDIR)/extern/AmpTools
endif
AMPTOOLS := $(AMPTOOLS_HOME)/AmpTools
AMPPLOTTER := $(AMPTOOLS_HOME)/AmpPlotter
AMPTOOLS_COMPAT := $(CURDIR)/build/amptools-compat
CONFIG_PARSER := IUAmpTools/ConfigFileParser.h
COMPAT_CXX := $(CXX) -I$(AMPTOOLS_COMPAT)

export

.PHONY: default clean

default: $(AMPTOOLS_COMPAT)/$(CONFIG_PARSER)
	@$(MAKE) -C $(AMPTOOLS_HOME) CXX="$(COMPAT_CXX)"
	@echo "=== Building src directory ==="
	@$(MAKE) -C src/GlueXAmplitude CXX="$(COMPAT_CXX)"
	@echo "=== Building script directory ==="
	@$(MAKE) -C script CXX="$(COMPAT_CXX)"

# Define the destructor after ConfigFileLine is complete for Clang in C++20 mode.
$(AMPTOOLS_COMPAT)/$(CONFIG_PARSER): $(AMPTOOLS)/$(CONFIG_PARSER) Makefile
	@mkdir -p "$(@D)"
	@awk '/^[[:space:]]*~ConfigFileParser\(\) \{\}[[:space:]]*$$/ { sub(/ \{\}/, ";"); moved = 1 } \
	    /^#endif/ && moved { print "inline ConfigFileParser::~ConfigFileParser() {}\n"; moved = 0 } \
	    { print }' "$<" > "$@.tmp"
	@mv "$@.tmp" "$@"

clean:
	@$(MAKE) -C src/GlueXAmplitude clean
	@$(MAKE) -C scripts clean
