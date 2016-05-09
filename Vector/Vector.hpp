#ifndef _VECTOR_HPP_X_
#define _VECTOR_HPP_X_
#include <iostream>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;

template<typename T>
class Vector{
public:
	typedef T value_type;
	//typedef std::shared_ptr<value_type> Ptr;
	typedef value_type* Ptr;
	//constructor function
	Vector();
	Vector(initializer_list<value_type> li);
	Vector(int num,value_type data);
	Vector(Vector& oriVec);
	//deconstructor function
	~Vector();
	//reload operator=
	Vector& operator=(Vector& vec);
	Ptr begin(){
		return begin_;
	}
	Ptr end(){
		return end_;
	}
	int capacity(){
		return capacity_;
	}
	int size(){
		return size_;
	}
	void push_back(T data);
	void pop_back();
	void insert(int pos,value_type data);
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

#endif