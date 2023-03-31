#include "Linked_List_Seq.h"
#include <iostream>
using namespace Sequence;

Linked_List_Node::Linked_List_Node(int x)
{
	item = x;
	next = nullptr;
}

Linked_List_Node* Linked_List_Node::later_node(int i)
{
	if (i == 0) {
		return this;
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
	Linked_List_Node* ptr = head;
	while (ptr != nullptr) {
		Linked_List_Node* tmp_ptr = ptr->next;
		delete ptr;
		ptr = tmp_ptr;
	}
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
		std::cout << node->item<<",";
		node = node->next;
	}
}

void Linked_List_Seq::build(int X[], int s)
{
	for (int i = s - 1;i > -1;i--) {
		insert_first(X[i]);
	}
}

int Linked_List_Seq::get_at(int i)
{
	return head->later_node(i)->item;
}

void Linked_List_Seq::set_at(int i, int x)
{
	head->later_node(i)->item=x;
}

void Linked_List_Seq::insert_first(int x)
{
	Linked_List_Node* new_node = new Linked_List_Node(x);
	new_node->next = head;
	head = new_node;
	size++;
}

int Linked_List_Seq::delete_first()
{
	int x = head->item;
	Linked_List_Node* t_ptr = head;
	head = head->next;
	delete t_ptr;
	size--;
	return x;
}

void Linked_List_Seq::insert_at(int i, int x)
{
	if (i == 0) {
		insert_first(x);
		return;
	}
	Linked_List_Node* new_node = new Linked_List_Node(x);
	Linked_List_Node* node = head->later_node(i - 1);
	new_node->next = node->next;
	node->next = new_node;
	size++;
}

int Linked_List_Seq::delete_at(int i)
{
	if (i == 0) {
		return delete_first();
	}
	Linked_List_Node* node = head->later_node(i - 1);
	int x = node->next->item;
	Linked_List_Node* t_ptr = node->next;
	node->next = node->next->next;
	delete t_ptr;
	size--;
	return x;
}

void Linked_List_Seq::insert_last(int x)
{
	insert_at(size, x);
}

int Linked_List_Seq::delete_last()
{
	return delete_at(size - 1);
}


















