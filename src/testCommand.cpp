#include "../header/Token.h"
#include "../header/ExeToken.h"
#include "../header/testCommand.h"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
//#include <stdio.h>
#include <unistd.h> 
#include <sys/stat.h> 
using namespace std;

int testCommand(char* command, vector<char*> arguments)
{
	
	int failstatus = -2;
	string testcheck(command);
	string filepath;

	
	//cout << "goes befoe the if" << endl;
	if (testcheck == "test")//use with "test"
	{
		//cout << "goes in test" << endl;

		//cout << "size: " << arguments.size() << endl;
		//cout << "testcheck: " << testcheck << endl;
		//cout << "arg.at(0): [" << arguments.at(0) << "]" << endl;
		//cout << "arg.at(1): [" << arguments.at(1) << "]" << endl;
		//cout << "arg.at(2): [" << arguments.at(2) << "]" << endl;
		
	
		//cout << "goes into one if" << endl;
		if (arguments.size() == 2)
		{
			cout << "(False)" << endl;
			failstatus = -1;
			return failstatus;
		}
		string flagchar = string(arguments.at(1));
		if (arguments.size() < 1)
		{
			cout << "(False)" << endl;
			failstatus = -1;
			return failstatus;
		}
		
		if (arguments.size() > 3 && flagchar != "-d" && flagchar != "-e" 
        && flagchar != "-f")
        {
			//cout << "goes in third if" << endl;
            cout << "(False)" << endl;
            failstatus = -1;
			return failstatus;
        }
		
		string flag = "-e";
		if (flagchar == "-d")
			flag = "-d";
		else if (flagchar == "-f")
			flag = "-f";
		
		string filepath;
		if (arguments.size() == 3)
		{
			filepath = arguments.at(1);
		}
		else
		{
			filepath = arguments.at(2);
		}	
		//cout << "filepath: " << filepath << endl;
	//	cout << "flagchar: " << flagchar << endl;
		//cout << "flag: " << flag << endl;


	


		const char *cfilepath = filepath.c_str();
		
		struct stat buf;
		stat(cfilepath, &buf);
		if (flag == "-f")
		{
			if(S_ISREG(buf.st_mode))
			{
				cout << "(True)" << endl;
				failstatus = 0;
				return failstatus;
			}
			else
			{
				cout << "(False)" << endl;
				failstatus = -1;
				return failstatus;
			}
		}
		else if (flag == "-d")
		{
			if(S_ISDIR(buf.st_mode))
			{
				cout << "(True)" << endl;
				failstatus = 0;
				return failstatus;
			}
			else
			{
				cout << "(False)" << endl;
				failstatus = -1;
				return failstatus;
			}
		}
		else if (flag == "-e")
		{
			if(S_ISREG(buf.st_mode) || S_ISDIR(buf.st_mode))
			{
				cout << "(True)" << endl;
				failstatus = 0;
				return failstatus;
			}
			else
			{
				cout << "(False)" << endl;
				failstatus = -1;
				return failstatus;
			}
		}
	}
	else if (testcheck == "[" )//use with brakets
	{
		//cout << "goes in brackets" << endl;
		string flagchar;
		//cout << "size: " << arguments.size() << endl;
		//cout << "arugument[0]: " << arguments.at(0) << endl;
		if (arguments.size() > 4)
		{
			flagchar = string(arguments.at(1));
		}
		else
		{
			//cout << "goes in else" << endl;
			flagchar = string(arguments.at(0));
		}

		//cout << "flagchar: " << flagchar << endl;

		//cout << "seg check 1" << endl;
		
		//cout << "in bracket if" << endl;
		if (flagchar == "]")//edge case for input "[ ]"
		{
			///cout << "goes in first if" << endl;
			cout << "(False)" << endl;
			failstatus = -1;
			return failstatus;
		}
		else if ((string(arguments.at(arguments.size() - 2)).back()) != ']')//edge case for input "[ ]"
		{
			//cout << "goes in second if" << endl;
			cout << "(False)" << endl;
			failstatus = -1;
			return failstatus;
		}
		
		//cout << "seg check 2" << endl;

		//string flagchar = string(arguments.at(1));

		if (arguments.size() > 4 && flagchar != "-d" && flagchar != "-e" 
        && flagchar != "-f")
        {
			//cout << "goes in third if" << endl;
            cout << "(False)" << endl;
            failstatus = -1;
			return failstatus;
        }
		//cout << "seg check 3" << endl;

		//cout << "flagchar: " << flagchar << endl;
		
		string flag = "-e";
		if (flagchar == "-d")
			flag = "-d";
		else if (flagchar == "-f")
			flag = "-f";
		
		//cout << "seg check 4" << endl;
		//cout << "size: " << arguments.size() << endl;
		//cout << "filepath before: " << filepath << endl;
		if (arguments.size() == 4)
		{
			filepath = arguments.at(1);
		}
		else
		{
			filepath = arguments.at(2);
		}
		//cout << "filepath after: " << filepath << endl;
		//cout << "seg check 5" << endl;
		
		//cout << "filepath: " << filepath << endl;
		//cout << "flag: " << flag << endl;
		//cout << "seg check 4" << endl;

		
		const char *cfilepath = filepath.c_str();
		
		struct stat buf;
		stat(cfilepath, &buf);
		if (flag == "-f")
		{
			if(S_ISREG(buf.st_mode))
			{
				cout << "(True)" << endl;
				failstatus = 0;
				return failstatus;
			}
			else
			{
				cout << "(False)" << endl;
				failstatus = -1;
				return failstatus;
			}
		}
		else if (flag == "-d")
		{
			if(S_ISDIR(buf.st_mode))
			{
				cout << "(True)" << endl;
				failstatus = 0;
				return failstatus;
			}
			else
			{
				cout << "(False)" << endl;
				failstatus = -1;
				return failstatus;
			}
		}
		else if (flag == "-e")
		{
			if(S_ISREG(buf.st_mode) || S_ISDIR(buf.st_mode))
			{
				cout << "(True)" << endl;
				failstatus = 0;
				return failstatus;
			}
			else
			{
				cout << "(False)" << endl;
				failstatus = -1;
				return failstatus;
			}
		}
	}
	
	return failstatus;
}