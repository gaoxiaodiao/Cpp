/*
*文件说明:智能指针之AutoPtr
*作者:高小调
*日期:2017-03-30
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
template<typename T>
class AutoPtr{
public:
	//构造函数
	AutoPtr(T * ptr = NULL)
		:_ptr(ptr){}
	//拷贝构造
	AutoPtr(AutoPtr& ap){
		//转移管理权
		_ptr = ap._ptr;
		ap._ptr = NULL;
	}
	//赋值运算符重载
	AutoPtr &operator=(AutoPtr &ap){
		if(ap._ptr != _ptr){
			AutoPtr tmp(ap);
			std::swap(_ptr,tmp._ptr);
		}//由析构函数去管理tmp
		return *this;
	}
	//析构函数
	~AutoPtr(){
		if(_ptr!=NULL){
			delete _ptr;
			_ptr = NULL;
		}
	}
private:
	T *_ptr;
};

void TestAutoPtr(){
	AutoPtr<int> ap1(new int(100));
	AutoPtr<int> ap2(new int(200));
	AutoPtr<int> ap3(ap1);
	AutoPtr<int> ap4(ap2);
	ap3 = ap4;
}