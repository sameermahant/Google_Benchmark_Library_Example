#!/bin/bash

make clean; clear;

echo "--------------------"
echo "Compiling program..."
echo "--------------------"
make || exit

echo "Running program..."
echo "--------------------"

# Setting CPU in max performance mode (requires root permission)
echo performance | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor > /dev/null

# Running our process on isolated CPU core
taskset -c 1 ./google_benchmark_library_example

# Re-setting CPU performance mode (requires root permission)
echo powersave | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor > /dev/null
echo "================================================================================"
