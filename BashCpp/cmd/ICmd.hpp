#ifndef _CMD_CMD_INTERFACE_HPP
#define _CMD_CMD_INTERFACE_HPP

#include <string>
#include <vector>
#include <memory>

class ICmd
{
	public:
		virtual std::string GetName() const = 0;
		virtual std::string Execute(const std::vector<std::string>& Args) = 0;
		virtual std::string Execute(){
			return Execute(std::vector<std::string>());
		}

};

#endif