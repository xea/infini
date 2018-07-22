#ifndef XA_EXP05_H
#define XA_EXP05_H

#ifdef _WIN32
#include <windows.h>

#define MAIN WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

#else // everything that's not windows

#define MAIN main(int argc, char **argv)

#endif // _WIN32

//#include <engine/Engine.h>

#endif // XA_EXP05_H