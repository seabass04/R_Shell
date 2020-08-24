#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Token
{
	protected:
	string wholetoken = "";
	int lhsDidExecute = -1;
  
  public:
	Token() {}
	

	virtual bool isexe() = 0;
	
	void setLeftStatus(int status)
	{
		lhsDidExecute = status;
	}
	
	
	int getLHS()
	{
		return lhsDidExecute;
	}
	
	string getWholeToken()
	{
		return wholetoken;
	}


	
	

};
#endif
