// largestSubstring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include<iostream>
#include<cstring>
using namespace std;

// find the largest substring
string find_largest_Substring(string s){

	string largeString,tempString;
	tempString=s[0];
	int pos;
	for (unsigned int i=1;i<s.length();i++)
	{
		//check if the character is unique 
		pos=tempString.find(s[i]);
		if (pos>=0 )
		{
			if (largeString.length()<tempString.length())
			{
				largeString=tempString;
			}
			tempString =tempString .substr (pos+1,tempString .length() );
		}
		tempString +=s[i];		
	}
	if (tempString.length()==s.length () || tempString.length()>largeString.length())
	{
		return tempString;
	}
	else{
		return largeString ;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	s="parma pizzav";
	cout <<"the string is '"<<s<< "' the largest substring  is '"<< find_largest_Substring(s)<<"'"<<endl;
	s="abcdefg hijk lmnopqrstuvwxyzadgc";
	cout <<"the string is '"<<s<< "' the largest substring  is '"<< find_largest_Substring(s)<<"'"<<endl;
	s="abcdefg hijklmnopqrstuvwxyz";
	cout <<"the string is '"<<s<< "' the largest substring  is '"<< find_largest_Substring(s)<<"'"<<endl;
	return 0;
}

