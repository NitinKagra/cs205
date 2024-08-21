#include "Test.h"
#include <fstream>
#include <random>
#include "config.h"

void Test::generateTraceFile(const std::string& filename, int numberOfTasks) {
    std::ofstream file(filename);
    std::default_random_engine generator;
    std::uniform_int_distribution<uint32_t> addressDist(0, VIRTUAL_MEMORY_SIZE / PAGE_SIZE);
    std::uniform_int_distribution<uint32_t> sizeDist(1, 256); // Up to 256KB

    for (int i = 0; i < numberOfTasks; ++i) {
        std::string taskId = "T" + std::to_string(i + 1);
        for (int j = 0; j < 10; ++j) { // Each task has 10 memory requests
            uint32_t logicalAddress = addressDist(generator) * PAGE_SIZE;
            uint32_t size = sizeDist(generator) * 1024;
            file << taskId << ": 0x" << std::hex << logicalAddress << ": " << std::dec << size << "KB" << std::endl;
        }
    }
}