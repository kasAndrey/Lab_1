#pragma once
#include <iostream>
#include <fstream>
#include "Class.h"

using namespace std;

void completion(List& list, int count)
{
	ifstream in("input.txt");
	ifstream in2("input2.txt");
	char tmp = NULL;
	in.unsetf(ios::skipws);
	in2.unsetf(ios::skipws);
	string data;
	if (count == 1)
	{
		while (!in.eof())
		{
			in >> tmp;
			while (tmp != '\n')
			{
				data += tmp;
				in >> tmp;
				if (in.eof()) break;
			}
			list.push_front(data);
			data = "";
		}
	}
	else
	{
		while (!in2.eof())
		{
			in2 >> tmp;
			while (tmp != '\n')
			{
				data += tmp;
				in2 >> tmp;
				if (in2.eof()) break;
			}
			list.push_front(data);
			data = "";
		}
	}
}
