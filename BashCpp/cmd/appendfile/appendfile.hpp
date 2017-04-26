#ifndef _CMD_APPENDFILE_HPP
#define _CMD_APPENDFILE_HPP

#include "cmd\ICmd.hpp"
#include <fstream>
#include <sstream>

class AppendFileCmd : public ICmd
{
public:
	std::string GetName() const override{
		return "appendfile";
	}
	std::string Execute(const std::vector<std::string>& Args) override {
		std::ofstream file;
		std::string output;

		if (Args.size() >= 2){
			file.open(Args[0]);
			if (file.is_open()){
				file << Args[1];

				output.append("Succesfull!");

				file.close();
				return output;
			}
		}

		return output.append("Invalid parameters!");
	}
};

#endif