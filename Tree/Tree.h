#ifndef __Tree_H__
#define __Tree_H__

#include "DList.h"

template<class TYPE>
struct Node
{
	TYPE *data;
	Node<TYPE> *parent;
	DList<TYPE> *d_list;
};

template<class TYPE>
class Tree
{
public:
	Node<TYPE> *root_node;

	Tree()
	{
		Node<TYPE> *root_node = new root_node;
	}

	~Tree(){}

	void Add(const TYPE& data)
	{
		Node<TYPE> *new_node = new Node<TYPE>;

		root_node->d_list->Add(new_node);
		new_node->data = data;
		new_node->parent = root_node;
	}
};

#endif __Tree_H__