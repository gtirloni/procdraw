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

#include "ProcdrawApp.h"
#include "ProcdrawMath.h"
#include <stdexcept>

namespace Procdraw {

ProcdrawApp::ProcdrawApp(HINSTANCE hInstance, int nCmdShow)
    : hInstance_(hInstance),
      nCmdShow_(nCmdShow),
      hWnd_(nullptr)
{
    CreateAppWindow();
    graphics_ = std::unique_ptr<D3D11Graphics>(new D3D11Graphics(hWnd_));
}

int ProcdrawApp::MainLoop()
{
    MSG msg = {0};
    while (true) {
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                return msg.wParam;
            }
            else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        Draw();
        graphics_->Present();
        // TODO: frameCounter_.RecordFrame();
    }
}

double ProcdrawApp::Width()
{
    int width = 0;
    RECT rect;
    if (GetClientRect(hWnd_, &rect)) {
        width = rect.right - rect.left;
    }
    return static_cast<double>(width);
}

double ProcdrawApp::Height()
{
    int height = 0;
    RECT rect;
    if (GetClientRect(hWnd_, &rect)) {
        height = rect.bottom - rect.top;
    }
    return static_cast<double>(height);
}

double ProcdrawApp::MouseX()
{
    POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hWnd_, &pt);
    return Clamp(static_cast<double>(pt.x) / (Width() - 1), 0.0, 1.0);
}

double ProcdrawApp::MouseY()
{
    POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hWnd_, &pt);
    return Clamp(static_cast<double>(pt.y) / (Height() - 1), 0.0, 1.0);
}

void ProcdrawApp::CreateAppWindow()
{
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance_;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = L"ProcdrawWindowClass";
    wcex.hIconSm = nullptr;
    if (!RegisterClassEx(&wcex)) {
        throw std::runtime_error("Failed to register window class");
    }

    // Create window
    RECT rc = {0, 0, 640, 640};
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    hWnd_ = CreateWindow(L"ProcdrawWindowClass", L"Procdraw", WS_OVERLAPPEDWINDOW,
                         CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left,
                         rc.bottom - rc.top, nullptr, nullptr, hInstance_,
                         nullptr);

    if (!hWnd_) {
        throw std::runtime_error("Failed to create window");
    }

    ShowWindow(hWnd_, nCmdShow_);
}

LRESULT CALLBACK ProcdrawApp::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

void ProcdrawApp::Draw()
{
    graphics_->Background(200, 0.6f, 0.9f);
    graphics_->RotateX(static_cast<float>(Lerp(1.0, -1.0, MouseY())));
    graphics_->RotateY(static_cast<float>(Lerp(1.0, -1.0, MouseX())));
    graphics_->Color(7, 0.7f, 0.7f);
    graphics_->Cube();
}
} // namespace Procdraw
