#pragma once

#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>

using namespace std;

class clsUtil
{
public:

	static string EncryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text; // Ucggf
	}

	static string DecryptionText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);

		}

		return Text;
	}

	static int RandomNumber(int From, int To)
	{

		int RandNum = rand() % (To - From + 1) + From;

		return RandNum;
	}

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	enum enCharTayp { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

	static char GetRandomCharacter(enCharTayp CharType)
	{
		switch (CharType)
		{
		case enCharTayp::SmallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharTayp::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharTayp::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharTayp::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		}
	}

	static string GenerateWord(enCharTayp CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey()
	{
		string Key = "";
		Key = GenerateWord(enCharTayp::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharTayp::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharTayp::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharTayp::CapitalLetter, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Kay [" << i << "] : " << GenerateKey() << endl;
		}
	}

	static int TimeRepeated(int Number, int arr[100], int arrLength)
	{
		int Count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
				Count++;
		}
		return Count;
	}

	static int MaxNumberInArray(int arr[100], int arrLength)
	{
		int Max = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}
		return Max;
	}

	static int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = 0;
		Min = arr[0];
		for (int i = 1; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}

	static int SumArray(int arr[100], int arrLength)
	{
		int Sum = 0;
		for (int i = 1; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithKeys(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey();
		}
	}

	static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i;
		}
		return -1;
	}

	static bool IsPalindromeArray(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] != arr[Length - i - 1])
			{
				return false;
			}
		}
		return true;
	}

	static void Swap(int& a, int& b)
	{
		int c;
		c = a;
		a = b;
		b = a;
	}

	static void Swap(float& num1, float& num2)
	{
		float temp;

		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void Swap(string& st1, string& st2)
	{
		string temp;

		temp = st1;
		st1 = st2;
		st2 = temp;
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return ";";
		}

		if (Number >= 1 && Number <= 19) {
			string arr[] = { "",
		   "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		   "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}

		else
		{
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}

	}

};





