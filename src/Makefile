# Compiler
CXX = g++
# Compilation flags
CXXFLAGS = -Wall -std=c++11 -fPIC
# Libraries to link if needed (empty for now)
LIBS =

# Name of the shared library
SHARED_LIB = libLibrarySystem.so
# Name of the final executable
EXECUTABLE = LibrarySystem

# Source files
SRCS = Admin.cpp \
       AdminManager.cpp \
       Book.cpp \
       BookManager.cpp \
       ClassInfo.cpp \
       LendManager.cpp \
       Menu.cpp \
       Reader.cpp \
       ReaderManager.cpp \
       User.cpp

# Object files automatically derived from source files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(EXECUTABLE)

# Rule to build object files for the library with position-independent code
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to build the shared library from object files
$(SHARED_LIB): $(OBJS)
	$(CXX) -shared -o $(SHARED_LIB) $(OBJS)

# Rule to build the main executable, linking with the shared library
$(EXECUTABLE): main.o $(SHARED_LIB)
	$(CXX) main.o -L. -lLibrarySystem -o $(EXECUTABLE) $(LIBS)

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) main.o $(EXECUTABLE) $(SHARED_LIB)

# Phony targets
.PHONY: all clean
