#include "Vector.hpp"
int main() {
	cout << "testing Vector(),push_back(),print()" << endl;
	//Vector(),push_back()
	Vector<int> vec;
	vec.push_back(2);
	vec.print();
	cout << vec.size() << endl;
	cout << "testing Vector(initilizer_list&)" << endl;
	//Vector(initilizer_list&)
	Vector<int> vec1 = { 2,5,6,7 };
	vec1.print();
	cout << vec1.size() << endl;
	cout << vec1.capacity() << endl;
	cout << "testing operator=" << endl;
	//operator=
	vec = vec1;
	vec.print();
	cout << vec.size() << endl;
	for (int i = 0; i < 5; ++i) {
		vec.push_back(i);
	}
	vec.print();
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "testing pop_back()" << endl;
	//pop_back()
	vec.pop_back();
	vec.print();
	cout << vec.size() << endl;
	cout << "testing insert()" << endl;
	//insert()
	vec.insert(0, 10);
	vec.print();
	cout << vec.size() << endl;
	cout << "testing clear(),erase()<<endl" << endl;
	//clear(),erase()
	vec.clear(3, 5);
	vec.print();
	cout << vec.size() << endl;
	vec.erase(3);
	vec.print();
	cout << vec.size() << endl;
	getchar();
	return 0;
}