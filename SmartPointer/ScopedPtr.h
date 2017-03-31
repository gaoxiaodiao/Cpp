/*
*�ļ�˵��:ģ��ʵ��scoped_ptr
*����:��С��
*����:2017-03-31
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
template<typename T>
class ScopedPtr{
public:
	//���캯��
	ScopedPtr(T* ptr = NULL)
		:_ptr(ptr){}
	//��������
	~ScopedPtr(){
		if(_ptr!=NULL){
			delete _ptr;
			_ptr=NULL;
		}
	}
private:
	//��������
	ScopedPtr(const ScopedPtr &sp);
	//��ֵ���������
	ScopedPtr& operator=(const ScopedPtr &sp);
private:
	T *_ptr;
};

void TestScopedPtr(){
	ScopedPtr<int> sp1(new int(10));
	ScopedPtr<int> sp2(new int(20));
	//ScopedPtr<int> sp3(sp1);		//����
	//sp1 = sp2						//����
}