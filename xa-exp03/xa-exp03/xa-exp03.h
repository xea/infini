#ifndef XA_EXP03_H
#define XA_EXP03_H

#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif

#include <engine/Engine.h>
#include <engine/GLFWView.h>

#ifdef _WIN32
#define MAIN WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
#define MAIN main(int argc, char **argv)
#endif
void messageBox(std::wstring& title, std::wstring& message);

#endif // XA_EXP03_H
