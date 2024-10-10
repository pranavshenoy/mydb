# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -g

# Source files
SRCS = main.cpp KVStoreManager.cpp LSM.cpp

# Header files
# HDRS = KVStoreInterface.h	LSM.h	KVStoreManager.h

# Output executable
TARGET = mydb

# Build target
all: $(TARGET)

# Link object files to create the executable
$(TARGET):	$(SRCS)
	$(CXX)	$(CXXFLAGS)	$(SRCS)	-o	$(TARGET)

# Clean up build files
clean:
	rm	-f	$(TARGET)

# Phony targets
.PHONY: all clean