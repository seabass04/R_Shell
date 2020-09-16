# RShell

> This is a copy of the original repository for privacy reason
### Introduction <br />
RShell is a program made to replicate the linux command shell. It takes in an unlimted amount commands, logical connectors, and flasgs, from the usual Bash, and executes them. 
It was implemented using composite design pattern in a multistep process.


### UML Diagram  
![Alt text](/images/UML_Hw4.png?raw=true "Image of our UML diagram")<br />
### Classes
* **RShell:** RShell is the interface which the user interacts with. It takes in input
from the user, breaks them down with the parser, tokenizes them, and tries to execute
the proper command, only stopping with the exit command.
* **Parser:** The Parser class has the important job of starting the breaking down
process of the user input. It
utilizes the Boost library's *Tokenier package* and inserts input into a vector.
* **Separate:** Separate is in charge of taking the parsed input and separating the
commands and connectors. It adds
the entire command
(without the connector) and the connector separately into a vector to be tokenized.
* **TestComamnd:** TestCommand is used to execute the test executables. It can handle literal and
symbolic executables such as *test src* or *[ src ]* along witht the flags *-e, -f, and -d*. Unlike the normal test
executable, RShell outputs *(True)* or *(False)* when executing the given command.
* **Tokenizer:** Tokenizer takes in the vector of separated input and creates tokens
based on the input. It makes
*ExeTokens* and *ConnTokens* and puts them into a vector of *Token\*'s* .
* **Tree:** The Tree class is in charge of making a binary tree, made of Node's, from a vector of *Token\*'s*. Without a tree, our program wouldn't be able to handle the use of parentheses from user input. This is due to the change of precedence in the order of executing commands. This tree then gets given to rshell to execute commands in the correct order.
  * **Node:** *Nodes* are a struct made to be stored in the *Tree* class. They hold *Token\*'s* as well as *Node* pointers to the left and right child of each *Node*.
* **Token:** Token serves as the base case for the two types of tokens. Without tokens,
there would be no way to tokenize the input. Each Token has variables such as
wholetoken, which is a string for
input, argument, another string that
holds the argument of the input, and others. It also uses various functions such as
managing statuses which are
necessary for
execting connectors properly.
  * **ExeToken:** ExeToken is a subclass of the Token class. Its purpose is to store
                 input to be used as a command. It also stores any flags and arguments with it.
                 It does not store any connectors and it is vital for executing the user input.
  * **ConnToken:** ConnToken is a subclass of the Token class. Its purpose is to store the connectors from the user
  input.
                   It takes in three types of connectors, semicolon(;), and(&&), and or(||). The *Semicolon*
                   executes the left and then the right command, the *And* executes the right command
                    only if the left command executes successfully, and the *Or* trys to execute the left command,
                    but if it
                   fails, the right command gets executed.



### Prototypes/Research
From our findings, it seems like waitpid() suspends execution until the state of a specified child changes. The
function execvp() allows
processes to run program files and call linux commands. Fork() creates child processes that are capable of executing
the same code as the parent, but code can be modifed so that
child processes run different functions if needed.
![Alt text](/images/parser_demo.png?raw=true "Image of Parser Demo")<br />
We utitlized the Tokenier package of the Boost library to create our prototype for the parser. Currently, the
prototype takes in a command such as "git add main.cpp && git add hello.h" and breaks it up into its separate parts.
Then, the count for executables, arguments, and
connectors is displayed. We tested connectors in a normal shell to see how they function. We found that the when
using semicolons you could chain separate commands together
instead of having to input them on different lines. The "&&" connector also allows you to chain commands but the
command following the connector only runs if the first command
executes properly. The "||" is the opposite of "&&" because it causes the command following the connector to only
run if the first command fails.
### Development and Testing Roadmap
1. [Develop Shell class](https://github.com/cs100/assignment-middleout/issues/1)
2. [Create tests for Shell that verify that the class can take in and store user input seabass04/assignment-middleout#10](https://github.com/cs100/assignment-middleout/issues/2)
3. [Create tests for Shell that verify that the class can print the proper command prompt](https://github.com/cs100/assignment-middleout/issues/3)
4. [Build off of the Parser prototype by modifying the main into a single function](https://github.com/cs100/assignment-middleout/issues/4)
5. [Test the Parser class to ensure that it maintains functionality after the modification](https://github.com/cs100/assignment-middleout/issues/5)
6. [Develop the Commands class](https://github.com/cs100/assignment-middleout/issues/6)
7. [Test that the Commands class can run files and commands, such as exit, specified by the user](https://github.com/cs100/assignment-middleout/issues/7)
8. [Integrate the Commands class into the Shell class so it can access user inputs](https://github.com/cs100/assignment-middleout/issues/8)
9. [Create an integration test for the Commands class that verifies proper execution of user commands](https://github.com/cs100/assignment-middleout/issues/9)
10. [Develop the Connectors class as a base class for child connectors](https://github.com/cs100/assignment-middleout/issues/10)
11. [Develop the child classes of Connectors](https://github.com/cs100/assignment-middleout/issues/11)
12. [Test all connectors by verifying that they respect the rules of "&&" , "||", and  ";" as well as precedence](https://github.com/cs100/assignment-middleout/issues/12)
13. [Integrate the Connectors class and subclasses into Shell](https://github.com/cs100/assignment-middleout/issues/13)
14. [Create an integration test to verify that connectors maintain functionality in Shell](https://github.com/cs100/assignment-middleout/issues/14)
15. [Create unit test for RShell to check edge cases and confirm that user input results in the correct outcome](https://github.com/cs100/assignment-middleout/issues/15)
