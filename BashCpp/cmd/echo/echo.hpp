#ifndef _CMD_ECHO_HPP
#define _CMD_ECHO_HPP

#include "cmd\ICmd.hpp"

class EchoCmd : public ICmd
{
	public:
		std::string GetName() const override{
			return "echo";
		}
		std::string Execute(const std::vector<std::string>& Args) override {
			std::stringstream sstrResult;

			for (const std::string& arg : Args){
				sstrResult << arg;
			}

			sstrResult << std::endl;

			return sstrResult.str();
			
		}
};

#endif