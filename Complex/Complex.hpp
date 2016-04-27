#ifndef _TEST_H_X_
#define _TEST_H_X_

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
template<typename T>
class Complex {
public:
	typedef T value_type;
	Complex(value_type real, value_type vir) :_real(real), _vir(vir) { cout << "this is the constructor" << endl; }
	Complex() { cout << "this is the default constructor" << endl; }
	Complex(Complex& a):_real(a._real),_vir(a._vir){}
	Complex& operator=(const Complex& b) {
		if (this == &b) {
			return *this;
		}
		_real = b._real;
		_vir = b._vir;
		cout << "this is the operator=" << endl;
		return *this;
	}
	~Complex(){
		cout << "this is decontructor" << endl;
	}
	Complex add(Complex& b) {
		/*Complex<T>* c = new Complex<T>(_real + b._real, _vir + b._vir);
		return *c;*/
		return Complex(_real + b._real, _vir + b._vir);
	}
	Complex operator*(Complex& b) {
		return Complex(_real*b._real - _vir*b._vir, _real*b._vir + _vir*b._real);
	}
	Complex operator+(Complex& b) {
		return Complex(_real + b._real, _vir + b._vir);
	}
	Complex operator-(Complex& b) {
		return Complex(_real - b._real, _vir - b._vir)
	}
	void inverse() {
		T _realTemp = _real;
		_real = _real / (_real*_real + _vir*_vir);
		_vir = -(_vir / (_real*_real + _vir*_vir));
	}
	T abs() {
		return _real*_real + _vir*_vir;
	}
	template<typename U> friend ostream& operator<<(ostream& os, const Complex<U> a);
private:
	T _real;
	T _vir;
};

template<typename U>
ostream& operator<<(ostream& os, const Complex<U> a) {
	os << a._real << " + i" << a._vir;
	return os;
}
#endif
