CXX = g++
CXXFLAGS = -pthread

# automatically find all .cc files and compile them directly into
# exectuable of the same name
SOURCES = $(shell ls *.cc)
EXECS = $(patsubst %.cc,%,$(SOURCES))

all : $(EXECS)

$(EXECS): %: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

clean : 
	rm $(EXECS)

