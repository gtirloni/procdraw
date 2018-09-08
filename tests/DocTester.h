/* Copyright (c) 2018 Simon Bates
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#include "Interpreter.h"
#include "ProcdrawManual.h"
#include <string>
#include <vector>

namespace Procdraw {
namespace Tests {

class DocTester {
public:
    bool RunTests(const char* filename, int expectedNumTests);
    const std::vector<std::string>& Messages() const;

private:
    std::vector<std::string> msgs_;
    void TestFunction(const FunctionDoc& functionDoc,
                      int& numTests,
                      int& numPassed);
    void TestExample(const FunctionExample& example,
                     Interpreter& interpreter,
                     const std::string& functionName,
                     int& numTests,
                     int& numPassed);
};

} // namespace Tests
} // namespace Procdraw