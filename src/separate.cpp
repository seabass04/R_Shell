#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../header/separate.h"
using namespace std;


int countQuotes(string s)
{
    int count = 0;
    for (unsigned int i=0 ; i <s.length(); ++i)
    {
        if (s.at(i) == '\"')
            count++;

    }
    return count;
}
vector<string> separate(vector<string> &input)
{
    string singleToken = "";
    int quoteCount = 0;
    bool encountered = false;
    bool semicolon = false;
    bool hasComment = false;
    vector<string> tokenStringVec;
    for(unsigned int i = 0; i < input.size(); ++i)
    {
        quoteCount += countQuotes(input.at(i));
        string temp = input.at(i);
		if(temp.at(0) == '(' && quoteCount != 1 && hasComment == false)
		{
			tokenStringVec.push_back("(");
			singleToken +=  temp.substr(temp.find("(") + 1);
			singleToken +=  " ";
		}
		else if(temp.at(temp.size()-1) == ')' && quoteCount != 1 && hasComment == false)
		{
            singleToken +=  input.at(i);
            singleToken.pop_back();
			singleToken +=  " ";
			tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back(")");
            singleToken = "";
		}
		else if(temp.at(0) == '[' && quoteCount != 1 && hasComment == false)///////
		{
			singleToken +=  temp.at(0);
			singleToken +=  " ";
		}
		else if(temp.at(temp.size()-1) == ']' && quoteCount != 1 && hasComment == false)///////////
		{
			singleToken +=  temp.at(0);
			singleToken +=  " ";
			//tokenStringVec.push_back(singleToken);
		
            //singleToken = "";
		}
        else if(temp.at(temp.size()-1) == ';' && quoteCount != 1 && hasComment == false)
        {
            singleToken +=  input.at(i);
            singleToken.pop_back();
            singleToken +=  " ";
            tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back(";");
            singleToken = "";

        }
        else if(input.at(i).at(0) == '#' && quoteCount != 1  && quoteCount != 2)
        {
            tokenStringVec.push_back(singleToken);
            singleToken = "";
            hasComment = true;
        }
        else if(quoteCount == 1 && hasComment == false)
        {
            singleToken +=  input.at(i);
        }
        else if(quoteCount == 2 && hasComment == false)
        {
            singleToken +=  input.at(i);
            quoteCount = 0;
        }
        else if(input.at(i) != "&&" && input.at(i) != "||" && input.at(i) != ";" && input.at(i) != "#" 
		&& input.at(i) != "|" && hasComment == false && input.at(i) != "(" && input.at(i) != ")")
        {
            if(input.at(i) != " ")
                singleToken +=  input.at(i) + " "	;
        }
        else if(input.at(i) == "&&" && hasComment == false)
        {
            tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back("&&");
            singleToken = "";
        }
        else if(input.at(i) == "||" && hasComment == false)
        {
            //cout << "in the separate for {||}" << endl;
			tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back("||");
            singleToken = "";
        }
		else if(input.at(i) == "|" && hasComment == false)
        {
			//cout << "in the separate for {|}" << endl;
			tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back("|");
            singleToken = "";
        }
        else if(input.at(i) == ";" && hasComment == false)
        {
            tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back(";");
            singleToken = "";
        }
		else if(input.at(i) == "(" && hasComment == false)
        {
            tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back("(");
            singleToken = "";
        }
		else if(input.at(i) == ")" && hasComment == false)
        {
            tokenStringVec.push_back(singleToken);
            tokenStringVec.push_back(")");
            singleToken = "";
        }


    }
    tokenStringVec.push_back(singleToken);

    for(unsigned int i = 0; i < tokenStringVec.size(); ++i) //loop to remove last extra space
    {
        if(tokenStringVec.at(i) != "&&" && tokenStringVec.at(i) != ";" && tokenStringVec.at(i) != "(" && tokenStringVec.at(i) != ")" && tokenStringVec.at(i) != "|" && tokenStringVec.at(i) != "||")
        {
            if(tokenStringVec.at(i).size() != 0)
            {
				
                string lastCharacterHelper = tokenStringVec.at(i);
				//cout << "the character inside the for loop is: " << tokenStringVec.at(i) << endl;
                if(lastCharacterHelper.at(lastCharacterHelper.size()-1) != '\"')
                {
                    string tempString = tokenStringVec.at(i);
                    tempString.pop_back();
                    tokenStringVec.at(i) = tempString;
                }
				if(lastCharacterHelper.at(0) == ' ')
				{
					 tokenStringVec.at(i) = tokenStringVec.at(i).substr(tokenStringVec.at(i).find(" ")+1);
				}

            }
        }
    }



    vector<string> tempVec;
    for(unsigned int i = 0; i < tokenStringVec.size(); ++i) //loop to remove empty's
    {
        if(tokenStringVec.at(i) != "")
        {
            tempVec.push_back(tokenStringVec.at(i));
        }
    }

    tokenStringVec = tempVec;

    return tokenStringVec;
}