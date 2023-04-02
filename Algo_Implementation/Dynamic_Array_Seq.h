#pragma once
#include "Static_Array_Seq.h"
namespace Sequence {

	template<class T>
	class Dynamic_Array_Seq:public Array_Seq<T>
	{
	public:
		Dynamic_Array_Seq(int r=2);		
		void build(T X[], int s);
		void insert_last(T x);
		T delete_last();
		void insert_at(int i, T x);
		T delete_at(int i);
		void insert_first(T x);
		T delete_first();

	private:
		int r;
		int upper;
		int lower;
		int A_capacity;
		void _compute_bounds();
		void _resize(int n);

	};

	template<class T>
	Dynamic_Array_Seq<T>::Dynamic_Array_Seq(int r) :Array_Seq<T>()
	{
		this->r = r;
		A_capacity = 0;
		_compute_bounds();
		_resize(0);
	}

	template<class T>
	void Dynamic_Array_Seq<T>::build(T X[], int s)
	{
		for (int i = 0;i < s;i++) {
			insert_last(X[i]);
		}
	}

	template<class T>
	void Dynamic_Array_Seq<T>::_compute_bounds() {
		upper = A_capacity;
		lower = A_capacity / (r * r);
	}

	template<class T>
	void Dynamic_Array_Seq<T>::_resize(int n)
	{
		if (lower < n && n < upper) {
			return;
		}
		int m = std::max(n, 1) * r;
		T* A = new T[m];
		this->_copy_forward(0, this->size, A, 0);
		delete[] this->A;
		this->A = A;
		A_capacity = m;
		_compute_bounds();
	}

	template<class T>
	void Dynamic_Array_Seq<T>::insert_last(T x)
	{
		_resize(this->size + 1);
		this->A[this->size] = x;
		this->size++;
	}

	template<class T>
	T Dynamic_Array_Seq<T>::delete_last()
	{
		T x = this->A[this->size - 1];
		this->A[this->size - 1] = NULL;
		this->size--;
		_resize(this->size);
		return x;
	}

	template<class T>
	void Dynamic_Array_Seq<T>::insert_at(int i, T x)
	{
		insert_last(NULL);
		this->_copy_backward(i, this->size - (i + 1), this->A, i + 1);
		this->A[i] = x;
	}

	template<class T>
	T Dynamic_Array_Seq<T>::delete_at(int i)
	{
		T x = this->A[i];
		this->_copy_forward(i + 1, this->size - (i + 1), this->A, i);
		delete_last();
		return x;
	}

	template<class T>
	void Dynamic_Array_Seq<T>::insert_first(T x)
	{
		insert_at(0, x);
	}

	template<class T>
	T Dynamic_Array_Seq<T>::delete_first()
	{
		return delete_at(0);
	}

}