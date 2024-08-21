#include "IO.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Task*> IO::readTraceFile(const std::string& filename, MemoryManager& memoryManager) {
    std::ifstream file(filename);
    std::string line;
    std::unordered_map<std::string, Task*> taskMap;
    std::vector<Task*> tasks;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string taskId;
        std::string logicalAddressStr;
        std::string sizeStr;
        
        std::getline(iss, taskId, ':');
        std::getline(iss, logicalAddressStr, ':');
        std::getline(iss, sizeStr, ':');

        uint32_t logicalAddress = std::stoul(logicalAddressStr, nullptr, 16);
        uint32_t size = (sizeStr.find("KB") != std::string::npos) 
                        ? std::stoi(sizeStr) * 1024 
                        : std::stoi(sizeStr) * 1024 * 1024;

        if (taskMap.find(taskId) == taskMap.end()) {
            taskMap[taskId] = new Task(memoryManager);
            tasks.push_back(taskMap[taskId]);
        }

        taskMap[taskId]->allocateMemory(logicalAddress, size);
    }

    return tasks;
}