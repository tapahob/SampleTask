#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "myString.h"

using namespace std;

bool comparer(myString, myString);

void main()
{
	vector<myString> vect;

	myString str1, str2, str3, str4, str5;

	str2 = "hello";
	str1 = "world";
	str3 = "test";
	str4 = "abc";
	str5 = str4 + str2 + str1;

	vect.push_back(str1);
	vect.push_back(str2);
	vect.push_back(str3);
	vect.push_back(str4);
	vect.push_back(str5);

	sort(vect.begin(), vect.end(), comparer);

	for(auto it = vect.begin(); it != vect.end(); it++)
	{
		printf("%s\n", *it);
	}

	getchar();
}

bool comparer(myString str1, myString str2)
{
	auto res = strcmp(str1.cStr(), str2.cStr());
	return res < 0 ? true : false;
}