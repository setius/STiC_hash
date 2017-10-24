

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;


unsigned int SDBMHash(const string& str)
{
	unsigned int hash = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		hash = str[i] + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}

int main()
{
	int x;
	cout << SDBMHash("ty no nie wiem jak tam twoja szmaciura zrogowacia³a niedzwiedzica co sie kurwi pod mostem za wojaka") << endl;
	cout << SDBMHash("ty no nie wiem jak tam twoja szmaciura zrogowacia³a niedziiedzica co sie kurwi pod mostem za wojaka") << endl;
	cout << SDBMHash("tyjaka") << endl;
	cout << SDBMHash("t") << endl;
	cin >> x;
	return 0;
}

