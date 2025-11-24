# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

**Developer:** Hu-Kai-Chieh  
**Email:** s1121429@mail.yzu.edu.tw  

## Environment Note
* **Operating System:** Linux (WSL 2 - Windows Subsystem for Linux, Ubuntu 22.04 LTS)
* **Platform:** Windows 10/11 Host
* **Editor:** VS Code (Remote - WSL)
* *Note: All compilation and execution commands below are intended for the WSL terminal.*

## My Hash Function

### Integer Keys 
- **Formula / pseudocode:**
  ```text
  FUNCTION myHashInt(key, m)
      IF m <= 0 THEN RETURN 0
      
      k = (unsigned int) key
      k = k XOR (k >> 16)      // Mix high and low bits
      k = k * 31               // Multiplication for scattering
      k = k XOR (k >> 13)      // Further mixing
      k = k + (k << 5)         // Non-linear variation
      
      RETURN (int) (k MOD m)
  END FUNCTION
兒Rationale: I implemented a Bit-Mixing algorithm inspired by Thomas Wang's integer hash. Simple division (key % m) fails when keys have patterns (e.g., 10, 20, 30 with m=10). By using XOR-shifts and multiplication by a prime (31), I ensure the "Avalanche Effect"—changing one bit in the input affects many bits in the output, minimizing collisions even for patterned data.

### Non-integer Keys
- Formula / pseudocode:
```
  FUNCTION myHashString(str, m)
    IF m <= 0 THEN RETURN 0

    hash_val = 0
    FOR EACH char ch IN str DO
        // Polynomial Rolling Hash
        hash_val = (hash_val * 31) + ASCII(ch)
    END FOR

    RETURN (int) (hash_val MOD m)
END FUNCTION
```
- Rationale: I used the Polynomial Rolling Hash (similar to Java's hashCode). It treats the string as a polynomial with a prime base (31). This ensures that "abc" and "cba" produce different hashes (positional weight). The multiplier 31 is chosen because it is an odd prime, reducing the chance of common factors with the table size m.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  # Build both C and C++ versions (or default target)
  make
  # OR
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot

[snapshot of working]<img width="559" height="842" alt="螢幕擷取畫面 2025-11-24 085329" src="https://github.com/user-attachments/assets/e46993c2-9388-4495-a2e1-fbcf4167d12c" />


- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
