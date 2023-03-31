#include <iostream>
#include "Static_Array_Seq.h"
using namespace Sequence;

/*Implementation of Sequence Interface using Static Array*/
Array_Seq::Array_Seq() {
	A = new int[0];
	size = 0;
}

Array_Seq::Array_Seq(int X[], int s) {
	for (int i = 0;i < s;i++) {
		*(A+i) = X[i];
	}
	size = 0;
}

Array_Seq::~Array_Seq() {
	delete[] A;
}

void Array_Seq::build(int* X, int s)
{
	delete[] A;
	A = new int[s];
	for (int i = 0;i < s;i++) {
		*(A+i) = *(X + i);
	}
	size = s;
}

int Array_Seq::get_length()
{
	return size;
}

void Array_Seq::iter()
{
	for (int i = 0;i < size;i++) {
		std::cout << *(A + i) << '\n';
	}
}

int Array_Seq::get_at(int i)
{
	if (i >= size) {
		throw "Index out of bound";
	}
	return *(A + i);
}

int Array_Seq::set_at(int i, int x)
{
	if (i >=size) {
		throw "Index out of bound";
	}
	*(A + i) = x;
}

void Array_Seq::insert_at(int i, int x)
{
	int n = size+1;
	int* A = new int[n];
	_copy_forward(0,i,A,0);
	*(A + i) = x;
	_copy_forward(i, n - i, A, i + 1);
	build(A, n);
	delete[] A;
}

int Array_Seq::delete_at(int i)
{
	int n = size-1;
	int* A = new int[n];
	_copy_forward(0, i, A, 0);
	int x = *(this->A + i);
	_copy_forward(i + 1, n - i - 1, A, i);
	build(A, n);
	delete[] A;
	return x;
}

void Array_Seq::insert_first(int x)
{
	insert_at(0, x);
}

int Array_Seq::delete_first()
{
	return delete_at(0);
}

void Array_Seq::insert_last(int x)
{
	insert_at(size, x);
}

int Array_Seq::delete_last()
{
	return delete_at(size - 1);
}

void Array_Seq::_copy_forward(int i, int n, int* A, int j)
{
	for (int k = 0;k < n;k++) {
		*(A+j+k) = *(this->A + i + k);
	}
}

void Array_Seq::_copy_backward(int i, int n, int* A, int j)
{
	for (int k = n - 1; k > -1; k--) {
		*(A+j+k) = *(this->A + i + k);
	}
}

