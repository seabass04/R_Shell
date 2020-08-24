#ifndef __TREEBUILDER_H__
#define __TREEBUILDER_H__

#include <queue>

struct Node {
	Token* connector = nullptr;
	int status = 0;
	bool hasExecuted = false;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr; //just added this
	Node(Token* connector) :connector(connector), left(nullptr), right(nullptr), hasExecuted(false) {}
};

class Tree {
	private:
	Node* root = nullptr;
	public:
	Tree() 
	{
       root = nullptr;
	}
	~Tree()
	{
		 destroyTree(root);

	}
	
	
	Node* buildTree(queue<Token*> &);
	Node* buildTree(queue<Token*> &, int size);
	
	void treeTraverse(Node* node);
	
	void destroyTree(Node* node);
	
	Node* getRoot()
	{
		return root;
	}
	
	void run(Node* connNode);

};


#endif
