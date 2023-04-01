#pragma once
namespace Sequence {
	class Array_Seq
	{
	public:
		Array_Seq();
		Array_Seq(int X[], int s);
		~Array_Seq();

		void build(int* X, int s);
		int get_length();
		void iter();
		int get_at(int i);
		int set_at(int i, int x);
		void insert_at(int i, int x);
		int delete_at(int i);
		void insert_first(int x);
		int delete_first();
		void insert_last(int x);
		int delete_last();

	protected:
		int* A;
		int size;
		void _copy_forward(int i, int n, int* A, int j);
		void _copy_backward(int i, int n, int* A, int j);
	};
}

