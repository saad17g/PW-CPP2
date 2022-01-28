CXX = g++
CXXFLAGS = -std=c++11 -g
EXEC = sejours

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard src/*.cpp))

all: $(EXEC)

debug: CXXFLAGS += -DDEBUG -g
debug: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -o $(EXEC) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)
