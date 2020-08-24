#ifndef __CMDTOKEN_H__
#define __CMDTOKEN_H__

#include "Token.h"
#include <string>
#include <cstring>

using namespace std;

class ExeToken : public Token
{
	protected:
	string command = "";
	int didExecute = 0;
	//string wholetoken = "";
	string argument = "";
  public:
	ExeToken(string input)
	{
		wholetoken = input;	
		
	}
	
	string getWholeToken()
	{
		return wholetoken;
	}
	
	bool isexe()
	{
		return true;
	}
	
	void setExecution(int status)
	{
		didExecute = status;
	}
	
	char* getCommand()
	{
		if(wholetoken.find(" ") != string::npos)
		{
            if(wholetoken.find('\0') != string::npos)
                wholetoken.erase(wholetoken.find('\0'));


			command = wholetoken.substr(0, wholetoken.find(" "));
			return const_cast<char*>(command.c_str());
		}
        if(wholetoken.find('\0') != string::npos)
            wholetoken.erase(wholetoken.find('\0'));

		return const_cast<char*>(wholetoken.c_str());
	}
	
	
	vector<string> getArgument()
	{
		
		if(wholetoken.find(" ") != string::npos && wholetoken.find("\"") == string::npos )//there's a space and no quotes
		{
            if(wholetoken.find('\0') != string::npos)
                wholetoken.erase(wholetoken.find('\0'));


			argument = wholetoken.substr(wholetoken.find(" ") + 1);


			vector<string> argumentVec;
			string temp = "";
			for(unsigned int i = 0; i < argument.size(); ++i)
            {
			    if(argument.at(i) != ' ')
                {
			        temp+=argument.at(i);
                }
			    else
                {
			        argumentVec.push_back((temp));
			        temp = "";
                }
            }
				if(temp != "\0")
                argumentVec.push_back((temp));

			return argumentVec;


		}
		else if(wholetoken.find("\"") != string::npos ) // there's quotes
        {
            argument = wholetoken.substr(wholetoken.find(" ") + 1);
			string beforeQuote = "";
			for(int i = 0; argument.at(i) != '\"'; ++i)//adds everything before the quotes
			{
				beforeQuote+=argument.at(i);
			}
     
            argument = argument.substr(argument.find("\"")+1); //removes the first quote
			int secondQuotePos = argument.find("\"");
			string betweenQuotes = argument.substr(0, secondQuotePos);
            string afterQuotes = argument.substr(argument.find("\"")+1);
            vector<string> argumentVec;
			
			//cout << "betweenQuotes + afterQuotes " << betweenQuotes+afterQuotes << endl;
			//cout << "betweenQuotes: " << betweenQuotes << endl;
			//cout << "afterQuotes: " << afterQuotes << endl;
            argumentVec.push_back((beforeQuote + betweenQuotes));
			
			string temp = "";
			for(unsigned int i = 0; i < afterQuotes.size(); ++i)
            {
			    if(afterQuotes.at(i) != ' ')
                {
			        temp += afterQuotes.at(i);
                }
			    else
                {
			        argumentVec.push_back((temp));
			        temp = "";
                }
            }
			if(temp != "\0")
				argumentVec.push_back((temp));
			
            return argumentVec;
        }
        else
        {
            vector<string> argumentVec;
            //argumentVec.push_back("\0");
            return argumentVec; //return an empty vector 
        }

	}
	

};


#endif
