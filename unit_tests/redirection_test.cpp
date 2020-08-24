#include "gtest/gtest.h"
#include "../header/execute.h"
#include "../header/Token.h"
#include "../header/Tokenizer.h"
#include "../header/execute.h"
#include <iostream>
#include <fstream>
using namespace std;

TEST(Redirection, inputAndOutput)
{
	vector<string> parsedinput {"sort < testingInput > tempTestOuput"} ;
	vector<Token*> newtokenized = tokenize(parsedinput);
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile<< "D\nC\nB\nA";
	testFile.close();
	execute(dynamic_cast<ExeToken*>((newtokenized.at(0))));

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "A");
	EXPECT_EQ(extractedOutput.at(1), "B");
	EXPECT_EQ(extractedOutput.at(2), "C");
	EXPECT_EQ(extractedOutput.at(3), "D");
	
	for (int i = 0; i <newtokenized.size(); ++i)
		{
			delete newtokenized.at(i); 
		}
	newtokenized.clear();
}


TEST(Redirection, inputAndOutputBackwards)
{
	vector<string> parsedinput {"sort > tempTestOuput < testingInput"} ;
	vector<Token*> newtokenized = tokenize(parsedinput);
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile<< "D\nC\nB\nA";
	testFile.close();
	execute(dynamic_cast<ExeToken*>((newtokenized.at(0))));

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "A");
	EXPECT_EQ(extractedOutput.at(1), "B");
	EXPECT_EQ(extractedOutput.at(2), "C");
	EXPECT_EQ(extractedOutput.at(3), "D");
	
	for (int i = 0; i <newtokenized.size(); ++i)
		{
			delete newtokenized.at(i); 
		}
	newtokenized.clear();
}



TEST(Redirection, inputAndAppend)
{
	vector<string> parsedinput {"sort < testingInput >> tempTestOuput"} ;
	vector<Token*> newtokenized = tokenize(parsedinput);
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile<< "D\nC\nB\nA";
	testFile.close();
	execute(dynamic_cast<ExeToken*>((newtokenized.at(0))));

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "A");
	EXPECT_EQ(extractedOutput.at(1), "B");
	EXPECT_EQ(extractedOutput.at(2), "C");
	EXPECT_EQ(extractedOutput.at(3), "D");
	
	for (int i = 0; i <newtokenized.size(); ++i)
		{
			delete newtokenized.at(i); 
		}
	newtokenized.clear();
}


TEST(Redirection, inputAndAppendBackwards)
{
	vector<string> parsedinput {"sort >> tempTestOuput < testingInput"} ;
	vector<Token*> newtokenized = tokenize(parsedinput);
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile<< "D\nC\nB\nA";
	testFile.close();
	execute(dynamic_cast<ExeToken*>((newtokenized.at(0))));

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "A");
	EXPECT_EQ(extractedOutput.at(1), "B");
	EXPECT_EQ(extractedOutput.at(2), "C");
	EXPECT_EQ(extractedOutput.at(3), "D");
	
	for (int i = 0; i <newtokenized.size(); ++i)
		{
			delete newtokenized.at(i); 
		}
	newtokenized.clear();
}
