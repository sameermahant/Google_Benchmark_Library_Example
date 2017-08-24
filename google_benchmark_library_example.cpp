#include <benchmark/benchmark.h>

// Modify this function as needed
int HashFunction(int number)
{
    return number % 1000;
}

void BM_HashFunction(benchmark::State& state)
{
  while (state.KeepRunning()) {
    int hashValue = HashFunction(state.range(0));
  }
}

BENCHMARK(BM_HashFunction)->Args({42});

BENCHMARK_MAIN()
