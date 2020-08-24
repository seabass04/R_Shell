#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/Tree.h"
#include "../header/parser.h"
#include "../header/separate.h"
#include "../header/rshellHelper.h"
#include <stack>
#include <queue> 
#include <vector>
#include <fstream>


TEST(symbolic_Integration_Test, echotest2) {

	vector<Token*> tokendInput;
	string fakeUserInput = "echo hello >> tempTestOutput && [ src ] >> tempTestOutput";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());


	ifstream tempOutputFile("tempTestOutput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOutput";
	remove(outputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "hello");
	EXPECT_EQ(extractedOutput.at(1), "(True)");

	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}


TEST(symbolic_Integration_Test, combinationtest2) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "[ src ] >> tempTestOutput && ([ -d src ] >> tempTestOutput && [ -e src ] >> tempTestOutput) && [ -f src ] >> tempTestOutput";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	vector<string> mirroredShunting = produceShunting(separatedInput);
	
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());


	ifstream tempOutputFile("tempTestOutput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOutput";
	remove(outputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "(True)");
	EXPECT_EQ(extractedOutput.at(1), "(True)");
	EXPECT_EQ(extractedOutput.at(2), "(True)");
	EXPECT_EQ(extractedOutput.at(3), "(False)");
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}

TEST(symbolic_Integration_Test, combinationfailtest2) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "[ fakefile ] >> tempTestOutput && ([ -d src ] >> tempTestOutput && [ -e src ] >> tempTestOutput) && [ -f src ] >> tempTestOutput && [ -d src ] >> tempTestOutput && [ -e src ] >> tempTestOutput";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());

	ifstream tempOutputFile("tempTestOutput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOutput";
	remove(outputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "(False)");
	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}


TEST(symbolic_Integration_Test, allflags2) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "[ -d unit_tests ] >> tempTestOutput; [ -e unit_tests ] >> tempTestOutput; [ -f unit_tests ] >> tempTestOutput; [ unit_tests ] >> tempTestOutput";

    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());

	ifstream tempOutputFile("tempTestOutput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOutput";
	remove(outputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "(True)");
	EXPECT_EQ(extractedOutput.at(1), "(True)");
	EXPECT_EQ(extractedOutput.at(2), "(False)");
	EXPECT_EQ(extractedOutput.at(3), "(True)");
	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}
