#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/Tree.h"
#include "../header/parser.h"
#include "../header/separate.h"
#include "../header/rshellHelper.h"
#include "../header/execute.h"
#include <stack>
#include <queue> 
#include <vector>
#include <iostream>
#include <fstream>

TEST(Pipe_Integration, combinationtest) 
{

   	string fakeUserInput = "cat testingInput | sort >> tempTestOuput && echo hi >> tempTestOuput";

	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();
	
	execute(fakeUserInput);
	
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
	EXPECT_EQ(extractedOutput.at(4), "hi");

}

TEST(Pipe_Integration, combinationtestOR) 
{

   	string fakeUserInput = "cat testingInput | sort >> tempTestOuput || echo hi >> tempTestOuput";

	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();

	execute(fakeUserInput);

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

}

TEST(Pipe_Integration, orWithFakeFile) 
{

   	string fakeUserInput = "cat fakeFile | sort >> tempTestOuput || echo hi >> tempTestOuput";

	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();

	execute(fakeUserInput);

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
	
	if(extractedOutput.size()!=0)
	{
		EXPECT_EQ(extractedOutput.at(0), "A");
		EXPECT_EQ(extractedOutput.at(1), "B");
		EXPECT_EQ(extractedOutput.at(2), "C");
		EXPECT_EQ(extractedOutput.at(3), "D");
	}

}


TEST(Pipe_Integration, andWithFakeFile) 
{

   	string fakeUserInput = "cat fakeFile | sort >> tempTestOuput && echo hi >> tempTestOuput";
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();
	
	execute(fakeUserInput);

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
	
	if(extractedOutput.size()!=0)
	{
		EXPECT_EQ(extractedOutput.at(0), "hi");
	}

}
