/*
*�ļ�˵��:����ָ��֮AutoPtr
*����:��С��
*����:2017-03-30
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
template<typename T>
class AutoPtr{
public:
	//���캯��
	AutoPtr(T * ptr = NULL)
		:_ptr(ptr){}
	//��������
	AutoPtr(AutoPtr& ap){
		//ת�ƹ���Ȩ
		_ptr = ap._ptr;
		ap._ptr = NULL;
	}
	//��ֵ���������
	AutoPtr &operator=(AutoPtr &ap){
		if(ap._ptr != _ptr){
			AutoPtr tmp(ap);
			std::swap(_ptr,tmp._ptr);
		}//����������ȥ����tmp
		return *this;
	}
	//��������
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