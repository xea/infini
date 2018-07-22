#ifndef XA_EXP05_H
#define XA_EXP05_H

#ifdef _WIN32
#include <windows.h>

#define MAIN WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)

#else // everything that's not windows

#define MAIN main(int argc, char **argv)

#endif // _WIN32

//#include <engine/Engine.h>

#endif // XA_EXP05_H