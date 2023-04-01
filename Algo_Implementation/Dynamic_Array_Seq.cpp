#include "Dynamic_Array_Seq.h"
#include <iostream>
#include <algorithm>
using namespace Sequence;

Dynamic_Array_Seq::Dynamic_Array_Seq(int r):Array_Seq()
{
	this->r = r;
	A_capacity = 0;
	_compute_bounds();
	_resize(0);
}

void Dynamic_Array_Seq::build(int X[], int s) 
{
	for (int i = 0;i < s;i++) {
		insert_last(X[i]);
	}
}

void Dynamic_Array_Seq::_compute_bounds() {
	upper = A_capacity;
	lower = A_capacity/(r*r);
}

void Dynamic_Array_Seq::_resize(int n)
{
	if (lower < n && n < upper) {
		return;
	}
	const int m = std::max(n, 1)*r;
	int* A = new int[m];
	_copy_forward(0,size,A,0);
	delete[] this->A;
	this->A = A;
	A_capacity = m;
	_compute_bounds();
}

void Dynamic_Array_Seq::insert_last(int x)
{
	_resize(size + 1);
	A[size] = x;
	size++;
}

int Dynamic_Array_Seq::delete_last() 
{
	int x = A[size - 1];
	A[size - 1] = NULL;
	size--;
	_resize(size);
	return x;
}

void Dynamic_Array_Seq::insert_at(int i, int x) 
{
	insert_last(NULL);
	_copy_backward(i, size - (i + 1), A, i + 1);
	A[i] = x;
}

int Dynamic_Array_Seq::delete_at(int i) 
{
	int x = A[i];
	_copy_forward(i + 1, size - (i + 1), A, i);
	delete_last();
	return x;
}

void Dynamic_Array_Seq::insert_first(int x)
{
	insert_at(0, x);
}

int Sequence::Dynamic_Array_Seq::delete_first()
{
	return delete_at(0);
}




