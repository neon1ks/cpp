// Кодировка utf-8

#pragma once

#ifndef WORK_WITH_PATH_H
#define WORK_WITH_PATH_H

#include "Common.h"

namespace neon1ks
{
#ifdef MSWindows
	constexpr char* DirSep = "\\";
	constexpr char DirSepChar = '\\';
	constexpr char* DoubleDirSep = "\\\\";
#else
	constexpr char* DirSep = "/";
	constexpr char DirSepChar = '/';
	constexpr char* DoubleDirSep = "//";
#endif

	string GoodPath(const string& name);

}  // namespace neon1ks

#endif