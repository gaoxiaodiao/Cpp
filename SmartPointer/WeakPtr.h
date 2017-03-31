/*
*文件说明:week_ptr的使用场景
*作者:高小调
*日期:2017-03-31
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<memory>
#if 0
//循环引用的场景
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
	//构成死锁
	std::cout<<sp1.use_count()<<std::endl;
	std::cout<<sp2.use_count()<<std::endl;
}
#endif

//week_ptr在C++11中,而我编译器是VS10,所以编译不过去....头疼!
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