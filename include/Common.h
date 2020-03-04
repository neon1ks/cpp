// Кодировка utf-8

#pragma once

#ifndef PP_LIB_AES_COMMON_H
#define PP_LIB_AES_COMMON_H

//==============================================================================
// Определение операционной системы
// [c++ - How to detect reliably Mac OS X, iOS, Linux, Windows in C preprocessor? - Stack Overflow]
// (https://stackoverflow.com/questions/5919996/how-to-detect-reliably-mac-os-x-ios-linux-windows-in-c-preprocessor)
//==============================================================================

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#ifndef MSWindows
#define MSWindows 1
#endif
#endif

#ifdef __APPLE__
#ifndef MacOSX
#define MacOSX 1
#endif
#endif

#if defined(__linux) || defined(__linux__)
#ifndef LinuxOS
#define LinuxOS 1
#endif
#endif

#include <string>

using std::string;

#endif