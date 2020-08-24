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
//

;
TEST(literalTest_integration, combinationtest) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "test src && (test -d src && test -e src) && test -f src";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	
	vector<string> mirroredShunting = produceShunting(separatedInput);
			
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());

	testing::internal::CaptureStdout();
	
	executiontree->treeTraverse(executiontree->getRoot());
	
	std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(True)\n(True)\n(True)\n");
	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}


TEST(literalTest_integration, combinationfailtest) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "test fakefile && (test -d src && test -e src) && test -f src && test -d src && test -e src";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	
	vector<string> mirroredShunting = produceShunting(separatedInput);
			
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());

	testing::internal::CaptureStdout();
	
	executiontree->treeTraverse(executiontree->getRoot());
	
	std::string output = testing::internal::GetCapturedStdout();
   // EXPECT_EQ(output, "(True)\n(True)\n(True)\n");
    EXPECT_EQ(output, "(False)\n");

	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}


TEST(literalTest_integration, allflags) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "test -d unit_tests; test -e unit_tests; test -f unit_tests; test unit_tests";

    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());

	testing::internal::CaptureStdout();
	
	executiontree->treeTraverse(executiontree->getRoot());
	
	std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(True)\n(True)\n(False)\n(True)\n");
	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}


TEST(literalTest_integration, echotest) {

	vector<Token*> tokendInput;
   	string fakeUserInput = "echo hello && test src";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	
	vector<string> mirroredShunting = produceShunting(separatedInput);
			
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	
	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());

	testing::internal::CaptureStdout();
	
	executiontree->treeTraverse(executiontree->getRoot());
	
	std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "hello\n(True)\n");
	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}

