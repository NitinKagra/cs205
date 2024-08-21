#include "MemoryManager.h"
#include <algorithm>

MemoryManager::MemoryManager() : freePages(PHYSICAL_MEMORY_SIZE / PAGE_SIZE, true) {}

uint32_t MemoryManager::allocatePage() {
    for (uint32_t i = 0; i < freePages.size(); ++i) {
        if (freePages[i]) {
            freePages[i] = false;
            return i;
        }
    }
    throw std::runtime_error("No free pages available!");
}

void MemoryManager::deallocatePage(uint32_t page_number) {
    freePages[page_number] = true;
}

uint32_t MemoryManager::getFreePagesCount() const {
    return std::count(freePages.begin(), freePages.end(), true);
}