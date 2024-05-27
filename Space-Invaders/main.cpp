#include"../../Header/Main/GameService.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace Main;
  int main() {

	  GameService* gameService = new GameService();

	  gameService->Ignite();

	  while (gameService->isRunning())
	  {
		  gameService->Update();
		  gameService->Render();
		 
	  }
      delete gameService;
      return 0;
  }