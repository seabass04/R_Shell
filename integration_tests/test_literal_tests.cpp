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
#include <iostream>
#include <fstream>


TEST(literal_Integration_Test, combinationtest) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "test src >> tempTestOutput && (test -d src >> tempTestOutput && test -e src >> tempTestOutput) && test -f src >> tempTestOutput";
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


TEST(literal_Integration_Test, combinationfailtest) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "test fakefile >> tempTestOutput && (test -d src >> tempTestOutput && test -e src >> tempTestOutput) && test -f src >> tempTestOutput && test -d src >> tempTestOutput && test -e src >> tempTestOutput";
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


TEST(literal_Integration_Test, allflags) {

	vector<Token*> tokendInput;
	string fakeUserInput = "test -d unit_tests >> tempTestOutput; test -e unit_tests >> tempTestOutput; test -f unit_tests >> tempTestOutput; test unit_tests >> tempTestOutput";
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


TEST(literal_Integration_Test, echotest) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "echo hello >> tempTestOutput && test src >> tempTestOutput";
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

TEST(literal_Integration_Test, ortest) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "test -f src >> tempTestOutput || echo hello >> tempTestOutput";
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
	EXPECT_EQ(extractedOutput.at(1), "hello");

	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}


