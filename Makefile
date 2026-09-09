CXX      ?= g++
CXXFLAGS ?= -O2 -std=c++17 -Wall -Wextra

all: agentty-stats

agentty-stats: agentty-stats.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f agentty-stats

.PHONY: all clean
