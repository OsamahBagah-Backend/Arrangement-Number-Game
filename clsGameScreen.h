#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"clsGame.h"
#include"clsInputValidate.h"

using namespace std;

class clsGameScreen
{

protected:

	clsGame Game;

private:

	void _PrintTheSpaceCount()
	{
		if (Game.NumberOfLevels <= 6)
		{
			cout << "\t\t\t\t";
		}

		else if (Game.NumberOfLevels == 9)
		{
			cout << "\t";
		}
		else if (Game.NumberOfLevels > 9)
		{
			cout << "";
		}

		else
		{
			cout << "\t\t";
		}
	}

	void _PrintTheFooterOfTheGameShape()
	{
		_PrintTheSpaceCount();

		for (short i = 1; i <= Game.NumberOfLevels + 2; i++)
		{
			cout << " |_|      ";
		}

		cout << endl;
		_PrintTheSpaceCount();

		for (short i = 1; i <= Game.NumberOfLevels + 2; i++)
		{
			cout << " _" << i << "_      ";
		}
		cout << endl;
	}

	void _PrintThaGameShap(vector<vector<short>> ContainAllVectors)
	{
		cout << "\n\n";
		_PrintTheSpaceCount();

		for (short i = Game.NumberOfLevels; i >= 1; i--)
		{
			string vec1Elem;
			short count = 0;
			for (short j = ContainAllVectors.size(); j >= 1; j--)
			{
				vector<short>Vec = ContainAllVectors.at(count);
				vec1Elem = Game.ReturnNumberOrSpace(Vec, i);
				cout << " |" << vec1Elem << "|      ";
				count++;
			}

			if (i != 1)
			{
				cout << endl;
				_PrintTheSpaceCount();
			}
		}

		cout << endl;
		_PrintTheFooterOfTheGameShape();
	}

	void _AskThePlayerToChoice(vector<vector<short>>& ContainAllVectors)
	{
		short ChoiceFrom, ChoiceTo;

		while (true)
		{
			system("color 0F");
			system("cls");
			_PrintThaGameShap(ContainAllVectors);

			if (Game.ChickIfAllArraysContainEqualsElements(ContainAllVectors))
			{
				cout << "\n\n\t\t\t\tYou Winer very Exslant bro :-)\n";
				system("color 2F");
				break;
			}

			cout << "\n\t\t\t\tplease enter the row to remove from it :";
			ChoiceFrom = clsInputValidate::ReadFloatNumberBetween(1, ContainAllVectors.size());
			cout << "\n\t\t\t\tplease enter the row to come to   :";
			ChoiceTo = clsInputValidate::ReadFloatNumberBetween(1, ContainAllVectors.size());

			if (ChoiceFrom == ChoiceTo)
			{
				system("color 4F");
				cout << "\a";
			}

			else if (ContainAllVectors.at(ChoiceTo - 1).size() == Game.NumberOfLevels)
			{
				system("color 4F");
				cout << "\a";
			}

			else
			{
				Game.TransferElemnetFromVector1ToVector2(ContainAllVectors.at(ChoiceFrom - 1), ContainAllVectors.at(ChoiceTo - 1));

			}
		}

	}

	void _IncraeasNumberOfLevels()
	{
		if (Game.NumberOfSubLevels >= 10)
		{
			Game.NumberOfLevels++;
			Game.NumberOfSubLevels = 1;
		}
	}

	void ChickFromTheNextLevel()
	{
		if (Game.NumberOfSubLevels == 10)
		{
			system("cls");
			cout << "\n\n\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
			cout << "\t\t\t^\n";
			cout << "\t\t\t^                    YOU WINNER TO THE NEXT LEVLE      -:)\n";
			cout << "\t\t\t^\n";
			cout << "\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		}
	}
	void PlaingTheGame()
	{
		vector <vector<short>> ContainAllVectors;
		ContainAllVectors = Game.FillAllVectorsWithValues();
		Game._SaveTheLevelsInTheFile(Game.NumberOfLevels, Game.NumberOfSubLevels);
		_AskThePlayerToChoice(ContainAllVectors);
		Game.NumberOfSubLevels++;
		ChickFromTheNextLevel();
		_IncraeasNumberOfLevels();
		Game._SaveTheLevelsInTheFile(Game.NumberOfLevels, Game.NumberOfSubLevels);
	}

public:

	void StartGame()
	{
		char Choice = 'y';

		while (Game.NumberOfSubLevels < 11 && Game.NumberOfLevels <= 9)
		{
			PlaingTheGame();

			cout << "\n\n\t\t\t Do You Want To Continue In Playing :";
			cin >> Choice;

			if (Choice == 'n' || Choice == 'N')
			{
				break;
			}

		}
	}
};

