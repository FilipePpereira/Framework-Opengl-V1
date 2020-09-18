#include"Game.h"



int main()
{
	Game::Instance()->Initialized("OpenGl Learn", 800, 600);
	Game::Instance()->Run();


	return 0;
}