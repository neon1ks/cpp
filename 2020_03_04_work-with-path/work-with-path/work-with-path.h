// Кодировка utf-8

#pragma once

#ifndef WORK_WITH_PATH_H
#define WORK_WITH_PATH_H

#include "Common.h"

#include <cstdarg>

namespace neon1ks
{
#ifdef MSWindows
	constexpr const char* DirSep = "\\";
	constexpr const char DirSepChar = '\\';
#else
	constexpr const char* DirSep = "/";
	constexpr const char DirSepChar = '/';
#endif

	/**
	 * @brief Преобразование пути к корректному виду
	 * @details Функция выполняет преобразование пути до файла или директории следующим образом:
	 * @li удаляются все повторяющиеся разделители
	 * @li удаляется завершающий разделитель
	 * @li для Windows все допустимые разделители заменяются на '\\'
	 * @code
	 *      для Unix:
	 *      GoodPath("/usr//local") -> "/usr/local"
	 *      GoodPath("/usr/local/") -> "/usr/local"
	 *      GoodPath("/usr///local/") -> "/usr/local"
	 *      для Windows:
	 *      GoodPath("c:\\Windows\\\\Program files\\") -> "c:\\Windows\\Program files"
	 *      GoodPath("c:/Windows/Program files") -> "c:\\Windows\\Program files"
	 * @endcode
	 */
	string GoodPath(const string& name);

	/**
	 * @brief Конкатенация путей
	 * @details Функция конкатенирует два пути по следующим правилам:
	 * @li Если first пуст, возвращается second
	 * @li Если second пуст, возвращается first
	 * @li В противном случае два пути конкатенируются через соотетствующий ОС разделитель
	 * @li В любом случае к результату применяется функция GoodPath
	 * @see GoodPath
	 */
	string ConcatNPath(int n, ...);
	string ConcatPath(const string& first, const string& second);
	string ConcatPath(const string& first, const string& second, const string& third);

}  // namespace neon1ks

#endif
