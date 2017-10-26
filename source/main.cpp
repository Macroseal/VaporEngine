//Brandon Nguyen VaporEngine 2017- main.cpp

#include "Application.h"

int main()
{
	//Initialize main game and let it run
	std::unique_ptr<ve::Application> gameUniqueRef = std::make_unique<ve::Application>(500, 500, "VaporEngine");
	gameUniqueRef->Run();

	return 0;
}