// Copyright 2020 Simon Bates
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PROCDRAW_PRINTER_H
#define PROCDRAW_PRINTER_H

#include "InterpreterTypes.h"
#include <string>

namespace Procdraw {

class Interpreter;

class Printer {
public:
    explicit Printer(Interpreter* interpreter);
    std::string Print(const Object& obj);

private:
    Interpreter* interpreter;
};

} // namespace Procdraw

#endif
