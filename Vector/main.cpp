#include "Vector.hpp"
int main(){
	Vector<int> vec;
	vec.push_back(2);
	vec.print();
	cout<<vec.size()<<endl;
	getchar();
	return 0;
}