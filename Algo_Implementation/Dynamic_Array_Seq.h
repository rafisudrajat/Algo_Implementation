#pragma once
#include "Static_Array_Seq.h"
namespace Sequence {
	class Dynamic_Array_Seq:public Array_Seq
	{
	public:
		Dynamic_Array_Seq(int r=2);		
		void build(int X[], int s);
		void insert_last(int x);
		int delete_last();
		void insert_at(int i, int x);
		int delete_at(int i);
		void insert_first(int x);
		int delete_first();

	private:
		int r;
		int upper;
		int lower;
		int A_capacity;
		void _compute_bounds();
		void _resize(int n);

	};

}