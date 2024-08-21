// Test.h
#ifndef TEST_H
#define TEST_H

#include <string>

class Test {
public:
    static void generateTraceFile(const std::string& filename, int numberOfTasks);
};

#endif // TEST_H