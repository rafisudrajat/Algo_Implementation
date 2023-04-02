#pragma once
#include<iostream>

namespace Sequence {

	//linked list node
	template<class T>
	class Linked_List_Node
	{
	public:
		Linked_List_Node(T x);
		Linked_List_Node* later_node(int i);
		T item;
		Linked_List_Node* next;

	};

	template<class T>
	Linked_List_Node<T>::Linked_List_Node(T x)
	{
		item = x;
		next = nullptr;
	}

	template<class T>
	Linked_List_Node<T>* Linked_List_Node<T>::later_node(int i)
	{
		if (i == 0) {
			return this;
		}
		if (next != nullptr) {
			return this->next->later_node(i - 1);
		}
	}
	
	//Sequence using linked list node
	template<class T>
	class Linked_List_Seq 
	{
	public:
		Linked_List_Seq();
		~Linked_List_Seq();
		int get_length();
		void iter();
		void build(T X[],int s);
		T get_at(int i);
		void set_at(int i, T x);
		void insert_first(T x);
		T delete_first();
		void insert_at(int i, T x);
		T delete_at(int i);
		void insert_last(T x);
		T delete_last();

	private:
		Linked_List_Node<T>* head;
		int size;
		
	};

	template<class T>
	Linked_List_Seq<T>::Linked_List_Seq()
	{
		head = nullptr;
		size = 0;
	}

	template<class T>
	Linked_List_Seq<T>::~Linked_List_Seq()
	{
		Linked_List_Node<T>* ptr = head;
		while (ptr != nullptr) {
			Linked_List_Node<T>* tmp_ptr = ptr->next;
			delete ptr;
			ptr = tmp_ptr;
		}
	}

	template<class T>
	int Linked_List_Seq<T>::get_length()
	{
		return size;
	}

	template<class T>
	void Linked_List_Seq<T>::iter()
	{
		Linked_List_Node<T>* node = head;
		while (node != nullptr)
		{
			//TO DO: Handle output when T is a class type
			std::cout << node->item << ",";
			node = node->next;
		}
	}

	template<class T>
	void Linked_List_Seq<T>::build(T X[], int s)
	{
		for (int i = s - 1;i > -1;i--) {
			insert_first(X[i]);
		}
	}

	template<class T>
	T Linked_List_Seq<T>::get_at(int i)
	{
		return head->later_node(i)->item;
	}

	template<class T>
	void Linked_List_Seq<T>::set_at(int i, T x)
	{
		head->later_node(i)->item = x;
	}

	template<class T>
	void Linked_List_Seq<T>::insert_first(T x)
	{
		Linked_List_Node<T>* new_node = new Linked_List_Node<T>(x);
		new_node->next = head;
		head = new_node;
		size++;
	}

	template<class T>
	T Linked_List_Seq<T>::delete_first()
	{
		T x = head->item;
		Linked_List_Node<T>* t_ptr = head;
		head = head->next;
		delete t_ptr;
		size--;
		return x;
	}

	template<class T>
	void Linked_List_Seq<T>::insert_at(int i, T x)
	{
		if (i == 0) {
			insert_first(x);
			return;
		}
		Linked_List_Node<T>* new_node = new Linked_List_Node<T>(x);
		Linked_List_Node<T>* node = head->later_node(i - 1);
		new_node->next = node->next;
		node->next = new_node;
		size++;
	}

	template<class T>
	T Linked_List_Seq<T>::delete_at(int i)
	{
		if (i == 0) {
			return delete_first();
		}
		Linked_List_Node<T>* node = head->later_node(i - 1);
		T x = node->next->item;
		Linked_List_Node<T>* t_ptr = node->next;
		node->next = node->next->next;
		delete t_ptr;
		size--;
		return x;
	}

	template<class T>
	void Linked_List_Seq<T>::insert_last(T x)
	{
		insert_at(size, x);
	}

	template<class T>
	T Linked_List_Seq<T>::delete_last()
	{
		return delete_at(size - 1);
	}
}