#include <benchmark/benchmark.h>

static void CustomArguments(benchmark::internal::Benchmark* b)
{
    for (int i = 11; i <= 15; ++i) {
        b->Args({i});
    }
}

int HashFunction(int number)
{
    // return number % 1000;
    // return number % 1024;
    return number & 1023;
}

void BM_HashFunction(benchmark::State& state)
{
  while (state.KeepRunning()) {
    int hashValue = HashFunction(state.range(0));
  }
}

// Single input
BENCHMARK(BM_HashFunction)->Args({42});

// Multiple inputs
BENCHMARK(BM_HashFunction)->Args({1000})->Args({42});

// Range inputs with default multiplier (8)
BENCHMARK(BM_HashFunction)->Range(1,2048);  // { 1, 8, 64, 512, 2048 }

// Range input with custom multiplier (2)
BENCHMARK(BM_HashFunction)->RangeMultiplier(2)->Range(1,10); // { 1, 2, 4, 8, 10 }

// Custom Arguments
BENCHMARK(BM_HashFunction)->Apply(CustomArguments);  // { 11, 12, 13, 14, 15 }

// Different output time units
BENCHMARK(BM_HashFunction)->Args({42})->Unit(benchmark::kNanosecond); // default
BENCHMARK(BM_HashFunction)->Args({42})->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_HashFunction)->Args({42})->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN()
