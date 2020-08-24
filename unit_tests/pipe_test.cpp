#include "gtest/gtest.h"
#include "../header/execute.h"
#include "../header/Token.h"
#include "../header/Tokenizer.h"
#include "../header/execute.h"
#include <iostream>
#include <fstream>
using namespace std;

TEST(Pipes, inputAndOutput)
{
	//ExeToken* leftToken = new ExeToken("cat testingInput");
	//ExeToken* rightToken = new ExeToken("sort > tempTestOuput");
	string testInput = "cat testingInput | sort > tempTestOuput";
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();
	execute(testInput);//executes for pipes

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
	
	//delete leftToken;
	//delete rightToken;
}


TEST(Pipes, inputAndOutputAppend)
{
	//ExeToken* leftToken = new ExeToken("cat testingInput");
	//ExeToken* rightToken = new ExeToken("sort >> tempTestOuput");
	string testInput = "cat testingInput | sort >> tempTestOuput";
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();
	execute(testInput); //execute for pipes

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
	
	//delete leftToken;
	//delete rightToken;
}