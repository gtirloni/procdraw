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

#ifndef PROCDRAW_CUBE_H
#define PROCDRAW_CUBE_H

#include <glad/glad.h>

namespace Procdraw {

class Cube {
public:
    Cube();
    ~Cube();
    void Draw();
    GLuint Vao()
    {
        return vao_;
    };

private:
    GLuint vao_;
    GLuint vertexBuffer_;
    GLuint indexBuffer_;
};

} // namespace Procdraw

#endif
