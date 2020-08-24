#include "gtest/gtest.h"
#include "../header/testCommand.h"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>


TEST(literalTest, DFlag) {
	string temparg = "test";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "test";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "-d";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "src";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(True)\n");
}

TEST(literalTest, FFlag) {
	string temparg = "test";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "test";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "-f";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "src";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(False)\n");
}

TEST(literalTest, EFlag) {
	string temparg = "test";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "test";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "-e";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "src";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(True)\n");
}

TEST(literalTest, NoFlag) {
    string temparg = "test";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "test";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg4 = "src";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(True)\n");
}

TEST(literalTest, NoFlag2) {
	string temparg = "test";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "test";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg4 = "Shell_project";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(False)\n");
}
///////////////////////
////SYMBOLIC TESTS////
/////////////////////

TEST(SybolicTest, DFlag) {
	string temparg = "[";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg1 = "[";
	charVec.emplace_back(const_cast<char*>(temparg1.c_str()));
	string temparg2 = "-d";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "src";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "]";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(True)\n");
}

TEST(SybolicTest, FFlag) {
	string temparg = "[";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg1 = "[";
	charVec.emplace_back(const_cast<char*>(temparg1.c_str()));
	string temparg2 = "-f";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "prototype";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "]";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(False)\n");
}

TEST(SybolicTest, EFlag) {
    string temparg = "[";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg1 = "[";
	charVec.emplace_back(const_cast<char*>(temparg1.c_str()));
	string temparg2 = "-e";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "header";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "]";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	
	EXPECT_EQ(strCout.str(), "(True)\n");
}

TEST(SybolicTest, NoFlag) {
    string temparg = "[";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "[";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "integration_tests";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "]";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	string temparg5 = "\0";
	charVec.emplace_back(const_cast<char*>(temparg5.c_str()));
	//charVec.emplace_back(const_cast<char*>(temparg5.c_str()));
	//cout << "charvec size: " << charVec.size() << endl;
	//charVec.emplace_back('\0');
	//charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	EXPECT_EQ(strCout.str(), "(True)\n");
}

TEST(SybolicTest, NoFlag2) {
	string temparg = "[";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "[";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "Shell_project";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "]";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	EXPECT_EQ(strCout.str(), "(False)\n");
}

TEST(SybolicTest, WrongFlag) {
  //  ExeToken* testtoken = new ExeToken("[ test header ]");
  	string temparg = "[";
	char* argv[1];
    argv[0] = const_cast<char*>(temparg.c_str());

	vector<char*> charVec;
	string temparg2 = "[";
	charVec.emplace_back(const_cast<char*>(temparg2.c_str()));
	string temparg3 = "test";
	charVec.emplace_back(const_cast<char*>(temparg3.c_str()));
	string temparg4 = "header";
	charVec.emplace_back(const_cast<char*>(temparg4.c_str()));
	string temparg5 = "]";
	charVec.emplace_back(const_cast<char*>(temparg5.c_str()));
	charVec.emplace_back(nullptr);
	
	streambuf* oldCoutStreamBuf = cout.rdbuf();
	ostringstream strCout;
	cout.rdbuf( strCout.rdbuf() );
	
	testCommand(argv[0], charVec);
	
	cout.rdbuf( oldCoutStreamBuf );
	EXPECT_EQ(strCout.str(), "(False)\n");
}












