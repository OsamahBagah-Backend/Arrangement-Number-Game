#include<iostream>
#include<string>
#include"clsGameScreen.h"
#include<time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	clsGameScreen Game;
	Game.StartGame();

	system("pause>0");
}