#ifndef _CMD_READFILE_HPP
#define _CMD_READFILE_HPP

#include "cmd\ICmd.hpp"
#include <fstream>

class ReadFileCmd : public ICmd
{
public:
	std::string GetName() const override{
		return "readfile";
	}
	std::string Execute(const std::vector<std::string>& Args) override {
		std::ifstream file;
		std::string output;
		std::stringstream buffer;

		if (!Args.empty()){
			file.open(Args[0]);
			if (file.is_open()){
				buffer << file.rdbuf();
				output = buffer.str();
				output.append("\n<EOF");

				file.close();
				return output;
			}
		}

		return output.append("Invalid filename!");
	}
};

#endif