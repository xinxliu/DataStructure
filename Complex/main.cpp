#include <iostream>
#include "Complex.hpp"
using namespace std;


void test(Complex<double>& a,Complex<double>& b){
	Complex<double> c = a.add(b); 
	cout << c;
}
int main(){
	
		Complex<double> a = Complex<double>(2.3, 4.4);
		Complex<double> b = Complex<double>(5.3, 5.5);
		test(a, b);
	
	getchar();
	return 0;
}