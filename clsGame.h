#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsUtill.h"
#include"clsString.h"

using namespace std;

class clsGame
{
private:

	int _NumberOfLevels;
	int _NumberOfSubLevels;

	short _RetruenLastNumberInTheArray(vector<short>& ChickVector)
	{
		short Size = ChickVector.size();

		short LastNumber = ChickVector.at(Size - 1);
		ChickVector.pop_back();

		return LastNumber;
	}

	bool _ChickFromTheNumbersIfAreEquals(vector<short>ChickVector, vector<short> vector2)
	{
		short Size1 = ChickVector.size();
		short Size2 = vector2.size();

		if (vector2.size() == 0)
		{
			return true;
		}

		else
		{
			return ChickVector.at(Size1 - 1) == vector2.at(Size2 - 1);
		}
	}

	bool _EnsureThatTheElementAreEqualInTheMatrix(vector<short>ChickVector)
	{
		bool chick = false;

		if (ChickVector.size() < _NumberOfLevels)
		{
			return false;
		}

		else
		{
			for (short i = 0; i < ChickVector.size(); i++)
			{
				if (ChickVector[0] == ChickVector[i])
				{
					chick = true;
				}

				else
				{
					return false;
				}
			}
			return true;
		}
	}

	vector<vector<short>> _ReplaceElementsPosition(vector<vector<short>>& ContainAllVectors)
	{
		for (short i = 1; i < (clsGame::_NumberOfLevels * 4); i++)
		{
			short Vec1random = clsUtil::RandomNumber(0, clsGame::_NumberOfLevels - 1);
			short ele1Random = clsUtil::RandomNumber(0, clsGame::_NumberOfLevels - 1);
			short Vec2random = clsUtil::RandomNumber(0, clsGame::_NumberOfLevels - 1);
			short ele2Random = clsUtil::RandomNumber(0, clsGame::_NumberOfLevels - 1);

			short temp = ContainAllVectors.at(Vec1random).at(ele1Random);
			ContainAllVectors.at(Vec1random).at(ele1Random) = ContainAllVectors.at(Vec2random).at(ele2Random);
			ContainAllVectors.at(Vec2random).at(ele2Random) = temp;
		}

		return ContainAllVectors;
	}

	vector<string> _LodeTheLevelsNumbersFromFile()
	{
		fstream myFile;
		vector<string>Levels;

		myFile.open("LevelsFile.txt", ios::in);

		if (myFile.is_open())
		{
			string Line;
			while (getline(myFile, Line))
			{
				if (Line == " ")
				{
					break;
				}

				else
				{
					Levels = clsString::Split(Line, "$##$");
				}
			}

			myFile.close();
			return Levels;
		}
	}

public:


	clsGame()
	{
		vector<string>Levels = _LodeTheLevelsNumbersFromFile();
		_NumberOfLevels = stoi(Levels[1]);
		_NumberOfSubLevels = stoi(Levels[0]);
	}

	~clsGame()
	{
		_SaveTheLevelsInTheFile(_NumberOfLevels, _NumberOfSubLevels);
	}

	void SetNumberOfLevels(int NumberOfLevel)
	{
		_NumberOfLevels = NumberOfLevel;
	}

	void SetNumberOfSubLevels(int NumberOfSubLevel)
	{
		_NumberOfSubLevels = NumberOfSubLevel;
	}

	int GetNumberOfLevels()
	{
		return _NumberOfLevels;
	}

	int GetNumberOfSubLevels()
	{
		return _NumberOfSubLevels;
	}

	__declspec(property(get = GetNumberOfLevels, put = SetNumberOfLevels))  int NumberOfLevels;
	__declspec(property(get = GetNumberOfSubLevels, put = SetNumberOfSubLevels)) int NumberOfSubLevels;

	void _SaveTheLevelsInTheFile(int NumberOfLevels1, int NumberOfSubLevels2)
	{
		string Line = to_string(NumberOfSubLevels2) + "$##$" + to_string(NumberOfLevels1);
		fstream myFile;

		myFile.open("LevelsFile.txt", ios::out);

		if (myFile.is_open())
		{
			myFile << Line << endl;
		}

		myFile.close();
	}

	void TransferElemnetFromVector1ToVector2(vector<short>& Vector1, vector<short>& Vector2)
	{
		short SizeOfVector1 = Vector1.size();
		short SizeOfVector2 = Vector2.size();

		for (short leangh = (_NumberOfLevels - SizeOfVector2); leangh > 0; leangh--)
		{
			if (Vector1.size() == 0)
			{
				break;
			}

			else if (_ChickFromTheNumbersIfAreEquals(Vector1, Vector2))
			{
				short Number = _RetruenLastNumberInTheArray(Vector1);
				Vector2.push_back(Number);
			}

		}
	}

	bool ChickIfAllArraysContainEqualsElements(vector<vector<short>>& ContainAllVectors)
	{
		short ChickNumber = 0;

		for (short i = 0; i < ContainAllVectors.size(); i++)
		{
			if (_EnsureThatTheElementAreEqualInTheMatrix(ContainAllVectors[i]))
			{
				ChickNumber++;
			}
		}

		if (ChickNumber == _NumberOfLevels)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	string ReturnNumberOrSpace(vector<short>ChickVector, short index)
	{
		if (ChickVector.size() == 0)
		{
			return " ";
		}

		else if (ChickVector.size() >= index)
		{
			return to_string(ChickVector.at(index - 1));
		}
		else
		{
			return " ";
		}
	}

	vector<vector<short>> FillAllVectorsWithValues()
	{
		vector<vector<short>> ContainAllVectors;
		vector<short> Vec;
		short count = 1;

		for (short i = 1; i <= _NumberOfLevels; i++)
		{
			for (short j = 1; j <= _NumberOfLevels; j++)
			{
				Vec.push_back(count);
			}

			count++;
			ContainAllVectors.push_back(Vec);
			Vec.clear();
		}


		ContainAllVectors.push_back(Vec);
		ContainAllVectors.push_back(Vec);
		ContainAllVectors = _ReplaceElementsPosition(ContainAllVectors);
		return ContainAllVectors;
	}

};

