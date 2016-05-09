#ifndef _VECTOR_HPP_X_
#define _VECTOR_HPP_X_
#include <iostream>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;

template<typename T>
class Vector {
public:
	typedef T value_type;
	//typedef std::shared_ptr<value_type> Ptr;
	typedef value_type* Ptr;
	//constructor function
	Vector();
	Vector(initializer_list<value_type> li);
	Vector(int num, value_type data);
	Vector(Vector& oriVec);
	//deconstructor function
	~Vector();
	//reload operator=
	Vector& operator=(Vector& vec);
	Ptr begin() {
		return begin_;
	}
	Ptr end() {
		return end_;
	}
	int capacity() {
		return capacity_;
	}
	int size() {
		return size_;
	}
	void push_back(T data);
	void pop_back();
	void insert(int pos, value_type data);
	void erase(int pos);
	void clear(int first, int end);
	void print();
private:
	void resize(int minSize);
	int size_;
	int capacity_;
	Ptr begin_;
	Ptr end_;

};

template<typename T>
Vector<T>::Vector() :size_(0), capacity_(0), begin_(nullptr), end_(nullptr) {
}

template<typename T>
Vector<T>::Vector(initializer_list<value_type> li) {
	size_ = li.size();
	capacity_ = 2 * size_;
	begin_ = new value_type[capacity_];
	end_ = begin + size_;
	Ptr temp = begin_;
	for (auto it = li.begin(); it != li.end(); ++it, ++temp) {
		*temp = *it;
	}
}

template<typename T>
Vector<T>::Vector(int num, value_type data) {
	size_ = num;
	capacity_ = 2 * size;
	begin_ = new value_type[capacity_];
	end_ = begin_ + size_;
	Ptr temp = begin;
	for (int i = 0; i < num; ++i, ++temp) {
		*(temp) = data;
	}
}

template<typename T>
Vector<T>::Vector(Vector<T>& oriVec) {
	size_ = oriVec.size_;
	capacity_ = oriVec.size_;
	if (capacity_ != 0) {
		delete begin_;
	}
	begin_ = new value_type[capacity_];
	end_ = begin_ + size_;
	for (Ptr temptr = begin_, temptrori = oriVec.begin_; temptrori != oriVec.end_; ++temptr, ++temptrori) {
		*(temptr) = *(temptrori);
	}
}

template<typename T>
Vector<T>::~Vector()
{
	if (capacity_ != 0) {
		delete[] begin_;
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>& vec) {
	if (this == &vec) {
		return *this;
	}
	size_ = vec.size_;
	capacity_ = vec.capacity_;
	if (capacity_ != 0) {
		delete[] begin_;
	}
	begin_ = new value_type[vec.capacity_];
	end_ = begin_ + size_;
	for (Ptr temptr = begin_, temptrori = vec.begin_; temptrori != vec.end_; ++temptr, ++temptrori) {
		*(temptr) = *(temptrori);
	}
	return *this;
}

template<typename T>
void Vector<T>::resize(int minSize) {
	Ptr tempBegin = begin_;
	begin_ = new value_type[minSize];
	for (Ptr temp1 = begin_, temp2 = tempBegin; tempBegin != end_; ++temp2, ++temp1) {
		*(temp1) = *(temp2);
	}
	end_ = begin_ + size_;
	if (capacity_ != 0) {
		delete[] tempBegin;
	}
	capacity_ = minSize;
}

template<typename T>
void Vector<T>::push_back(T data) {
	if (capacity_ == 0) {
		this->resize(1);
		*begin_ = data;
		++size_;
		++end_;
		return;
	}
	if (capacity_ <= size_) {
		resize(2 * size_);
		*end_ = data;
		++size;
		++end_;
	}
}

template<typename T>
void Vector<T>::pop_back() {
	if (capacity_ == 0) {
		cout << "nothing to pop_back" << endl;
		return;
	}
	--end_;
}

template<typename T>
void Vector<T>::insert(int pos, value_type data) {

}

template<typename T>
void Vector<T>::erase(int pos)
{
}

template<typename T>
void Vector<T>::clear(int first, int end)
{
}

template<typename T>
void Vector<T>::print()
{
	for (Ptr temp = begin_; temp != end_; ++temp) {
		cout << *temp << " ";
	}
	cout << "print over" << endl;
}

#endif