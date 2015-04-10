#ifndef __Tree_H__
#define __Tree_H__

#include "DList.h"

template<class TYPE>
struct TreeNode
{
	TYPE *data;
	TreeNode<TYPE> *parent;
	DList<TYPE> *d_list;
};

template<class TYPE>
class Tree
{
public:
	TreeNode<TYPE> *root_node;

	Tree()
	{
		TreeNode<TYPE> *root_node = new root_node;
	}

	~Tree(){}

	void Add(const TYPE& data)
	{
		TreeNode<TYPE> *new_node = new TreeNode<TYPE>;

		root_node->d_list->Add(new_node);
		new_node->data = data;
		new_node->parent = root_node;
	}
};

#endif __Tree_H__