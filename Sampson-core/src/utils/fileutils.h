#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class FileUtils {
public:
	static std::string read_file(const char* filepath)
	{
		std::string filestring;
		std::ifstream file;
		file.exceptions(std::ifstream::badbit);
		try
		{
			file.open(filepath);
			std::stringstream stream;
			stream << file.rdbuf();
			file.close();
			filestring = stream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "File not read successfully!" << std::endl;
		}
		return filestring;
	}
};
