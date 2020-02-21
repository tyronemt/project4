#ifndef __PROJ_THREE_AVL_HPP
#define __PROJ_THREE_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};


template<typename Key, typename Value>
class MyAVLTree
{
private:
	// fill in private member data here
	// If you need to declare private functions, do so here too.
	struct Node 
	{
		Value value;
		Key key;
		Node* right;
		Node* left;

	};
	Node* root;
	size_t sz;

	int findHeight(Node* n );
	int rebranch(Node* z);


public:
	MyAVLTree();

	// In general, a copy constructor and assignment operator
	// are good things to have.
	// For this quarter, I am not requiring these. 
	//	MyAVLTree(const MyAVLTree & st);
	//	MyAVLTree & operator=(const MyAVLTree & st);


	// The destructor is, however, required. 
	~MyAVLTree()
	{
		// TODO
	}

	// size() returns the number of distinct keys in the tree.
	size_t size() const noexcept;

	// isEmpty() returns true if and only if the tree has no values in it. 
	bool isEmpty() const noexcept;

	// contains() returns true if and only if there
	//  is a (key, value) pair in the tree
	//	that has the given key as its key.
	bool contains(const Key & k) const; 

	// find returns the value associated with the given key
	// If !contains(k), this will throw an ElementNotFoundException
	// There needs to be a version for const and non-const MyAVLTrees.
	Value & find(const Key & k);
	const Value & find(const Key & k) const;

	// Inserts the given key-value pair into 
	// the tree and performs the AVL re-balance
	// operation, as described in lecture. 
	// If the key already exists in the tree, 
	// you may do as you please (no test cases in
	// the grading script will deal with this situation)
	void insert(const Key & k, const Value & v);

	// in general, a "remove" function would be here
	// It's a little trickier with an AVL tree
	// and I am not requiring it for this quarter's ICS 46.
	// You should still read about the remove operation
	// in your textbook. 

	// The following three functions all return
	// the set of keys in the tree as a standard vector.
	// Each returns them in a different order.
	std::vector<Key> inOrder() const;
	std::vector<Key> preOrder() const;
	std::vector<Key> postOrder() const;


};


template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree()
{
	sz = 0;
	root = nullptr;
}

template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return sz;
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
	return (sz==0);
}


template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key &k) const
{
	Node* current = root;
	if (current==nullptr)
	{
		return false;
	}
	if (current->key == k)
	{
		return true;
	}
	while (current->key != k)
	{
		if (current->key < k) 
		{
			//std::cout << (current->right ==nullptr) << sz << std::endl;
			current = current->right;
			//std::cout <<"shifted";
			if (current== nullptr)// || current->key > k)
				//std::cout << current->key << k <<std::endl;
				return false;
		}
		else
		{
			current = current->left;
			if (current==nullptr)// || current->key < k)
				return false;
		}
	}
	return true;


}



template<typename Key, typename Value>
Value & MyAVLTree<Key, Value>::find(const Key & k)
{
	Value v;
	return v; // not only a stub, but a terrible idea.
}

template<typename Key, typename Value>
const Value & MyAVLTree<Key, Value>::find(const Key & k) const
{
	Value v;
	return v; // not only a stub, but a terrible idea.
}

template <typename Key, typename Value>
int MyAVLTree<Key,Value>::findHeight(Node* n)
{
	if (n==nullptr)
	{
		return -1;
	}
	else 
	{
		return 1 + max(findHeight(n->left), findHeight(n->right));
	}

}


// template<typename Key, typename Value>
// Node MyAVLTree<Key,Value>::rebranch(Node* z)
// {
	
// } 

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
	if (root==nullptr)
	{
		Node* temp = new Node;
		temp->key = k;
		temp->value = v;
		root = temp;
		root->right = nullptr;
		root->left = nullptr;
		sz++;

	}
	else
	{
		Node* current = root;
		while (true) //this loop will always run
		{
			if (current->key > k)
			{
				if (current->left == nullptr)
				{
					current->left = new Node;
					current->left->key = k;
					current->left->value = v;
					current->left->left = nullptr;
					current->left->right = nullptr;
					sz++;
					//std::cout << (current->right == nullptr);

					break;
				}
				current = current->left;
			}
			else
			{
				if (current->right == nullptr)
				{
					current->right = new Node;
					current->right->key = k;
					current->right->value = v;
					current->right->right = nullptr;
					current->right->left = nullptr;
					sz++;
					
					break;
				}
				current = current->right;
			}
		}
		if (abs(findHeight(current->left)-findHeight(current->right))> 1)
			{
				current = rebranch(current);
			}


	}

}




template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder() const
{
	std::vector<Key> foo;
	return foo; 
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder() const
{
	std::vector<Key> foo;
	return foo; 
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder() const
{
	std::vector<Key> foo;
	return foo; 
}







#endif 