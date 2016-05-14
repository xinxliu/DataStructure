#ifndef _TREE_HPP_X_
#define _TREE_HPP_X_

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

template <typename T>
struct BinaryTreeNode {
	T _data;
	BinaryTreeNode* _lchild;
	BinaryTreeNode* _rchild;
	BinaryTreeNode() :_lchild(NULL), _rchild(NULL) {}
	BinaryTreeNode(T data,BinaryTreeNode* l = NULL,BinaryTreeNode* r = NULL):_data(x),_lchild(l),_rchild(r){}
	print();
};

template<typename T>
class BinaryTree {
public:

private:
	BinaryTreeNode<T>* root;

};


#endif

template<typename T>
inline BinaryTreeNode<T>::print(){
	cout << _data << " ";
}
