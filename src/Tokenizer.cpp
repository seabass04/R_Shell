#include "../header/Token.h"
#include "../header/ExeToken.h"
#include "../header/ConnToken.h"
#include <vector>
using namespace std;

vector<Token*> tokenize (vector<string> &wholetokens)
{
	
	vector<Token*> tokenized;
	
	for (unsigned i = 0; i < wholetokens.size(); ++i)//throws all the tokens in 
	{
		
		if (wholetokens.at(i)  == "&&")
		{
			ConnToken* AND = new ConnToken("&&");
			tokenized.push_back(AND);
		}
		else if (wholetokens.at(i) == "||")
		{
			
			ConnToken* OR = new ConnToken("||");
			tokenized.push_back(OR);
		}
		else if (wholetokens.at(i) == ";")
		{

			ConnToken* SEMI = new ConnToken(";");
			tokenized.push_back(SEMI);
		}
		else if (wholetokens.at(i) == "(")
		{

			ConnToken* LeftParenth = new ConnToken("(");
			tokenized.push_back(LeftParenth);
		}
		else if (wholetokens.at(i) == ")")
		{
			
			ConnToken* RightParenth = new ConnToken(")");
			tokenized.push_back(RightParenth);
		}
		else if (wholetokens.at(i) == "|")
		{
			
			ConnToken* pipe = new ConnToken("|");
			tokenized.push_back(pipe);
		}
		else
		{
			
			ExeToken* exe = new ExeToken(wholetokens.at(i));
			tokenized.push_back(exe);
		}
		

   }

	return tokenized;

};
