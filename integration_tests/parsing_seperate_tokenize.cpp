#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/parser.h"
#include "../header/separate.h"



TEST(ParsingWithSeparationAndTokenize, connecterInsideQuotes)
{
	string fakeUserInput = "echo hello && echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello","&&","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (separatedUserInput);
	vector<bool> faketokenbools = {true, false, true, false, true};
	
	ASSERT_EQ(tokenizedinput.size(), faketokenbools.size()) << "Vectors tokenizedinput and faketokenbools are of unequal length";
    for (int i = 0; i < tokenizedinput.size(); ++i)
		{
			EXPECT_EQ(tokenizedinput.at(i)->isexe(), faketokenbools.at(i)) << "Vectors tokenizedinput and faketokenbools differ at index " << i;
		}
		
	for (int i = 0; i <tokenizedinput.size(); ++i)
		{
			delete tokenizedinput.at(i); 
		}
	tokenizedinput.clear();
}


TEST(ParsingWithSeparationAndTokenize, semicolonConnector)
{
	string fakeUserInput = "echo hello ; echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello ",";","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (separatedUserInput);
	vector<bool> faketokenbools = {true, false, true, false, true};

	
	ASSERT_EQ(tokenizedinput.size(), faketokenbools.size()) << "Vectors tokenizedinput and faketokenbools are of unequal length";
    for (int i = 0; i < tokenizedinput.size(); ++i)
		{
			EXPECT_EQ(tokenizedinput.at(i)->isexe(), faketokenbools.at(i)) << "Vectors tokenizedinput and faketokenbools differ at index " << i;
		}
	
	for (int i = 0; i <tokenizedinput.size(); ++i)
		{
			delete tokenizedinput.at(i); 
		}
	tokenizedinput.clear();
}

TEST(ParsingWithSeparationAndTokenize, semicolonConnectorNoSpace)
{
	string fakeUserInput = "echo hello; echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello",";","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (separatedUserInput);
	vector<bool> faketokenbools = {true, false, true, false, true};

	
	ASSERT_EQ(tokenizedinput.size(), faketokenbools.size()) << "Vectors tokenizedinput and faketokenbools are of unequal length";
    for (int i = 0; i < tokenizedinput.size(); ++i)
		{
			EXPECT_EQ(tokenizedinput.at(i)->isexe(), faketokenbools.at(i)) << "Vectors tokenizedinput and faketokenbools differ at index " << i;
		}
	
	for (int i = 0; i <tokenizedinput.size(); ++i)
		{
			delete tokenizedinput.at(i); 
		}
	tokenizedinput.clear();
}
