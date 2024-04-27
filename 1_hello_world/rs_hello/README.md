# Fibonacci Benchmarks

```
❯ ruby bin/benchmark
ruby 3.3.1 (2024-04-23 revision c56cd86388) [arm64-darwin23]
Warming up --------------------------------------
                Ruby   176.000 i/100ms
                   C     5.064k i/100ms
                Rust     4.902k i/100ms
Calculating -------------------------------------
                Ruby      1.751k (± 1.3%) i/s -      8.800k in   5.027581s
                   C     50.571k (± 1.2%) i/s -    253.200k in   5.007577s
                Rust     49.343k (± 1.0%) i/s -    250.002k in   5.067185s

Comparison:
                   C:    50570.5 i/s
                Rust:    49342.7 i/s - 1.02x  slower
                Ruby:     1750.6 i/s - 28.89x  slower
```

```
❯ rubyjit bin/benchmark
ruby 3.3.1 (2024-04-23 revision c56cd86388) +YJIT [arm64-darwin23]
Warming up --------------------------------------
                Ruby     1.294k i/100ms
                   C     5.084k i/100ms
                Rust     4.946k i/100ms
Calculating -------------------------------------
                Ruby     12.891k (± 1.1%) i/s -     64.700k in   5.019751s
                   C     50.537k (± 1.3%) i/s -    254.200k in   5.030837s
                Rust     49.342k (± 0.9%) i/s -    247.300k in   5.012316s

Comparison:
                   C:    50536.6 i/s
                Rust:    49342.4 i/s - 1.02x  slower
                Ruby:    12890.8 i/s - 3.92x  slower
```
