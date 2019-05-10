/* Copyright (c) 2018, 2019 Simon Bates
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "DocTester.h"
#include <gtest/gtest.h>

namespace Procdraw {
namespace Tests {

// clang-format off

TEST(FunctionDocsTests, RunFunctionDocsTests)
{
    const int expectedNumTests = 15;

    DocTester tester;
    bool passed = tester.RunTests(PROCDRAW_FUNCTION_DOCS_FILE,
                                  expectedNumTests);
    EXPECT_TRUE(passed);
    for (auto message : tester.Messages()) {
        ADD_FAILURE() << message;
    }
}

}
}
