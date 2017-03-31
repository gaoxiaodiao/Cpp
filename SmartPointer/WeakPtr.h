/*
*�ļ�˵��:week_ptr��ʹ�ó���
*����:��С��
*����:2017-03-31
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
#include<memory>
#if 0
//ѭ�����õĳ���
template<typename T>
struct ListNode{
	T _value;
	std::shared_ptr<ListNode> _prev;
	std::shared_ptr<ListNode> _next;
	ListNode(const T & value)
		:_value(value)
		,_prev(NULL)
		,_next(NULL){}
};
void TestWeekPtr(){
	std::shared_ptr<ListNode<int>> sp1(new ListNode<int>(10)); 
	std::shared_ptr<ListNode<int>> sp2(new ListNode<int>(20));
	sp1->_next = sp2;
	sp2->_prev = sp1;
	//��������
	std::cout<<sp1.use_count()<<std::endl;
	std::cout<<sp2.use_count()<<std::endl;
}
#endif

//week_ptr��C++11��,���ұ�������VS10,���Ա��벻��ȥ....ͷ��!
template<typename T>
struct ListNode{
	T _value;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	ListNode(const T & value)
		:_value(value)
		,_prev(NULL)
		,_next(NULL){}
};
void TestWeekPtr(){
	std::shared_ptr<ListNode<int>> sp1(new ListNode<int>(10)); 
	std::shared_ptr<ListNode<int>> sp2(new ListNode<int>(20));
	sp1->_next = sp2;
	sp2->_prev = sp1;

	std::cout<<sp1.use_count()<<std::endl;
	std::cout<<sp2.use_count()<<std::endl;
}