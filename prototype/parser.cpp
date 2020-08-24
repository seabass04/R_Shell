#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>
#include <vector> 


using namespace std;
using namespace boost;

int main()
{
	cout << "Type in a command. (This isn't actually going to work. This is just testing the parser)" << endl;
	string userInput;
	getline(cin, userInput);
	boost::char_separator<char> sep(" ;", "");
	boost::tokenizer<boost::char_separator<char>> tokens(userInput, sep);
	vector<string> executables;
	vector<string> argumentList;
	vector<string> connectorList;
	int counter = 0;
	int executableCounter = 0;
	for(tokenizer<char_separator<char>>::iterator beg=tokens.begin(); beg!=tokens.end();++beg)
	{
			//cout << *beg << "\n";
			if((*beg == "&&") || (*beg == "||") )
			{
				counter = 0;
				executableCounter = 0;
				connectorList.push_back(*beg);
			}
			else if(counter == 0 && executableCounter !=1)
			{
				executables.push_back(*beg);
				executableCounter = 1;
			}
			else
			{
				argumentList.push_back(*beg);
			}
	}
	cout << "Executable Count: " << executables.size()<< endl;
	cout << "Argument Count: " << argumentList.size()<< endl;
	cout << "Connector Count: " << connectorList.size()<< endl;
	return 0;
}