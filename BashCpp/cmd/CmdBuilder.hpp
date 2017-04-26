#ifndef _CMD_CMD_BUILDER_HPP
#define _CMD_CMD_BUILDER_HPP

#include <memory>
#include <vector>
#include "ICmd.hpp"
#include "echo\echo.hpp"
#include "help\help.hpp"
#include "readfile\readfile.hpp"
#include "appendfile\appendfile.hpp"
#include "copyfile\copyfile.hpp"

class CmdBuilder
{
	private:
		CmdBuilder(){}
		virtual ~CmdBuilder(){}

	public:
		static std::vector<std::shared_ptr<ICmd>> BuildCmdList(){
			std::vector<std::shared_ptr<ICmd>> CmdList;

			CmdList.push_back(std::make_shared<EchoCmd>(EchoCmd()));
			CmdList.push_back(std::make_shared<ReadFileCmd>(ReadFileCmd()));
			CmdList.push_back(std::make_shared<AppendFileCmd>(AppendFileCmd()));
			CmdList.push_back(std::make_shared<CopyFileCmd>(CopyFileCmd()));

			//Must be the last to auto list all avaliable commands
			std::shared_ptr<ICmd> helpCmd = std::make_shared<HelpCmd>(HelpCmd(CmdList));
			CmdList.push_back(helpCmd);

			return CmdList;
		}
};

#endif