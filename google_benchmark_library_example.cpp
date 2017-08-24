#include <benchmark/benchmark.h>

// Modify this function as needed
int Function(int arg1)
{
    // Repalce this with code / operation which you want to benchmark
    return arg1;
}

void BM_Function(benchmark::State& state)
{
  while (state.KeepRunning()) {
    // Replace this as needed
    int result = Function(state.range(0));
  }
}

BENCHMARK(BM_Function)->Args({42}); // Modify this as needed

BENCHMARK_MAIN()
