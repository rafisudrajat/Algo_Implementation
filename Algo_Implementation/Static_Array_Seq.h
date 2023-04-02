#pragma once
namespace Sequence {
	template<typename T>
	class Array_Seq
	{
	public:
		Array_Seq();
		Array_Seq(T X[], int s);
		~Array_Seq();

		void build(T* X, int s);
		int get_length();
		void iter();
		T get_at(int i);
		void set_at(int i, T x);
		void insert_at(int i, T x);
		T delete_at(int i);
		void insert_first(T x);
		T delete_first();
		void insert_last(T x);
		T delete_last();

	protected:
		T* A;
		int size;
		void _copy_forward(int i, int n, T* A, int j);
		void _copy_backward(int i, int n, T* A, int j);
	};

	template<typename T>
	Array_Seq<T>::Array_Seq() {
		A = new T[0];
		size = 0;
	}

	template<typename T>
	Array_Seq<T>::Array_Seq(T X[], int s) {
		for (int i = 0;i < s;i++) {
			*(A+i) = X[i];
		}
		size = 0;
	}

	template<typename T>
	Array_Seq<T>::~Array_Seq() {
		delete[] A;
	}

	template<typename T>
	void Array_Seq<T>::build(T* X, int s)
	{
		delete[] A;
		A = new T[s];
		for (int i = 0;i < s;i++) {
			*(A+i) = *(X + i);
		}
		size = s;
	}

	template<typename T>
	int Array_Seq<T>::get_length()
	{
		return size;
	}

	template<typename T>
	void Array_Seq<T>::iter()
	{
		//TO DO: Handle output when T is a class type
		for (int i = 0;i < size;i++) {
			std::cout << *(A + i) << '\n';
		}
	}

	template<typename T>
	T Array_Seq<T>::get_at(int i)
	{
		if (i >= size) {
			throw "Index out of bound";
		}
		return *(A + i);
	}

	template<typename T>
	void Array_Seq<T>::set_at(int i, T x)
	{
		if (i >=size) {
			throw "Index out of bound";
		}
		*(A + i) = x;
	}

	template<typename T>
	void Array_Seq<T>::insert_at(int i, T x)
	{
		int n = size+1;
		T* A = new T[n];
		_copy_forward(0,i,A,0);
		*(A + i) = x;
		_copy_forward(i, n - i, A, i + 1);
		build(A, n);
		delete[] A;
	}

	template<typename T>
	T Array_Seq<T>::delete_at(int i)
	{
		int n = size-1;
		T* A = new T[n];
		_copy_forward(0, i, A, 0);
		T x = *(this->A + i);
		_copy_forward(i + 1, n - i - 1, A, i);
		build(A, n);
		delete[] A;
		return x;
	}

	template<typename T>
	void Array_Seq<T>::insert_first(T x)
	{
		insert_at(0, x);
	}

	template<typename T>
	T Array_Seq<T>::delete_first()
	{
		return delete_at(0);
	}

	template<typename T>
	void Array_Seq<T>::insert_last(T x)
	{
		insert_at(size, x);
	}

	template<typename T>
	T Array_Seq<T>::delete_last()
	{
		return delete_at(size - 1);
	}

	template<typename T>
	void Array_Seq<T>::_copy_forward(int i, int n, T* A, int j)
	{
		for (int k = 0;k < n;k++) {
			*(A+j+k) = *(this->A + i + k);
		}
	}

	template<typename T>
	void Array_Seq<T>::_copy_backward(int i, int n, T* A, int j)
	{
		for (int k = n - 1; k > -1; k--) {
			*(A+j+k) = *(this->A + i + k);
		}
	}
}

