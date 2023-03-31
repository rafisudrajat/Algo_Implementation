#pragma once
namespace Sequence {
	class Linked_List_Node
	{
	public:
		Linked_List_Node(int x);
		~Linked_List_Node();
		Linked_List_Node later_node(int i);
		int item;
		Linked_List_Node* next;

	};

	class Linked_List_Seq 
	{
	public:
		Linked_List_Seq();
		~Linked_List_Seq();
		int get_length();
		void iter();
		void build(int X[],int s);
		int get_at(int i);
		void set_at(int i, int x);
		void insert_first(int x);
		int delete_first();
		void insert_at(int i, int x);
		int delete_at(int i);
		void insert_last(int x);
		int delete_last();


	private:
		Linked_List_Node* head;
		int size;
		

	};

}