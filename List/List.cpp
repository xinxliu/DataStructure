#include "List.hpp"
#include <iostream>

using namespace std;

//���캯������ʼ��������
ListNode::ListNode()
{
	data_ = 0;
	next = NULL;
}
//��ȡ����ڵ�����
int &ListNode::data()
{
	return data_;
}
//����const��ʽ����ȡ����ڵ㺯��
const int ListNode::data() const
{
	return data_;
}


//���캯������ʼ������
CPPList::CPPList()
{
	size_ = 0;
	last = new ListNode;
	last->next = NULL;
	first = last;
}
//�����������ͷ�������ռ�ռ�
CPPList::~CPPList()
{
	clear();
}
//������sizeΪ�㣬���ʾ����Ϊ��
bool CPPList::is_empty()
{
	if (size_==0)
		return true;
	else
		return false;
}
//��������size
int CPPList::size() 
{
	return size_;
}
//����ͷ
ListNode *CPPList::begin()
{
	return first;
}
//����β
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
//��ѯ��ǰ������һ���
ListNode *CPPList::next(const ListNode *current)
{
	if (begin() == end())
	{
		return NULL;
	}
	else
		return current->next;
}
//const��ʽ
const ListNode *CPPList::next(const ListNode *current) const
{
	if (begin() == end())
	{
		return NULL;
	}
	else
		return current->next;
}
//��������������
void CPPList::append(int data)
{
	ListNode *p = new ListNode;  //��������
	p->data_ = data;
	p->next = last;
	if (is_empty())
	{
		first = p;              //����Ϊ�գ�����������Ϊͷ���
			}
	else                         //���򣬴��������ָ����ָ��β��㣬ԭָ����ָ��β���Ľ��ָ����ָ���������
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
//��ǰ���ǰ������
void CPPList::insert(ListNode *current, int data)
{
	if (is_empty())        //�������Ϊ�գ���˲�����Ч��ֱ�ӷ���
	{
		return;
	}       
	if (current->next == NULL)  //�����ǰ���Ϊβ�ڵ㣬�����append����
	{
		append(data);
	}
	else                    
	{
		ListNode *tmp = first;
		ListNode *p = new ListNode;
		p->data_ = data;
		if (current != first)            //�����ǰ���Ϊͷ�ڵ㣬����������Ϊͷ���
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
//ɾ��һ����㲢�ͷ���Ӧ���ڴ�ռ�
void CPPList::remove(ListNode *current)
{
	ListNode *tmp = first;
	if (current == NULL ||((current->next == NULL)&&(is_empty())))   //��ǰ���Ϊ�ջ�ǰ����Ϊ�յ���ǰ���Ϊβ���ʱ
	{                                                                //������Ч
		cout << "u cannot delete NULL or the tailor while the list is not empty!" << endl;
	}
	else if (current == first)                                       //��ǰ���Ϊͷ�ڵ�
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

void CPPList::clear()                   //�ͷ���������Ŀռ䣬��������sizeΪ0
{
	while (first->next != NULL)
	{
		ListNode *tmp = first;
		first = first->next;
		delete tmp;
	}
	size_ = 0;
}
