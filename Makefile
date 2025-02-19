CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wunused-function
LINKFLAGS := -mwindows


SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%, build/%, $(patsubst %.cpp, %.o, $(SOURCES)))
DEPENDS := $(patsubst src/%, build/%, $(patsubst %.cpp, %.d, $(SOURCES)))
INCLUDE := -I include/raylib_cpp -I include/raylib -I include/
LIBS := -L lib/ -lraylib -lgdi32 -lwinmm

ASSETS_DIR := assets/

BIN := bin/
EXE := $(BIN)ludo-rl.exe

.PHONY: all
all: $(EXE)

.PHONY: full
full: $(EXE) run

$(EXE): $(OBJECTS)
	g++ $(LINKFLAGS) $(OBJECTS) $(COFF) -o $(EXE) $(LIBS) -g
# mkdir -p $(BIN)$(ASSETS_DIR)
# cp -r $(ASSETS_DIR) $(BIN)

-include $(DEPENDS)

$(OBJECTS): build/%.o: src/%.cpp | build_dirs
	$(CXX) $(CXXFLAGS) -MMD -MD -c $< $(INCLUDE) -o $@ -g

.PHONY: build_dirs
build_dirs: $(BIN) build

$(BIN):
	mkdir -p bin

build:
	mkdir -p build

.PHONY: clean
clean:
	rm -rf bin/*
	rm -f build/*.o
	rm -f build/*.d
	rm -f build/*.coff

.PHONY: run
run:
	./$(EXE)
