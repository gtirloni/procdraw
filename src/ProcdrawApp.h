/* Copyright (c) 2018 Simon Bates
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#include "D3D11Graphics.h"
#include <memory>

namespace Procdraw {

class ProcdrawApp {
public:
    ProcdrawApp(HINSTANCE hInstance, int nCmdShow);
    static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
    int MainLoop();
    double Width();
    double Height();
    double MouseX();
    double MouseY();

private:
    HINSTANCE hInstance_;
    int nCmdShow_;
    HWND hWnd_;
    std::unique_ptr<D3D11Graphics> graphics_;
    void CreateAppWindow();
    void Draw();
};

} // namespace Procdraw