#include "Static_Array_Seq.h"
#include <iostream>
#include "Linked_List_Seq.h"

void array_seq_test() {
	try {
		Sequence::Array_Seq A = Sequence::Array_Seq();
		int arr[] = { 1,2,3 };
		int sizeArr = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0;i < sizeArr;i++) {
			A.insert_last(arr[i]);
		}
		A.iter();
		A.insert_first(9);
		std::cout << "Second Iter" << '\n';
		A.iter();
		std::cout << A.get_length() << " items \n";

		std::cout << A.get_at(2) << '\n';

		A.delete_last();
		std::cout << "Third Iter" << '\n';
		A.iter();
		std::cout << A.get_length() << " items \n";

		std::cout << A.get_at(4);
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
}

void linked_list_seq_test() {
	try {
		Sequence::Linked_List_Node A = Sequence::Linked_List_Node(5);

			//sequence::Linked_List_Seq();

	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
}


int main() {
	
	//linked_list_seq_test();
	array_seq_test();

}