# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -g

# Source files
# SRCS = main.cpp KVStoreManager.cpp LSM.cpp MemTable.cpp
SRCS = *.cpp

TESTSRCS = tests/*.cpp *.cpp
# TESTSRCS = ^(?!.*\bmain\.cpp\b).*\.cpp$
# Header files
# HDRS = KVStoreInterface.h	LSM.h	KVStoreManager.h

# Output executable
TARGET = mydb

# Build target
all: $(TARGET)

mydb_tests: 
	$(CXX)	$(CXXFLAGS)	$(TESTSRCS)	-o	mydb_tests

# Link object files to create the executable
$(TARGET):	$(SRCS)
	$(CXX)	$(CXXFLAGS)	$(SRCS)	-o	$(TARGET)

# Clean up build files
clean:
	rm	-f	$(TARGET) test_sstable mydb_tests

# Phony targets
.PHONY: all clean