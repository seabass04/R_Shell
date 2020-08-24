#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "../header/parser.h"

using namespace std;
using namespace boost;

vector<string> parser(string input)
{
    string userInput = input;
    boost::char_separator<char> sep("", " ()");
    boost::tokenizer<boost::char_separator<char>> tokens(userInput, sep);
    vector<string> delimitedInput;
    int counter = 0;
    int executableCounter = 0;
    for(tokenizer<char_separator<char>>::iterator beg=tokens.begin(); beg!=tokens.end();++beg)
    {
        delimitedInput.push_back(*beg);
    }
    return delimitedInput;
}