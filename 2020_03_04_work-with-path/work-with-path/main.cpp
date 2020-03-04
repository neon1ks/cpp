// Кодировка utf-8

#include "work-with-path.h"

#include <iostream>

int main()
{
	string path1 = "C:\\Program Files";
	string path2 = "C:\\Program Files\\";
	string path3 = "C:\\Program Files\\";
	string path4 = "C:/Program Files\\";
	string path5 = "C:/Program Files/";
	string path6 = "C:\\\\Program Files/";
	string path7 = "C:\\\\";

	std::cout << "Orig = \"" << path1 << "\"\n";
	std::cout << "Good = \"" << neon1ks::GoodPath(path1) << "\"\n\n";

	std::cout << "Orig = \"" << path2 << "\"\n";
	std::cout << "Good = \"" << neon1ks::GoodPath(path2) << "\"\n\n";

	std::cout << "Orig = \"" << path3 << "\"\n";
	std::cout << "Good = \"" << neon1ks::GoodPath(path3) << "\"\n\n";

	std::cout << "Orig = \"" << path4 << "\"\n";
	std::cout << "Good = \"" << neon1ks::GoodPath(path4) << "\"\n\n";

	std::cout << "Orig = \"" << path5 << "\"\n";
	std::cout << "Good = \"" << neon1ks::GoodPath(path5) << "\"\n"
			  << std::endl;

	std::cout << "Orig = \"" << path6 << "\"\n";
	std::cout << "Good = \"" << neon1ks::GoodPath(path6) << "\"\n"
			  << std::endl;
	std::cout << "Orig = \"" << path7 << "\"\n";
	std::cout << "Good = \"" << neon1ks::GoodPath(path7) << "\"\n"
			  << std::endl;


	string dirName1 = "dirName1";
	string dirName2 = "\\dirName2\\";
	string dirName3 = "/dirName3/";

	std::cout << "AppendPath = \"" << path7 + neon1ks::DirSep + dirName1 << "\"\n";
	std::cout << "ConcatPath = \"" << neon1ks::ConcatPath(path7, dirName1) << "\"\n"
			  << std::endl;

	
	std::cout << "AppendPath = \"" << path7 + neon1ks::DirSep + dirName2 << "\"\n";
	std::cout << "ConcatPath = \"" << neon1ks::ConcatPath(path7, dirName2) << "\"\n"
			  << std::endl;

	std::cout << "AppendPath = \"" << path7 + neon1ks::DirSep + dirName3 << "\"\n";
	std::cout << "ConcatPath = \"" << neon1ks::ConcatPath(path7, dirName3) << "\"\n"
			  << std::endl;

	return 0;
}