#include <iostream>
#include <string>
#include <vector>
#include <queue> 
#include "../header/execute.h"
#include "../header/Token.h"
#include "../header/ExeToken.h"
#include "../header/ConnToken.h"
#include "../header/Tree.h"
using namespace std;

	void Tree::run(Node* connNode)
	{
			ConnToken* token = dynamic_cast<ConnToken*>(connNode->connector);
			if(token->getType() == "&&")
			{
				if(connNode->right->status != 0)//the right child failed
				{
					connNode->status = -1;
					//cout << "setting the status to -1 because the right child failed" << endl;
				}
				else if(connNode->left->status == -1)
				{
					connNode->status = -1; // the left failed so set the status of the connector to -1
					return;
				}
					
			}
			else if(token->getType() == "||")
			{
					if(connNode->left->status == -1)//left status failed so do nothing
					{
						//cout << "i am setting the status in the first if to -1" << endl;
						connNode->status = -1; //setting the status to -1 because the left child failed
					}
					else if(connNode->left->status == 0)
					{
						connNode->status = 0; // the left passed so set the status of the connector to 0 and dont run the right child
						return;
					}
					if(connNode->right->status == 0 && connNode->right->hasExecuted == true)//might need to make a -1 case to set the node status to -1
					{
						//cout << "i am setting the status in the first if to 0" << endl;
						connNode->status = 0; // the right passed so set the status of the connector to 0 and return to go up
					}
					else if(connNode->right->status == -1)
					{
						//cout << "i am setting the status in the last else if to -1" << endl;
						connNode->status = -1; // the right failed so set the status of the connector to -1 and return to go up
						return;
					}
			}
			else if(token->getType() == "|")
			{
				/*if(!connNode->hasExecuted && connNode->left->connector->isexe() && connNode->right->connector->isexe())
				{
					ExeToken* leftToken = dynamic_cast<ExeToken*>(connNode->left->connector);
					ExeToken* rightToken = dynamic_cast<ExeToken*>(connNode->right->connector);
					connNode->status = execute(leftToken, rightToken);
					
					connNode->hasExecuted = true;
				}
				else
					return;*/
			}
	}
	
	Node* Tree::buildTree(queue<Token*> &tokenQueue, int size)
	{
		if(size>1)
		{
			buildTree(tokenQueue);
		}
		else
		{
			Node* tempNode = new Node(tokenQueue.front());
			tokenQueue.pop();
			root = tempNode;
			return tempNode;
		}
	}
	
   	Node* Tree::buildTree(queue<Token*> &tokenQueue)
	{
		if(tokenQueue.front()->isexe())
		{
			Node* leafNode = new Node(tokenQueue.front());
			tokenQueue.pop();
			return leafNode;
		}
		else
		{
			Node* connNode = new Node(tokenQueue.front());
			if(root == nullptr)
			{
				root = connNode;
			}
			tokenQueue.pop();
			connNode ->left = buildTree(tokenQueue);
			connNode ->left->parent = connNode;
			connNode ->right = buildTree(tokenQueue);
			connNode ->right->parent = connNode;
			return connNode;
		}
	}
   
   void	Tree::treeTraverse(Node* node)
   {
		if (node == nullptr) 
		{
			return;
		}

	
		treeTraverse(node->left); //recur on left child
		
		if(node->connector->isexe() && node->parent == nullptr)
		{
			
			node->status = execute(dynamic_cast<ExeToken*>(node->connector));
			node->hasExecuted = true;
		}
		else if(node->connector->isexe() && node->parent != nullptr && node->parent->connector->getWholeToken() != "|")
		{
			node->status = execute(dynamic_cast<ExeToken*>(node->connector));
			node->hasExecuted = true;
		}
		else if(node->connector->isexe() && node->parent->connector->getWholeToken() == "|")
		{
			run(node->parent);
		}
		else
		{
			run(node);
			//cout << "the staus of "<< node->connector->getWholeToken() << " is " << node->status << endl;
			if(node->status == -1 && node->connector->getWholeToken() != "||")
			{
				return;
			}
			else if(node->status == 0 && node->connector->getWholeToken() == "||")
			{
				return;
			}
				
		}
		
		treeTraverse(node->right); // after, recur on right child  
		
		if(!node->connector->isexe())
		{
			run(node);
			if(node->status == -1 && node->connector->getWholeToken() != "||")
			{
				return;
			}
			else if(node->status == 0 && node->connector->getWholeToken() == "||")
			{
				return;
			}
		}
		
		
   }
   
   void destroyTree(Node* node)
   {
		if (node != nullptr)
		{
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
   }