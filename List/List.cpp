#include "List.hpp"
#include <iostream>

using namespace std;

//构造函数，初始化链表结点
ListNode::ListNode()
{
	data_ = 0;
	next = NULL;
}
//获取链表节点数据
int &ListNode::data()
{
	return data_;
}
//采用const形式，获取链表节点函数
const int ListNode::data() const
{
	return data_;
}


//构造函数，初始化链表
CPPList::CPPList()
{
	size_ = 0;
	last = new ListNode;
	last->next = NULL;
	first = last;
}
//析构函数，释放链表所占空间
CPPList::~CPPList()
{
	clear();
}
//若链表size为零，则表示链表为空
bool CPPList::is_empty()
{
	if (size_==0)
		return true;
	else
		return false;
}
//返回链表size
int CPPList::size() 
{
	return size_;
}
//链表头
ListNode *CPPList::begin()
{
	return first;
}
//链表尾
ListNode *CPPList::end()
{
	return last;
}

const ListNode *CPPList::begin() const
{
	return first;
}

const ListNode *CPPList::end() const
{
	return last;
}
//查询当前结点的下一结点
ListNode *CPPList::next(const ListNode *current)
{
	if (begin() == end())
	{
		return NULL;
	}
	else
		return current->next;
}
//const形式
const ListNode *CPPList::next(const ListNode *current) const
{
	if (begin() == end())
	{
		return NULL;
	}
	else
		return current->next;
}
//在链表最后插入结点
void CPPList::append(int data)
{
	ListNode *p = new ListNode;  //待插入结点
	p->data_ = data;
	p->next = last;
	if (is_empty())
	{
		first = p;              //链表为空，则待插入结点成为头结点
			}
	else                         //否则，待插入结点的指针域指向尾结点，原指针域指向尾结点的结点指针域指向待插入结点
	{
		ListNode *tmp = first;
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = p;
	}
	size_++;
}
//向当前结点前插入结点
void CPPList::insert(ListNode *current, int data)
{
	if (is_empty())        //如果链表为空，则此操作无效，直接返回
	{
		return;
	}       
	if (current->next == NULL)  //如果当前结点为尾节点，则调用append函数
	{
		append(data);
	}
	else                    
	{
		ListNode *tmp = first;
		ListNode *p = new ListNode;
		p->data_ = data;
		if (current != first)            //如果当前结点为头节点，则待插入结点成为头结点
		{
			while (tmp->next != current)
			{
				tmp = tmp->next;
			}
			tmp->next = p;
			p->next = current;
		}
		else 
		{
			first = p;
			p->next = tmp;
		}
		size_++;
	}
}
//删除一个结点并释放相应的内存空间
void CPPList::remove(ListNode *current)
{
	ListNode *tmp = first;
	if (current == NULL ||((current->next == NULL)&&(is_empty())))   //当前结点为空或当前链表不为空但当前结点为尾结点时
	{                                                                //操作无效
		cout << "u cannot delete NULL or the tailor while the list is not empty!" << endl;
	}
	else if (current == first)                                       //当前结点为头节点
	{
		first = first->next;
		delete current;
		size_--;
	}
	else
	{
		
		while (tmp->next != current)
		{
			tmp = tmp->next;
		}
		tmp->next = current->next;
		delete current;
		size_--;
	}
}

void CPPList::clear()                   //释放整个链表的空间，并让链表size为0
{
	while (first->next != NULL)
	{
		ListNode *tmp = first;
		first = first->next;
		delete tmp;
	}
	size_ = 0;
}
