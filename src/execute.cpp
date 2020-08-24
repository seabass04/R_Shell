#include "../header/Token.h"
#include "../header/ExeToken.h"
#include "../header/testCommand.h"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h> 
#include <assert.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cassert>
#include <cstdio>



using namespace std;


int execute(ExeToken* token)
{
	pid_t pid;
	int status;
	int failstatus = 0;
    char* argv[1];
    argv[0] = token->getCommand();
    vector<string> arguments = (token->getArgument());
    vector<char*> charVec;
    charVec.emplace_back(argv[0]);
	if(strcmp(*argv,"exit") == 0)
		exit(0);
	
	bool hasInputRedirect = false;
	bool hasOutputRedirectAppend = false;
	bool hasOutputRedirectOverite = false;
	int inputfileDescriptor = STDIN_FILENO;
	int outputfileDescriptor = 1;
	bool inputSet = false;
	bool outputSet = false;
	for(int i = 0; i < arguments.size(); ++i)
	{
		if (arguments.at(i) == "<")
		{
			if(inputSet == true)
				close(inputfileDescriptor);
			inputfileDescriptor = open(arguments.at(i+1).c_str(),  O_RDONLY, 0777);
			inputSet = true;
		}	
		else if (arguments.at(i) == ">")
		{
			if(outputSet == true)
				close(outputfileDescriptor);
			outputfileDescriptor = open(arguments.at(i+1).c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0777); 
			outputSet = true;
		}
		else if (arguments.at(i) == ">>")
		{
			if(outputSet == true)
				close(outputfileDescriptor);
			outputfileDescriptor = open(arguments.at(i+1).c_str(), O_WRONLY | O_APPEND | O_CREAT, 0777);
			outputSet = true;
		}
	}


	if( inputfileDescriptor == -1 ) 
	{
        cerr <<"Error with dup or dup2" << endl;
		return -1;
    }
	if( outputfileDescriptor == -1 ) 
	{
        cerr <<"Error with dup or dup2" << endl;
		return -1;
    }
	
	
    for (auto const& argument : arguments)
	{
		if(argument != "<" && argument != ">" && argument != ">>")//just added this line 3/4/2020 5:09pm
			charVec.emplace_back(const_cast<char*>(argument.c_str()));
		else
			break;
	}
    charVec.push_back(nullptr);

	

	pid = fork();	///////////////////////////////////////FORK////////////////////////////////////////////////////////////////////////////////


	if (pid == 0)//child
	{

		if(outputfileDescriptor != 1)
		{
			dup2(outputfileDescriptor, STDOUT_FILENO); //works for multiple
		}
		if(inputfileDescriptor != 0)
		{
			dup2(inputfileDescriptor, STDIN_FILENO); //works for multiple
		}
	
		int commandstatus = testCommand(argv[0], charVec);
		
		if (commandstatus == 0)
		{
			exit(0);
		}
		else if (commandstatus == -1)
		{
			exit(1);
		}
	
		if(execvp(*argv,charVec.data()) == -1)
		{
			perror("Invalid input");
			exit(1);
		}
		
	}
	else if(pid < 0)
	{
		perror("Error forking");

	}
	else if (waitpid(pid, &status, 0) == pid)
	{
		if(outputfileDescriptor != 1)
		{
			
			close(outputfileDescriptor);
			int temp = dup2(STDOUT_FILENO,outputfileDescriptor);
			
			close(temp);
		}
		if(inputfileDescriptor != 0)
		{
		
			close(inputfileDescriptor);
			int temp = dup2(STDIN_FILENO,inputfileDescriptor);
			
			close(temp);
		}
		
		if (WIFEXITED(status)) 
		{
			if(WEXITSTATUS(status) == 1)
			{
				failstatus = -1;
			}
			return failstatus;
		}
	}
	
	if(outputfileDescriptor != 1)
	{
		
		close(outputfileDescriptor);
		int temp = dup2(STDOUT_FILENO,outputfileDescriptor);
		close(temp);
	}
	if(inputfileDescriptor != 0)
	{
		
		close(inputfileDescriptor);
		int temp = dup2(STDIN_FILENO,inputfileDescriptor);
		close(temp);
	}
	
	failstatus = -1;
	return failstatus;
}

int execute(string input)
{
	const int PATH_MAX  = 10000;
	char buffer[PATH_MAX];
	memset(buffer, '\0', PATH_MAX);
	string read = "r";
	
	FILE* in_pipe = popen(input.c_str(), read.c_str());
	if(!in_pipe)
	{
		cerr << "cannot open pipe to read" << endl;
		return -1;
	}
	
	while(fgets(buffer, PATH_MAX, in_pipe) != nullptr)
	{
		cout << buffer;
	}
	
	pclose(in_pipe);

	
}
