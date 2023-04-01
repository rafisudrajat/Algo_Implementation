#include <iostream>
#include "Static_Array_Seq.h"
#include "Linked_List_Seq.h"
#include "Dynamic_Array_Seq.h"

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
		Sequence::Linked_List_Seq A = Sequence::Linked_List_Seq();
		int arr[] = { 1,2,3,4,5 };
		A.build(arr, 5);
		std::cout << "first iter" << "\n";
		A.iter();
		std::cout << "SIZE: " << A.get_length() << "\n";

		std::cout << "\n" << A.get_at(2) << " " << A.get_at(1)<<"\n";
		A.delete_first();

		std::cout << "second iter" << "\n";
		A.iter();
		std::cout << "SIZE: " << A.get_length() << "\n";
		
		A.insert_at(1, 10);
		std::cout <<"\n"<< "third iter" << "\n";
		A.iter();
		std::cout << "SIZE: " << A.get_length() << "\n";

		A.delete_last();
		std::cout <<"\n"<< "fourth iter" << "\n";
		A.iter();
		std::cout << "SIZE: " << A.get_length() << "\n";

	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
}


void dynamic_array_seq_test() {
	try {
		Sequence::Dynamic_Array_Seq A = Sequence::Dynamic_Array_Seq();
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

int main() {
	
	//array_seq_test();
	//linked_list_seq_test();
	dynamic_array_seq_test();

	

}