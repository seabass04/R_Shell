#ifndef __CONNTOKEN_H__
#define __CONNTOKEN_H__

#include "Token.h"
#include "ExeToken.h"
using namespace std;


class ConnToken : public Token
{

	protected:
	string connectortype;
	Token* leftChild = nullptr; 
	Token* rightChild = nullptr;
	
  public:
	ConnToken(string input)
	{
		wholetoken = input;
		connectortype = input;
		
	}
	string getWholeToken()
	{
		return wholetoken;
	}
	
	string getType()
	{
		return connectortype;
	}
	
	bool isexe()
	{
		return false;
	}
	
	~ConnToken()
	{
		delete leftChild;
		delete rightChild;
	}


};


#endif
