#include "Vector.hpp"


template <typename T> int Vector<T>::refcount_ = 1;
template<T>
Vector<T>::Vector() : size_(0), capacity_(0) {
	dataPtr_ = nullptr;
	end_ = dataPtr_;
}

template<T>
Vector<T>::Vector(initializer_list<value_type> li) :
	size_(li.size()), capacity_(2 * size_) {
	dataPtr = new value_type[capacity_];
	Ptr temp = dataPtr;
	for (auto it = li.begin(); itbegin != li.end(); ++it, ++temp) {
		*(temp) = *(it);
	}
	end_ = dataPtr_ + size_;
}

template<typename T>
Vector<T>::Vector(int num, value_type data) :
	size(num), capacity_(2 * size_) {
	dataPtr_ = new value_type[capacity_];
	Ptr temp = dataPtr;
	for (int i = 0; i < num; ++i, ++temp) {
		*(temp) = data;
	}
	end_ = dataPtr + size_;
}

template<typename T>
Vector<T>::Vector(Vector & oriVec){

}

template<typename T>
int Vector<T>::capacity() {
	return capacity_;
}

template<typename T>
int Vector<T>::size() {
	return size_;
}

template<typename T>
void Vector<T>::copyTo(Vector& vec){
	if (vec.refcount_ != 1) {
		cout << "vector is not unique!connot update your data!" << endl;
		return;
	}
	if (vec.size_ != 0) {
		delete[] vec.dataPtr;
		end_ = nullptr;
	}
	vec.size_ = size_;
	vec.capacity_ = capacity_;
	vec.dataPtr_ = new value_type[capacity_];
	Ptr temp = vec.dataPtr;
	for (Ptr tempOri = dataPtr; tempOri != end_; ++tempOri,++temp) {
		*(temp) = *(tempOri);
	}
	end_ = vec.dataPtr_ + vec.size_;
	refcount = 1;
}

template<typename T>
void Vector<T>::push_back(value_type data) {

}

template<typename T>
void Vector<T>::pop_back() {

}

template<typename T>
void Vector<T>::insert(int pos, value_type data) {

}

template <typename T>
void Vector<T>::erase(int pos) {

}

template<typename T>
void Vector<T>::clear(int first,int end) {

}

template<typename T>
int Vector<T>::refcount() {
	return refcount_;
}

template<T>
void Vector<T>::resize(int minSize) {

}

template<T>
Vector<T>::~Vector() {
	
}

template<typename T>
Vector & Vector<T>::operator=(Vector & vec){
	
	if (&vec == this) {
		return *this;
	}
	if (size_ != 0) {
		delete[] dataPtr;
		end_ = nullptr;
	}
	size_ = vec.size_;
	capacity_ = vec.capacity_;
	//reference counter
	++refcount_;
	dataPtr_ = vec.dataPtr_;
	end_ = vec.end_;
	return *this;
}

template<typename T>
Ptr Vector<T>::begin()
{
	return dataPtr_;
}

template<typename T>
Ptr Vector<T>::end(){
	return end_;
}