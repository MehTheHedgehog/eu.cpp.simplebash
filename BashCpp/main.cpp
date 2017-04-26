#include "main.hpp"

int _main()
{
	std::vector<std::string> Args;
	std::vector<std::shared_ptr<ICmd>> CmdList;

	//Introduction
	std::cout << "Welcome to simple bash!" << std::endl
		<< "Project for Europejska Uczelnia w Warszawie" << std::endl
		<< "Copyright@ Artur Jaworski" << std::endl << std::endl;

	CmdList = CmdBuilder::BuildCmdList();

	//Main loop of program
	while (true)
	{
		Args = utils::getCommandWithArgs();
		if (!Args.empty()){
			bool isFound = false;

			if ("exit" == Args[0])
				break;

			for (auto cdm : CmdList){
				if (cdm->GetName() == Args[0]){
					std::vector<std::string> CmdArgs;
					isFound = true;

					if (Args.size() > 1)
						CmdArgs = std::vector<std::string>(++Args.begin(), Args.end());

					std::cout << cdm->Execute(CmdArgs) << std::endl;
				}
					
			}

			if (!isFound)
				std::cout << Args[0] << " is not a valid command." << std::endl
				<< "Type 'help' to get list of valid commands" << std::endl
				<< "Type 'exit' to exit from bash" << std::endl;

			std::cout << std::endl;
		}
	}

	return 0;

}