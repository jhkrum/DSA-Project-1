OUTPUTDIR = build
SRCDIR = src
EXECUTABLE = DSA-Project-1

all:
	g++ -c -o $(OUTPUTDIR)/$(EXECUTABLE).o $(SRCDIR)/$(EXECUTABLE).cpp
	g++ -o $(OUTPUTDIR)/$(EXECUTABLE) $(OUTPUTDIR)/*.o
	mv $(OUTPUTDIR)/$(EXECUTABLE) ./

TOPTARGETS := all test clean

SUBDIRS := $(wildcard src/*/.)

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)

clean:
	rm -f build/*
	rm -f $(EXECUTABLE)
	rm -f tests/*
