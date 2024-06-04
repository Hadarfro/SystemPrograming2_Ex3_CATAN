# /*
#  * Author: Hadar Froimowich.
#  * ID: 213118458
#  * Email: hadarfro12@gmail.com
#  */
# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion 
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Source and object files
SOURCES =  board.cpp player.cpp TestCounter.cpp Test.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule to build and run the demo
run: demo 
	./demo 

# Rule to build the demo executable
demo: Demo.o $(filter-out TestCounter.o Test.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -v $^ -o $@

# Rule to build the test executable
test: TestCounter.o Test.o $(filter-out Demo.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -v $^ -o $@

# Rule to run clang-tidy on the source files
tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# Rule to run valgrind on the demo and test executables
valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean up the build directory
clean:
	rm -f *.o demo test
