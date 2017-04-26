#ifndef _UTLIS_HPP
#define _UTILS_HPP

#include <string>
#include <sstream>
#include <vector>

namespace utils
{
	inline std::vector<std::string> getCommandWithArgs()
	{
		std::vector<std::string> Args;

		//Prompt character
		std::cout << "> ";

		std::string token;
		std::getline(std::cin, token);

		std::stringstream buffer(token);
		while (std::getline(buffer, token, ' ')){
			Args.push_back(token);
		}

		return Args;

	}
}


#endif