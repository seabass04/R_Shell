#include <iostream>
#include <sys/wait.h>
#include <unistd.h> 
using namespace std;

void childProcessPrint()
{
	cout << "The child process is running." << endl;
}

void parentProcessPrint()
{
	cout << "This current cout statement is part of the parent process. The child process never runs this code." << endl;
}

int main()
{
	pid_t pid;
	pid = fork();
	int status;
	
	if (pid == 0) 
	{
     	childProcessPrint();
		char* argv[2];
		argv[0] = "pwd";
		argv[1] = NULL;
		cout << "The child process will now run pwd" << endl;
		execvp(argv[0],argv); 
		
    } 
	else if (pid == -1) 
	{
           cout << "Fork failed" << endl;
    } 
	else if (waitpid(pid, &status, 0) == pid)
	{
		cout << "The child has exited" << endl;
		if (WIFEXITED(status)) 
		{
			cout << "The child " << pid <<" terminated with status: "<< WEXITSTATUS(status) <<"\n"; 
			cout << "The child exited normally. The parent process can continue." << endl;
			parentProcessPrint();
		}
	}
	return 0;
}
