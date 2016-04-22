#ifndef _VECTOR_HPP_X_
#define _VECTOR_HPP_X_
#include <iostream>
#include <memory>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;

template<typename T> class Vector {
public:
	typedef T value_type;
	//typedef std::shared_ptr<value_type> Ptr;
	typedef value_type* Ptr;
	Vector();
	Vector(initializer_list<value_type> li);
	Vector(int num,value_type data);
	Vector(Vector& oriVec);
	~Vector();
	Vector& operator=(Vector& vec);
	Ptr begin();
	Ptr end();
	int capacity();
	int size();
	void copyTo(Vector& vec);
	void push_back(value_type data);
	void pop_back();
	void insert(int pos,value_type data);
	void erase(int pos);
	void clear(int first, int end);
	static int refcount();
private:
	void resize(int minSize);
	static int refcount_;
	int size_;
	int capacity_;
	Ptr dataPtr_;
	Ptr end_;

};

#endif