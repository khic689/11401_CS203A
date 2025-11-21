/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/20: Finish myHashInt implementation
    - 2025/11/21: Finish myHashString implementation

   Developer: Hu-Kai-Chieh <s1121429@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    if (m <= 0) return 0;  // Ensure m is valid

    // Convert key to an unsigned integer to avoid issues with negative numbers
    unsigned int k = (unsigned int)key;

    // Simple bit-mixing operations
    k = k ^ (k >> 16);  // Mix high and low bits
    k = k * 31;         // Simple multiplication to avoid small key values
    k = k ^ (k >> 13);  // Further mix high and low bits
    k = k + (k << 5);   // Add non-linear variation

    // Write the mixed result back to key
    key = (int)k;

    return key % m;  // Basic division method
}

int myHashString(const char* str, int m) {
    if (m <= 0) return 0;  // Ensure m is valid

    unsigned long hash = 0;
    while (*str) {  // Traverse each character in the string
        hash = hash * 31 + (unsigned long)(*str);  // Convert char to ASCII and compute hash value
        str++;
    }

    return (int)(hash % m);  // Basic division method
}