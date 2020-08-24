#include <iostream>
#include <string>
#include <unistd.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "../header/rshellHelper.h" 

using namespace std;

vector<string> produceShunting(vector<string> &separatedInput)
{
	
	vector<string> reverseSeparatedInput;
	for(int i = separatedInput.size()-1; i >= 0; --i) //mirror 1
	{
		if(separatedInput.at(i) == "(")
		{
			reverseSeparatedInput.push_back(")");
		}
		else if(separatedInput.at(i) ==")")
		{
			reverseSeparatedInput.push_back("(");
		}
		/*else if(separatedInput.at(i) =="<")//might not work 3/3/20->3:00pm
		{
			cout << " the <" << endl;
			reverseSeparatedInput.push_back(">");
		}
		else if(separatedInput.at(i) ==">")//might not work 3/3/20->3:00pm
		{
			cout << " the >" << endl;
			reverseSeparatedInput.push_back("<");
		}
		else if(separatedInput.at(i) ==">>")//might not work 3/3/20->3:00pm
		{
			cout << " the >>" << endl;
			reverseSeparatedInput.push_back("<<");
		}*/
		else
		{
			reverseSeparatedInput.push_back(separatedInput.at(i));
		}
	}
	
	
	queue<string> inputQueue;
	stack<string> inputStack;
	for(int i = 0; i <  reverseSeparatedInput.size(); ++i) //Shunting
	{																													 //might not work
		if(reverseSeparatedInput.at(i) != "&&" && reverseSeparatedInput.at(i) != "||" && reverseSeparatedInput.at(i) != ";"
		&& reverseSeparatedInput.at(i) != "#" && reverseSeparatedInput.at(i) != "(" && reverseSeparatedInput.at(i) != ")"
		&&  reverseSeparatedInput.at(i) != "|")
		{
			inputQueue.push(reverseSeparatedInput.at(i));
		}
		else if(reverseSeparatedInput.at(i) == "&&" || reverseSeparatedInput.at(i) == "||" 
		|| reverseSeparatedInput.at(i) == ";" || reverseSeparatedInput.at(i) == "|"
		&& reverseSeparatedInput.at(i) != "(" && reverseSeparatedInput.at(i) != ")" )
		{
			
			inputStack.push(reverseSeparatedInput.at(i));
		}	
		else if(reverseSeparatedInput.at(i) == "(")
		{
				inputStack.push(reverseSeparatedInput.at(i));
		}
		else if(reverseSeparatedInput.at(i) == ")")
		{
			while(inputStack.top() != "(")
			{
				inputQueue.push(inputStack.top());
				inputStack.pop();
			}
			if(inputStack.top() == "(")
			{
				inputStack.pop();
			}
		}
	}

	while (!inputStack.empty()) //pushes the remaining connectors to the stack
	{
			inputQueue.push(inputStack.top());
			inputStack.pop();
	}
	
	vector<string> temp;
	while (!inputQueue.empty()) //pops the queue and places the contents into a vector
	{ 
        temp.push_back(inputQueue.front());
        inputQueue.pop(); 
	}
	
	vector<string> secondMirror;
	for(int i = temp.size()-1; i >= 0; --i) //mirror 2
	{
		secondMirror.push_back(temp.at(i));
	}
	
	return secondMirror;
}