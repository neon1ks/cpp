// Кодировка utf-8

#include "Common.h"

#include "work-with-path.h"

#include <cstring>

namespace
{

#ifdef MSWindows
	constexpr char* FileSepChars = "\\/";
#else
	constexpr char FileSepChars = '/';
#endif

	// inpl обозначает In-place algorithm: https://en.wikipedia.org/wiki/In-place_algorithm
	namespace inpl
	{
		string& AppendPath(string& first, const string& second)
		{
			if (second.empty())
				return first;
			if (!first.empty())
				first.append(neon1ks::DirSep);
			return first.append(second);
		}
	}  // namespace inpl

	string AppendPath(const string& first, const string& second)
	{
		string wc = first;
		return inpl::AppendPath(wc, second);
	}

	// Является ли символ разделителем
	inline bool IsSep(char ch)
	{
#ifdef MSWindows
		return std::strchr(FileSepChars, ch) != nullptr;
#else
		return ch == FileSepChars;
#endif
	}

}  // namespace

namespace neon1ks
{

	string GoodPath(const string& name)
	{
		string res = name;
		string::size_type pos = res.find_first_of(FileSepChars);
		while (pos != string::npos)
		{
			res[pos++] = DirSepChar;
			auto end = pos;
			while (end < res.size() && IsSep(res[end]))
				++end;
			res.erase(pos, end - pos);
			pos = res.find_first_of(FileSepChars, pos);
		}

#ifdef MSWindows
		if (res.size() > 1 && IsSep(res[res.size() - 1]))
		{
			if (res[res.size() - 2] != ':')
			{
				res.resize(res.size() - 1);
			}
			else if (res.size() == 3)
			{
				res.resize(res.size() - 1);
			}
		}
#else
		if (res.size() > 1 && IsSep(res[res.size() - 1]))
		{
			res.resize(res.size() - 1);
		}
#endif

		return res;
	}

	string ConcatNPath(int n, ...)
	{
		string res;
		std::va_list vl;
		va_start(vl, n);
		while (--n >= 0)
		{
			res = AppendPath(res, va_arg(vl, char*));
		}
		va_end(vl);
		return GoodPath(res);
	}

	string ConcatPath(const string& first, const string& second)
	{
		return GoodPath(AppendPath(first, second));
	}

	string ConcatPath(const string& first, const string& second, const string& third)
	{
		return GoodPath(AppendPath(AppendPath(first, second), third));
	}

}  // namespace neon1ks
