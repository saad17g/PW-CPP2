CXX = g++
CXXFLAGS = -Wall -Wpedantic -pedantic -std=c++11 -ansi -g 
SOURCES = main.cpp Trajet.cpp TrajetSimple.cpp Cellule.cpp ListeChainee.cpp \
TrajetCompose.cpp Catalogue.cpp
OBJECTS = $(subst .cpp,.o, $(SOURCES))
EXEC = sejours

all: $(EXEC)

debug: CXXFLAGS += -DMAP
debug: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -o $(EXEC) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)