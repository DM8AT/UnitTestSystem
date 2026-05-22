/**
 * @file Test1.cpp
 * @author DM8AT
 * @brief a simple example test that always succeeds
 * @version 0.1
 * @date 2026-05-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */
//add the test contract
#include "TestContract.h"

#include <iostream>
#include <fstream>
#include <filesystem>

void runTest(const TestContext* ctx, TestReport* report, const TestFunctions* funcs) {
    //log a message
    TestMessage msg {};
    msg.messageType = TEST_MESSAGE_TYPE_INFO;
    msg.msg = "Hello World from the message system!";

    (*(funcs->log))(&msg);

    std::cout << "Hello from test\n";
    std::cout << "Another message from test\n";

    std::cerr << "This is in the error pipe\n";

    msg.msg = "Another message";
    (*(funcs->log))(&msg);

    //success
    report->result = TEST_SUCCESS;
}

//define the registration function
TEST_REGISTER_TEST_FN{
    //if the data is null, set the size
    if (data == NULL) {
        *size = 1;
    } else {
        //else, write the data
        data->invoker = static_cast<PFN_TestInvoker>(&runTest);
        data->entry.name = "Example Test";
        data->entry.description = "Just a test to show that the contract works";
        data->entry.tags = "example simple";
        data->entry.requirements = 0;
        data->entry.timeout = 1E3;
    }
}

TEST_GET_ABI_VERSION_FN {
    //this uses ABI version 1
    return 1;
}