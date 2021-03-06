#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <windows.h> 
#include "City.h"

using namespace std;

class Session;
class ConsoleFormat
{

	static HANDLE hConsole;


public:

	const enum color {
		black = 0,
		dblue = 1,
		dgreen = 2,
		dteal = 3,
		dred = 4,
		purple = 5,
		brown = 6,
		lgrey = 7,
		mgrey = 8,
		blue = 9,
		green = 10,
		teal = 11,
		red = 12,
		pink = 13,
		yellow = 14,
		white = 15
	};

	const enum boxStatus {
		player = 0,
		region = 1
	};

	ConsoleFormat();
	~ConsoleFormat();
	static int printWall();
	static void printLine();
	static int makeBox(int length, string sentence, string data, int maxDataSize);
	static int makeBox(int length, string data);
	static int blockColor(City * city, int division);
	static void setColor(int region);
	static int printLineOfText(string text);
	static int printMultipleColorBoxWithData(int boxLength, int numberOfDiseases, vector<string>* data, int playerOrRegion);
	static int printSeparation(int separation);
	static void setColor(int background, int color);
	static void printRightWall(int numberOfCharsUsedInLine);
	static string emptySpaces(int spaces);
	static int printEmptyLineWall();
};

