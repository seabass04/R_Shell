#include "gtest/gtest.h"
#include "../header/parser.h"
#include "../header/separate.h"

TEST(Parsing, connectorInsideQuotes)
{
string fakeUserInput = "echo hello && echo world || echo \"hello ; there\"";
vector<string> fakeUserInputVec{"echo"," ","hello"," ","&&"," ","echo"," ","world"," ","||"," ","echo"," ","\"hello"," ",";"," ","there\""};
vector<string> delimitedInput = parser(fakeUserInput);
ASSERT_EQ(fakeUserInputVec.size(), delimitedInput.size()) << "Vectors fakeUserInputVec and delimitedInput are of unequal length";
for (int i = 0; i < fakeUserInputVec.size(); ++i)
{
EXPECT_EQ(fakeUserInputVec.at(i), delimitedInput.at(i)) << "Vectors fakeUserInputVec and delimitedInput differ at index " << i;
}
}

TEST(Parsing, semicolonConnector)
{
string fakeUserInput = "echo hello ; echo world || echo \"hello ; there\"";
vector<string> fakeUserInputVec{"echo"," ","hello"," ",";"," ","echo"," ","world"," ","||"," ","echo"," ", "\"hello"," ", ";"," ", "there\""};
vector<string> delimitedInput = parser(fakeUserInput);
ASSERT_EQ(fakeUserInputVec.size(), delimitedInput.size()) << "Vectors fakeUserInputVec and delimitedInput are of unequal length";
for (int i = 0; i < fakeUserInputVec.size(); ++i)
{
EXPECT_EQ(fakeUserInputVec.at(i), delimitedInput.at(i)) << "Vectors fakeUserInputVec and delimitedInput differ at index " << i;
}
}

TEST(Parsing, semicolonConnectorNoSpace)
{
string fakeUserInput = "echo hello; echo world || echo \"hello ; there\"";
vector<string> fakeUserInputVec{"echo"," ","hello;"," ","echo"," ","world"," ","||"," ","echo"," ", "\"hello"," ", ";"," ", "there\""};
vector<string> delimitedInput = parser(fakeUserInput);
ASSERT_EQ(fakeUserInputVec.size(), delimitedInput.size()) << "Vectors fakeUserInputVec and delimitedInput are of unequal length";
for (int i = 0; i < fakeUserInputVec.size(); ++i)
{
EXPECT_EQ(fakeUserInputVec.at(i), delimitedInput.at(i)) << "Vectors fakeUserInputVec and delimitedInput differ at index " << i;
}
}

TEST(Parsing, hasComment)
{
string fakeUserInput = "echo hello; echo world # echo \"hello ; there\"";
vector<string> fakeUserInputVec{"echo"," ","hello;"," ","echo"," ","world"," ","#"," ","echo"," ", "\"hello"," ",";"," ","there\""};
vector<string> delimitedInput = parser(fakeUserInput);
ASSERT_EQ(fakeUserInputVec.size(), delimitedInput.size()) << "Vectors fakeUserInputVec and delimitedInput are of unequal length";
for (int i = 0; i < fakeUserInputVec.size(); ++i)
{
EXPECT_EQ(fakeUserInputVec.at(i), delimitedInput.at(i)) << "Vectors fakeUserInputVec and delimitedInput differ at index " << i;
}
}
TEST(Parsing, hasCommentInQuotes)
{
string fakeUserInput = "echo hello; echo world && echo \"hello # there\"";
vector<string> fakeUserInputVec{"echo"," ","hello;"," ","echo"," ","world"," ","&&"," ","echo"," ","\"hello"," ","#"," ", "there\""};
vector<string> delimitedInput = parser(fakeUserInput);
ASSERT_EQ(fakeUserInputVec.size(), delimitedInput.size()) << "Vectors fakeUserInputVec and delimitedInput are of unequal length";
for (int i = 0; i < fakeUserInputVec.size(); ++i)
{
EXPECT_EQ(fakeUserInputVec.at(i), delimitedInput.at(i)) << "Vectors fakeUserInputVec and delimitedInput differ at index " << i;
}
}
/////////////Testing Separating into Tokens////////////////////

TEST(Separating, connectorInsideQuotes)
{
vector<string> fakeSeparatedVec{"echo hello","&&","echo world","||","echo \"hello ; there\""};
vector<string> fakeParsedVec{"echo"," ","hello"," ","&&"," ","echo"," ","world"," ","||"," ","echo"," ","\"hello"," ",";"," ","there\""};
vector<string> separatedInput = separate(fakeParsedVec);
ASSERT_EQ(fakeSeparatedVec.size(), separatedInput.size()) << "Vectors separatedInput and fakeSeparatedVec are of unequal length";
for (int i = 0; i < fakeSeparatedVec.size(); ++i)
{
EXPECT_EQ(fakeSeparatedVec.at(i), separatedInput.at(i)) << "Vectors separatedInput and fakeSeparatedVec differ at index " << i;
}
}

TEST(Separating, semicolonConnector)
{
vector<string> fakeSeparatedVec{"echo hello ",";","echo world","||","echo \"hello ; there\""};
vector<string> fakeParsedVec{"echo"," ","hello"," ",";"," ","echo"," ","world"," ","||"," ","echo"," ", "\"hello"," ",";"," ", "there\""};
vector<string> separatedInput = separate(fakeParsedVec);
ASSERT_EQ(fakeSeparatedVec.size(), separatedInput.size()) << "Vectors separatedInput and fakeSeparatedVec are of unequal length";
for (int i = 0; i < fakeSeparatedVec.size(); ++i)
{
EXPECT_EQ(fakeSeparatedVec.at(i), separatedInput.at(i)) << "Vectors separatedInput and fakeSeparatedVec differ at index " << i;
}
}

TEST(Separating, semicolonConnectorNoSpace)
{
vector<string> fakeSeparatedVec{"echo hello",";","echo world","||","echo \"hello ; there\""};
vector<string> fakeParsedVec{"echo"," ","hello;"," ","echo"," ","world"," ","||"," ","echo"," ", "\"hello"," ", ";"," ", "there\""};
vector<string> separatedInput = separate(fakeParsedVec);
ASSERT_EQ(fakeSeparatedVec.size(), separatedInput.size()) << "Vectors separatedInput and fakeSeparatedVec are of unequal length";
for (int i = 0; i < fakeSeparatedVec.size(); ++i)
{
EXPECT_EQ(fakeSeparatedVec.at(i), separatedInput.at(i)) << "Vectors separatedInput and fakeSeparatedVec differ at index " << i;
}
}

TEST(Separating, hasComment)
{
vector<string> fakeSeparatedVec{"echo hello",";","echo world"};
vector<string> fakeParsedVec{"echo"," ","hello;"," ","echo"," ","world"," ","#"," ","echo"," ","\"hello"," ", ";"," ", "there\""};
vector<string> separatedInput = separate(fakeParsedVec);
ASSERT_EQ(fakeSeparatedVec.size(), separatedInput.size()) << "Vectors separatedInput and fakeSeparatedVec are of unequal length";
for (int i = 0; i < fakeSeparatedVec.size(); ++i)
{

EXPECT_EQ(fakeSeparatedVec.at(i), separatedInput.at(i)) << "Vectors separatedInput and fakeSeparatedVec differ at index " << i;
}
}
TEST(Separating, hasCommentInQuotes)
{
vector<string> fakeSeparatedVec{"echo hello",";","echo world","&&","echo \"hello # there\""};
vector<string> fakeParsedVec{"echo"," ","hello;"," ","echo"," ","world"," ","&&"," ","echo"," ", "\"hello"," ", "#"," ", "there\""};
vector<string> separatedInput = separate(fakeParsedVec);
ASSERT_EQ(fakeSeparatedVec.size(), separatedInput.size()) << "Vectors separatedInput and fakeSeparatedVec are of unequal length";
for (int i = 0; i < fakeSeparatedVec.size(); ++i)
{

EXPECT_EQ(fakeSeparatedVec.at(i), separatedInput.at(i)) << "Vectors separatedInput and fakeSeparatedVec differ at index " << i;
}
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}