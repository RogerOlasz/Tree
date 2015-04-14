#ifndef __DList_H__
#define __DList_H__

#include <iostream>

template<class TYPE>
struct  DNode
{
	TYPE value;
	DNode<TYPE>* next;
	DNode<TYPE>* previous;
};

template<class TYPE>
class DList {

private:
	DNode<TYPE>* start;

public:
	DList()
	{
		start = NULL;
	}

	unsigned int Count() const
	{
		unsigned int counter = 0;
		DNode<TYPE>* tmp = start;

		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}

		return counter;
	}

	void Add(TYPE new_value)
	{
		DNode<TYPE>* new_node = new DNode<TYPE>;
		new_node->value = new_value;
		new_node->next = NULL;

		if (start != NULL)
		{
			DNode<TYPE>* tmp = start;

			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
				
			tmp->next = new_node;
			new_node->previous = tmp;
		}

		else
		{
			new_node->previous = NULL;
			start = new_node;
		}
	}

	bool Del(DNode<TYPE>* delete_node)
	{
		if (start != NULL && delete_node != NULL)
		{
			if (start != delete_node)
			{
				DNode<TYPE>* tmp = start;

				while (tmp->next != delete_node)
				{
					tmp = tmp->next;
					if (tmp->next == NULL)
					{
						return false;
					}	
				}

				tmp->next = delete_node->next;

				if (delete_node->next != NULL)
				{
					delete_node->next->previous = tmp;
				}
				else
				{
					tmp->next = NULL;
				}
			}
			else
			{
				if (delete_node->next != NULL)
				{
					start = delete_node->next;
					delete_node->next->previous = NULL;
				}
				else
				{
					start = NULL;
				}
					
			}
			delete delete_node;
			return true;
		}
		return false;
	}

	bool DelList() 
	{
		if (start != NULL)
		{
			while (start->next != NULL)
			{
				DNode<TYPE>* node_to_delete = start;
				start = start->next;
				delete node_to_delete;
			}
			start = NULL;
			return true;
		}
		return false;
	}

	DNode<TYPE>* getNodeAtPos(unsigned int position) const
		{
			if (start != NULL && position < Count())
			{
				unsigned int position_counter = 0;
				DNode<TYPE>* tmp = start;

				while (position_counter != position)
				{
					tmp = tmp->next;
					position_counter++;
				}
				return tmp;
			}
			return NULL;
		}
};

#endif //__DList_H__