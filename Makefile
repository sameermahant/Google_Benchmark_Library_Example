CC=g++

# Modify as needed
# -O0 is to prevent comiler optimizations
CC_FLAGS=-g -O0 -Wall -Wextra -pedantic -Wno-unused-variable -std=c++11

# Modify as per your setup
GOOGLE_BENCHMARK_INSTALL_PATH="/home/sameer/softwares/google_benchmark_v1.1.0"
GOOGLE_BENCHMARK_INCLUDE_PATH=${GOOGLE_BENCHMARK_INSTALL_PATH}/include
GOOGLE_BENCHMARK_LIBRARY_PATH=${GOOGLE_BENCHMARK_INSTALL_PATH}/lib

all: google_benchmark_library_example

google_benchmark_library_example: google_benchmark_library_example.cpp
	$(CC) $(CC_FLAGS) \
	-I$(GOOGLE_BENCHMARK_INCLUDE_PATH) \
	-L$(GOOGLE_BENCHMARK_LIBRARY_PATH) \
	-o google_benchmark_library_example google_benchmark_library_example.cpp \
	-lbenchmark -pthread
	@echo "--------------------"

clean:
	rm -vf google_benchmark_library_example

.PHONEY: clean
