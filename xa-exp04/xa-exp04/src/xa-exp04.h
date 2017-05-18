#ifndef XA_EXP04_H
#define XA_EXP04_H

#ifdef _WIN32
#include <windows.h>

#define MAIN WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

#else // everything that's not windows

#define MAIN main(int argc, char **argv)

#endif // _WIN32

#include <engine/Engine.h>

#endif // XA_EXP04_H