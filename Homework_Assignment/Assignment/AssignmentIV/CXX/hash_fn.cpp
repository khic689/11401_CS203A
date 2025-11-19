/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    if (m <= 0) return 0;  // Ensure m is valid

    // Convert key to an unsigned integer to avoid issues with negative numbers
    unsigned int k = static_cast<unsigned int>(key);

    // Simple bit-mixing operations
    k = k ^ (k >> 16);  // Mix high and low bits
    k = k * 31;         // Simple multiplication to avoid small key values
    k = k ^ (k >> 13);  // Further mix high and low bits
    k = k + (k << 5);   // Add non-linear variation

    // Write the mixed result back to key
    key = static_cast<int>(k);

    return key % m;// basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    return static_cast<int>(hash % m);  // basic division method
}
