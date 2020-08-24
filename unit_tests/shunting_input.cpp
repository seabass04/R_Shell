#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/parser.h"
#include "../header/separate.h"
#include "../header/rshellHelper.h"
#include <vector>

TEST(Shunting, connecterInsideQuotes)
{
	vector<string> fakeSeparatedVec{"echo hello","&&","echo world","||","echo \"hello ; there\""};
	vector<string> shuntedVec = produceShunting(fakeSeparatedVec);
	vector<string> fakeShuntedVec = {"||", "&&", "echo hello", "echo world", "echo \"hello ; there\""};
	
	ASSERT_EQ(fakeShuntedVec.size(), shuntedVec.size()) << "Vectors shuntedVec and fakeShuntedVec are of unequal length";
    for (int i = 0; i < shuntedVec.size(); ++i)
		{
			EXPECT_EQ(shuntedVec.at(i), fakeShuntedVec.at(i)) << "Vectors shuntedVec and fakeShuntedVec differ at index " << i;
		}
		
}

TEST(Shunting, semicolonConnector)
{
	vector<string> fakeSeparatedVec{"echo hello ",";","echo world","||","echo \"hello ; there\""};
	vector<string> shuntedVec = produceShunting(fakeSeparatedVec);
	vector<string> fakeShuntedVec = {"||", ";", "echo hello ", "echo world", "echo \"hello ; there\""};
	
	ASSERT_EQ(fakeShuntedVec.size(), shuntedVec.size()) << "Vectors shuntedVec and fakeShuntedVec are of unequal length";
    for (int i = 0; i < shuntedVec.size(); ++i)
		{
			EXPECT_EQ(shuntedVec.at(i), fakeShuntedVec.at(i)) << "Vectors shuntedVec and fakeShuntedVec differ at index " << i;
		}
		
}

TEST(Shunting, parenthesis)
{
	vector<string> fakeSeparatedVec{"echo hi","&&", "(","echo bye","&&","echo see yuh", ")", "&&", "echo test"};
	vector<string> shuntedVec = produceShunting(fakeSeparatedVec);
	vector<string> fakeShuntedVec = {"&&", "&&", "echo hi", "&&", "echo bye", "echo see yuh", "echo test"};
	
	ASSERT_EQ(fakeShuntedVec.size(), shuntedVec.size()) << "Vectors shuntedVec and fakeShuntedVec are of unequal length";
    for (int i = 0; i < shuntedVec.size(); ++i)
		{
			EXPECT_EQ(shuntedVec.at(i), fakeShuntedVec.at(i)) << "Vectors shuntedVec and fakeShuntedVec differ at index " << i;
		}
		
}