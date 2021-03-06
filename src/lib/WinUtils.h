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

#ifndef PROCDRAW_WINUTILS_H
#define PROCDRAW_WINUTILS_H

#include <DirectXMath.h>

namespace Procdraw {

void TriangleNormal(DirectX::XMFLOAT3* normal, const DirectX::XMFLOAT3* vertex1, const DirectX::XMFLOAT3* vertex2, const DirectX::XMFLOAT3* vertex3);

} // namespace Procdraw

#endif
