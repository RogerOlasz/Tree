#ifndef __Tree_H__
#define __Tree_H__

#include "DList.h"

template<class TYPE>
struct TreeNode
{
	TYPE data;
	TreeNode<TYPE> *parent;
	DList<TreeNode*> d_list;

	void VisitAll(DList<TYPE> list)
	{
		list->Add(data);

		for (unsigned int i = 0; i <= d_list.Count(); i++)
		{
			VisitAll(list);
		}
	}
};

template<class TYPE>
class Tree
{
public:
	TreeNode<TYPE> *root_node;

	Tree()
	{
		root_node = new TreeNode<TYPE>;
	}

	~Tree(){}

	TreeNode<TYPE>* Add(const TYPE& new_data)
	{
		TreeNode<TYPE> *new_node = new TreeNode<TYPE>;

		root_node->d_list.Add(new_node);
		new_node->data = new_data;
		new_node->parent = root_node;

		return new_node;
	}

	TreeNode<TYPE>* Add(const TYPE& new_data, TreeNode<TYPE> *parent)
	{
		TreeNode<TYPE> *new_node = new TreeNode<TYPE>;

		parent->d_list.Add(new_node);
		new_node->data = new_data;
		new_node->parent = parent;

		return new_node;
	}
	
	

	void VisitAllNodes(DList<TYPE> list) const
	{
		root_node->VisitAll(list);
	}
};

#endif __Tree_H__