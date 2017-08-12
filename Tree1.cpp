#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node()
	{
		data = 0;
		left = nullptr;
		right = nullptr;
	}

	Node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}

	Node(const Node &node)
	{
		data = node.data;
		left = node.left;
		right = node.right;
	}
};

class BinaryTree
{
	private:
	Node *root;
	void add(Node *current, int value)
	{
		if (current->data > value)
		{
			if (current->left != nullptr)
			{
				add(current->left, value);
			}
			else
			{
				current->left = new Node(value);
				return;
			}
		}
		else
		{
			if (current->right != nullptr)
			{
				add(current->right, value);
			}
			else
			{
				current->right = new Node(value);
				return;
			}
		}
	}

	public:

		BinaryTree()
		{
			root = nullptr;
		}
		Node *getRoot()
		{
			return root;
		}
		void addNode(int value)
		{
			if (root == nullptr)
			{
				root = new Node(value);				
			}
			else
			{
				add(root, value);				
			}
		}
		void traverse(Node *current)
		{
			if (current == nullptr)
				return;
			cout << current->data << endl;
			traverse(current->left);
			traverse(current->right);
		}
		bool search(int num)
		{
			Node *temp = root;      //'head' is pointer to root node
			while (temp != nullptr)
			{
				if (temp->data == num)
					return true;

				if (num > temp->data)
					temp = temp->right;

				if (num < temp->data)
					temp = temp->left;
			}
			if (temp == nullptr)
				return false;
		}
};

int main()
{
	std::vector<int> v = { 4, 2, 6, 1, 3, 5, 7 };
	BinaryTree *mytree = new BinaryTree();
	for (int i = 0; i < 7; ++i)
	{
		mytree->addNode(v[i]);
	}
	mytree->traverse(mytree->getRoot());
	bool ret = mytree->search(4);
	cout << ret;
	return 0;
}