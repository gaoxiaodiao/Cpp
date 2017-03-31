/*
*文件说明:模拟实现scoped_ptr
*作者:高小调
*日期:2017-03-31
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
template<typename T>
class ScopedPtr{
public:
	//构造函数
	ScopedPtr(T* ptr = NULL)
		:_ptr(ptr){}
	//析构函数
	~ScopedPtr(){
		if(_ptr!=NULL){
			delete _ptr;
			_ptr=NULL;
		}
	}
private:
	//拷贝构造
	ScopedPtr(const ScopedPtr &sp);
	//赋值运算符重载
	ScopedPtr& operator=(const ScopedPtr &sp);
private:
	T *_ptr;
};

void TestScopedPtr(){
	ScopedPtr<int> sp1(new int(10));
	ScopedPtr<int> sp2(new int(20));
	//ScopedPtr<int> sp3(sp1);		//错误
	//sp1 = sp2						//错误
}