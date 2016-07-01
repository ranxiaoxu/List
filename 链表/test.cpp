#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	ListNode *_next;
	ListNode(const DataType &x)
		:_data(x) 
		,_next(NULL)
	{}
};
class List
{
private:
	ListNode *_head;
	ListNode *_tail;
public:
	List()
		:_head(NULL)
		,_tail(NULL)
	{}
	~List()
	{
		Clear();
	}
	void Clear()
	{
		ListNode *begin = _head;
		while(begin)
		{
			ListNode *del = begin;
			begin = begin->_next;
			delete del;
		}
		_head = _tail = NULL;
	}
	void print()
	{
		ListNode *tmp = _head;
		while(tmp != NULL)
		{
			cout<<tmp->_data<<"->";
			tmp = tmp->_next;
		}
		cout<<"NULL"<<endl;
	}
	void Push_Back(DataType x)
	{
		//1.没有结点 2.有结点
		ListNode *tmp = new ListNode(x);
		if(_head == NULL){
			_head = tmp;
			_tail = tmp;
		}else{
			_tail->_next = tmp;
			_tail = tmp;
		}
	}
	List(List &s)   //传统写法
		:_head(NULL)
		,_tail(NULL)
	{
		ListNode *stmp = s._head;
		_head = new ListNode(stmp->_data);
		_tail = _head;
		stmp = stmp->_next;
		while(stmp->_next != NULL)
		{
			_tail->_next = new ListNode(stmp->_data);
			_tail = _tail->_next;
			stmp = stmp->_next;
		}
		_tail->_next = new ListNode(stmp->_data);
		_tail = _tail->_next;
	}
	List & operator = (const List &s)
	{
		this->~List();
		ListNode *stmp = s._head;
		_head = new ListNode(stmp->_data);
		_tail = _head;
		stmp = stmp->_next;
		while(stmp->_next != NULL)
		{
			_tail->_next = new ListNode(stmp->_data);
			_tail = _tail->_next;
			stmp = stmp->_next;
		}
		_tail->_next = new ListNode(stmp->_data);
		_tail = _tail->_next;
		return *this;
	}
	ListNode *Find(DataType x)
	{
		ListNode *tmp = _head;
		while(tmp != NULL){
			if(x == tmp->_data){
				return tmp;
			}
			tmp = tmp->_next;
		}
		return NULL;
	}
	void Insert(ListNode *pos,DataType x)//在POS节点后插入
	{
		ListNode *tmp = new ListNode(x);
		assert(pos);
		if(pos == _tail){   //如果是尾插，就要更新_tail的值
			tmp->_next = pos->_next;
			pos->_next = tmp;
			_tail = tmp;
		}else{
			tmp->_next = pos->_next;
			pos->_next = tmp;
		}
	}
	void Erase(ListNode *pos)
	{
		ListNode *del;
		ListNode *prev = _head;
		ListNode *tmp = _head;
		assert(pos);
		if(_head == _tail && _head == pos){   //如果只有一个结点
			_head = NULL;
			_tail = NULL;
 		}else{                         //有多个结点
			if(pos == _head){     //如果是头删
				del = _head;
				_head = _head->_next;
			}else{
				while(tmp != NULL){
					prev = tmp;
					tmp = tmp->_next;
					if(tmp == pos){
						del = tmp;
						prev->_next = tmp->_next;
						break;
					}
			}
		}
		delete del;
	}
};
void test1()
{
	List s1;
	s1.Push_Back(1);
	s1.Push_Back(2);
	s1.Push_Back(3);
	s1.Push_Back(4);
	s1.Push_Back(5);

	s1.print();
	List s2(s1);
	s2.print();

	s2 = s1;
	s2.print();

}
void test2()
{
	List s1;
	ListNode *tmp;
	s1.Push_Back(1);
	s1.Push_Back(2);
	s1.Push_Back(3);
	s1.Push_Back(4);
	s1.Push_Back(5);

	s1.print();
	tmp = s1.Find(5);

	s1.Insert(tmp,6);
	s1.print();

	s1.Erase(tmp);
	s1.print();
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}