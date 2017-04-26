#ifndef _CMD_COPYFILE_HPP
#define _CMD_COPYFILE_HPP

#include "cmd\ICmd.hpp"
#include <sstream>
#include <windows.h>
#include <io.h>

class CopyFileCmd : public ICmd
{
public:
	std::string GetName() const override{
		return "appendfile";
	}
	std::string Execute(const std::vector<std::string>& Args) override {

		if (Args.size() >= 2){
			if (_access(Args[1].c_str(), 4)){
				if (0 != CopyFile(Args[1].c_str(), Args[2].c_str(), TRUE)){
					return ("File copied successful!");
				}
				else{
					std::ostringstream output;
					output << "Cannot copy file, error = '" << GetLastError() << "'";
					return output.str();
				}
			}else{
				return ("Cannot access to given file!");
			}

		}

		return ("Invalid parameters!");
	}
};

#endif