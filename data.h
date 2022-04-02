#pragma once
#include <fstream>
using namespace std;

struct dataToSave
{
	int money;
	// Skins
	char skins[8];
	int current_skin;
	// Background skins
	char bg_skins[4];
	int current_bgskin;
	dataToSave(int m = 0, char* s = nullptr, int cs = -1, char* bs = nullptr, int cbs = -1)
	{
		money = m;
		current_skin = cs;
		current_bgskin = cbs;
		if (s != nullptr && bs != nullptr)
		{
			for (int i = 0; i < 8; i++)
			{
				skins[i] = s[i];
			}
			for (int i = 0; i < 4; i++)
			{
				bg_skins[i] = bs[i];
			}
		}
	}
};