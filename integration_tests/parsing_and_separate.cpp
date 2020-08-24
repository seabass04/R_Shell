#include "gtest/gtest.h"
#include "../header/parser.h"
#include "../header/separate.h"

TEST(ParsingWithSeparation, connecterInsideQuotes)
{
    string fakeUserInput = "echo hello && echo world || echo \"hello ; there\"";
    vector<string> fakeSeparatedVec{"echo hello","&&","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
    vector<string> separatedUserInput = separate(parsedUserInput);
    ASSERT_EQ(fakeSeparatedVec.size(), separatedUserInput.size()) << "Vectors separatedUserInput and fakeSeparatedVec are of unequal length";
    for (int i = 0; i < fakeSeparatedVec.size(); ++i)
    {
        EXPECT_EQ(fakeSeparatedVec.at(i), separatedUserInput.at(i)) << "Vectors separatedUserInput and fakeSeparatedVec differ at index " << i;
    }
}


TEST(ParsingWithSeparation, semicolonConnector)
{
    string fakeUserInput = "echo hello ; echo world || echo \"hello ; there\"";
    vector<string> fakeSeparatedVec{"echo hello ",";","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
    vector<string> separatedUserInput = separate(parsedUserInput);
    ASSERT_EQ(fakeSeparatedVec.size(), separatedUserInput.size()) << "Vectors separatedUserInput and fakeSeparatedVec are of unequal length";
    for (int i = 0; i < fakeSeparatedVec.size(); ++i)
    {
        EXPECT_EQ(fakeSeparatedVec.at(i), separatedUserInput.at(i)) << "Vectors separatedUserInput and fakeSeparatedVec differ at index " << i;
    }
}

TEST(ParsingWithSeparation, semicolonConnectorNoSpace)
{
    string fakeUserInput = "echo hello; echo world || echo \"hello ; there\"";
    vector<string> fakeSeparatedVec{"echo hello",";","echo world","||","echo \"hello ; there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
    vector<string> separatedUserInput = separate(parsedUserInput);
    ASSERT_EQ(fakeSeparatedVec.size(), separatedUserInput.size()) << "Vectors separatedUserInput and fakeSeparatedVec are of unequal length";
    for (int i = 0; i < fakeSeparatedVec.size(); ++i)
    {
        EXPECT_EQ(fakeSeparatedVec.at(i), separatedUserInput.at(i)) << "Vectors separatedUserInput and fakeSeparatedVec differ at index " << i;
    }
}

TEST(ParsingWithSeparation, hasComment)
{
    string fakeUserInput = "echo hello; echo world # echo \"hello ; there\"";
    vector<string> fakeSeparatedVec{"echo hello",";","echo world"};
    vector<string> parsedUserInput = parser(fakeUserInput);
    vector<string> separatedUserInput = separate(parsedUserInput);
    ASSERT_EQ(fakeSeparatedVec.size(), separatedUserInput.size()) << "Vectors separatedUserInput and fakeSeparatedVec are of unequal length";
    for (int i = 0; i < fakeSeparatedVec.size(); ++i)
    {
        EXPECT_EQ(fakeSeparatedVec.at(i), separatedUserInput.at(i)) << "Vectors separatedUserInput and fakeSeparatedVec differ at index " << i;
    }
}

TEST(ParsingWithSeparation, hasCommentInQuotes)
{
    string fakeUserInput = "echo hello; echo world || echo \"hello # there\"";
    vector<string> fakeSeparatedVec{"echo hello",";","echo world","||","echo \"hello # there\""};
    vector<string> parsedUserInput = parser(fakeUserInput);
    vector<string> separatedUserInput = separate(parsedUserInput);
    ASSERT_EQ(fakeSeparatedVec.size(), separatedUserInput.size()) << "Vectors separatedUserInput and fakeSeparatedVec are of unequal length";
    for (int i = 0; i < fakeSeparatedVec.size(); ++i)
    {
    EXPECT_EQ(fakeSeparatedVec.at(i), separatedUserInput.at(i)) << "Vectors separatedUserInput and fakeSeparatedVec differ at index " << i;
    }
}