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

}  // namespace neon1ks
