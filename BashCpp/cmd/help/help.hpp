#ifndef _CMD_HELP_HPP
#define _CMD_HELP_HPP

#include "cmd\ICmd.hpp"
#include <sstream>

class HelpCmd : public ICmd
{
	private:
		std::string strCommands;

	public:
		HelpCmd(const std::vector<std::shared_ptr<ICmd>>& Commands){
			std::stringstream sstrCommands;

			sstrCommands << "List of all commands:" << std::endl;
			for (auto cmd : Commands){
				sstrCommands << "\t" << cmd->GetName() << std::endl;
			}

			strCommands = sstrCommands.str();
		}

		std::string GetName() const override{
			return "help";
		}
		std::string Execute(const std::vector<std::string>& Args) override {
			return strCommands;
		}
};

#endif