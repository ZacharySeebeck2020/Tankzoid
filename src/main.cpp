#include <algorithm>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Logger.h"
#include "Game.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"

const std::string VERSION = "0.0.1";
Game* game = nullptr;

char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, char *argv[])
{
	std::cout << "Tankzoid " << VERSION << std::endl;
	std::cout << "Written By Zachary Seebeck" << std::endl;

	// If -h is passed in as an argument, print the help message and exit
	if(cmdOptionExists(argv, argv+argc, "-h"))
    {
        std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "  -h\t\t\tPrint this help message" << std::endl;
		std::cout << "  -l <level>\t\tSet the log level (default: 3)" << std::endl;
		std::cout << "  -v\t\t\tPrint the version" << std::endl;
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		std::cout << "Log Levels:" << std::endl;
		std::cout << "  0\t\t\tDebug" << std::endl;
		std::cout << "  1\t\t\tInfo" << std::endl;
		std::cout << "  2\t\t\tWarning" << std::endl;
		std::cout << "  3\t\t\tError" << std::endl;
		std::cout << "  4\t\t\tFatal" << std::endl;
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		return 0;
    }
	if (cmdOptionExists(argv, argv+argc, "-v"))
	{
		std::cout << "Version: " << VERSION << std::endl;
		return 0;
	}
	
	// Set the log level if -l is passed in as an argument
	if (cmdOptionExists(argv, argv+argc, "-l"))
	{
		char* level = getCmdOption(argv, argv+argc, "-l");
		if (level)
		{
			Logger::getInstance().setLogLevel(LogLevel(std::stoi(level)));
		}
	}

	// Start The Game
	game = new Game();

	game->Init(1280, 720, "Tankzoid");

	while(game->Running()) {
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();

	return 0;
}