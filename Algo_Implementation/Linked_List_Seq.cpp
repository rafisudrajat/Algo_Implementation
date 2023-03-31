#include "Linked_List_Seq.h"
#include <iostream>
using namespace Sequence;

Linked_List_Node::Linked_List_Node(int x)
{
	item = x;
	next = nullptr;
}

Sequence::Linked_List_Node::~Linked_List_Node()
{
	delete next;
}

Linked_List_Node Linked_List_Node::later_node(int i)
{
	if (i == 0) {
		return *this;
	}
	if (next != nullptr) {
		return this->next->later_node(i - 1);
	}
}


Linked_List_Seq::Linked_List_Seq()
{
	head = nullptr;
	size = 0;
}

Linked_List_Seq::~Linked_List_Seq()
{
}

int Linked_List_Seq::get_length()
{
	return size;
}

void Linked_List_Seq::iter()
{
	Linked_List_Node* node = head;
	while (node!=nullptr)
	{
		std::cout << node->item;
		node = node->next;
	}
}

void Linked_List_Seq::build(int X[], int s)
{
	for (int i = s - 1;i > -1;i--) {
		insert_first(X[i]);
	}
}








