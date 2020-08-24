#include "gtest/gtest.h"
//#include "../header/parser.h"
//#include "../header/separate.h"
#include "../header/Token.h"
#include "../header/Tokenizer.h"


TEST(Tokenizer, mixconnectors)
{	
	vector<string> parsedinput { "echo hello", "&&", "echo world", "||", "ls", ";", "echo spotify"} ;
	vector<Token*> newtokenized = tokenize(parsedinput);
	vector<bool> tokenbools = {true, false, true, false, true, false, true};
	
	
	ASSERT_EQ(newtokenized.size(), tokenbools.size()) << "Vectors newtokenized and tokenbools are of unequal length";
    for (int i = 0; i < newtokenized.size(); ++i)
		{
			EXPECT_EQ(newtokenized.at(i)->isexe(), tokenbools.at(i)) << "Vectors newtokenized and tokenbools differ at index " << i;
		}
	for (int i = 0; i <newtokenized.size(); ++i)
		{
			delete newtokenized.at(i); 
		}
	newtokenized.clear();
}

TEST(Tokenizer, mostsemi)
{	
	vector<string> parsedinput { "ls", ";", "git status", ";", "echo hello", "&&", "echo world"} ;
	vector<Token*> newtokenized = tokenize(parsedinput);
	vector<bool> tokenbools = {true, false, true, false, true, false, true};
	
	
	ASSERT_EQ(newtokenized.size(), tokenbools.size()) << "Vectors newtokenized and tokenbools are of unequal length";
    for (int i = 0; i < newtokenized.size(); ++i)
		{
			EXPECT_EQ(newtokenized.at(i)->isexe(), tokenbools.at(i)) << "Vectors newtokenized and tokenbools differ at index " << i;
		}
		
	for (int i = 0; i <newtokenized.size(); ++i)
		{
			delete newtokenized.at(i); 
		}
	newtokenized.clear();
}


TEST(Tokenizer, mostor)
{	
	vector<string> parsedinput { "echo first", "||", "echo second", "||", "echo third", ";", "echo fourth"} ;
	vector<Token*> newtokenized = tokenize(parsedinput);
	vector<bool> tokenbools = {true, false, true, false, true, false, true};
	
	
	ASSERT_EQ(newtokenized.size(), tokenbools.size()) << "Vectors newtokenized and tokenbools are of unequal length";
    for (int i = 0; i < newtokenized.size(); ++i)
		{
			EXPECT_EQ(newtokenized.at(i)->isexe(), tokenbools.at(i)) << "Vectors newtokenized and tokenbools differ at index " << i;
		}
		
	for (int i = 0; i <newtokenized.size(); ++i)
		{
			delete newtokenized.at(i); 
		}
	newtokenized.clear();
}