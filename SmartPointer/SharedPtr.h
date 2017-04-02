/*
*文件说明:模拟实现shared_ptr
*作者:高小调
*日期:2017-03-31
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
template<typename T>
class SharedPtr{
public:
	//构造函数
	SharedPtr(T *ptr=NULL)
		:_ptr(ptr)
		,_count(NULL){
			if(ptr!=NULL){
				_count = new int(1);
				std::cout<<_ptr<<" Is Created"<<std::endl;
			}
	}
	//拷贝构造
	SharedPtr(const SharedPtr & sp)
		:_ptr(sp._ptr)
		,_count(sp._count){
			if(sp._count!=NULL){
				++(*_count);
			}
	}
	//赋值运算符重载
	SharedPtr& operator=(const SharedPtr &sp){
		if(_ptr!=sp._ptr){
			SharedPtr tmp(sp);
			std::swap(_ptr,tmp._ptr);
			std::swap(_count,tmp._count);
		}
		return *this;
	}
	//析构函数
	~SharedPtr(){
		if(_count!=NULL && --(*_count)==0){
			std::cout<<_ptr<<" Is Destory"<<std::endl;
			delete _ptr;
			delete _count;
			_ptr = NULL;
			_count = NULL;
		}
	}
private:
	T* _ptr;
	int *_count;
};

void TestSharedPtr(){
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(new int(20));
	SharedPtr<int> sp3(new int(30));
	SharedPtr<int> sp4(sp1);
	sp2 = sp1;
	sp3 = sp1;
}
