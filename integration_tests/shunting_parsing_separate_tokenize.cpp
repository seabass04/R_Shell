#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/parser.h"
#include "../header/separate.h"
#include "../header/rshellHelper.h"


TEST(ParsingWithSeparationAndShuntingAndTokenize, connecterInsideQuotes)
{
	string fakeUserInput = "echo hello && echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello","&&","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	vector<string> shuntedVec = produceShunting(separatedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (shuntedVec);
	vector<bool> faketokenbools = {false, false, true, true, true};
	
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


TEST(ParsingWithSeparationAndShuntingAndTokenize, semicolonConnector)
{
	string fakeUserInput = "echo hello ; echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello ",";","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	vector<string> shuntedVec = produceShunting(separatedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (shuntedVec);
	vector<bool> faketokenbools = {false, false, true, true, true};

	
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

TEST(ParsingWithSeparationAndShuntingAndTokenize, semicolonConnectorNoSpace)
{
	string fakeUserInput = "echo hello; echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello",";","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	vector<string> shuntedVec = produceShunting(separatedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (shuntedVec);
	vector<bool> faketokenbools = {false, false, true, true, true};

	
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

TEST(ParsingWithSeparationAndShuntingAndTokenize, Parenthesis)
{
	string fakeUserInput = "echo hi && (echo bye && echo see yuh) && echo test";
	vector<string> fakeSeparatedVec{"echo hi","&&", "(","echo bye","&&","echo see yuh", ")", "&&", "echo test"};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	vector<string> shuntedVec = produceShunting(separatedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (shuntedVec);
	vector<bool> faketokenbools = {false, false, true, false, true, true, true};

	
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

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

TEST(ParsingWithSeparationAndShuntingAndTokenize, checkingTokenValues)
{
	string fakeUserInput = "echo hello && echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello","&&","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	vector<string> shuntedVec = produceShunting(separatedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (shuntedVec);
	vector<string> faketokenValues = {"||", "&&", "echo hello", "echo world", "echo \"hello ; there\""};
	
	ASSERT_EQ(tokenizedinput.size(), faketokenValues.size()) << "Vectors tokenizedinput and faketokenValues are of unequal length";
    for (int i = 0; i < tokenizedinput.size(); ++i)
		{
			EXPECT_EQ(tokenizedinput.at(i)->getWholeToken(), faketokenValues.at(i)) << "Vectors tokenizedinput and faketokenValues differ at index " << i;
		}
		
	for (int i = 0; i <tokenizedinput.size(); ++i)
		{
			delete tokenizedinput.at(i); 
		}
	tokenizedinput.clear();
}

TEST(ParsingWithSeparationAndShuntingAndTokenize, checkingTokenValues2)
{
	
	string fakeUserInput = "echo hello ; echo world || echo \"hello ; there\"";
	vector<string> fakeSeparatedVec{"echo hello ",";","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	vector<string> shuntedVec = produceShunting(separatedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (shuntedVec);
	vector<string> faketokenValues = {"||", ";", "echo hello ", "echo world", "echo \"hello ; there\""};

	
	ASSERT_EQ(tokenizedinput.size(), faketokenValues.size()) << "Vectors tokenizedinput and faketokenValues are of unequal length";
    for (int i = 0; i < tokenizedinput.size(); ++i)
		{
			EXPECT_EQ(tokenizedinput.at(i)->getWholeToken(), faketokenValues.at(i)) << "Vectors tokenizedinput and faketokenValues differ at index " << i;
		}
	
	for (int i = 0; i <tokenizedinput.size(); ++i)
		{
			delete tokenizedinput.at(i); 
		}
	tokenizedinput.clear();
}

TEST(ParsingWithSeparationAndShuntingAndTokenize, checkingTokenValues3)
{
	
	string fakeUserInput = "echo hi && (echo bye && echo see yuh) && echo test";
	vector<string> fakeSeparatedVec{"echo hi","&&", "(","echo bye","&&","echo see yuh", ")", "&&", "echo test"};
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedUserInput = separate(parsedUserInput);
	vector<string> shuntedVec = produceShunting(separatedUserInput);
	
	vector<Token*> tokenizedinput = tokenize (shuntedVec);
	vector<string> faketokenValues = {"&&", "&&", "echo hi", "&&", "echo bye", "echo see yuh ", "echo test"};

	ASSERT_EQ(tokenizedinput.size(), faketokenValues.size()) << "Vectors tokenizedinput and faketokenValues are of unequal length";
    for (int i = 0; i < tokenizedinput.size(); ++i)
		{
			EXPECT_EQ(tokenizedinput.at(i)->getWholeToken(), faketokenValues.at(i)) << "Vectors tokenizedinput and faketokenValues differ at index " << i;
		}
	
	for (int i = 0; i <tokenizedinput.size(); ++i)
		{
			delete tokenizedinput.at(i); 
		}
	tokenizedinput.clear();
}