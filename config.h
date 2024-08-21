#ifndef CONFIG_H
#define CONFIG_H

#include <cstdint>

const uint32_t PAGE_SIZE = 4096; // 4KB page size
const uint32_t VIRTUAL_MEMORY_SIZE = 1 << 30; // 1GB virtual memory
const uint32_t PHYSICAL_MEMORY_SIZE = 1 << 28; // 256MB physical memory

// Configuration for multi-level page table
const uint32_t LEVELS = 2; 
const uint32_t ENTRIES_PER_LEVEL = 1024;

#endif // CONFIG_H
