#pragma once

#include <iostream>
using namespace std;

template<typename DATA>
class MyArray
{
	DATA *p_mData;
	int mSize;
	int mCount=18;

public:
	MyArray<DATA>::MyArray(int size = 5);
	MyArray<DATA>::~MyArray();

	void add(const DATA &d);
	void removeAll();
	void removeIndex(int index, int count=1);

	bool isRealloc();

	DATA &getAt(int index);

	DATA& operator[](int index);

	void insert(const DATA & data);
	void insert(const int idnex,const DATA & data);

	bool isFull(){
		if (mCount == mSize){
			return true;
		}
		return false;
	}

	int getLength();
};

template<typename DATA>
MyArray<DATA>::MyArray(int size = 5)
{
	p_mData = new DATA[size];
	mSize = 0;
	mCount = size;
}

template<typename DATA>
MyArray<DATA>::~MyArray()
{
	delete[]p_mData;
	mSize = 0;
	mCount = 0;
}

template<typename DATA>
DATA& MyArray<DATA>::operator[](int index){
	return p_mData[index];
}

template<typename DATA>
DATA & MyArray<DATA>::getAt(int index){
	return p_mData[index];
}

template<typename DATA>
void MyArray<DATA>::add(const DATA &d){
	if (isFull()){
		if (!isRealloc()){
			cout << "内存不足,数据拷贝失败" << endl;
			return ;
		}
	}
	p_mData[mSize++] = d;
}

template<typename DATA>
bool MyArray<DATA>::isRealloc(){
	int size = mCount * 2 + 1;
	DATA* temp = new DATA[size];
	memcpy_s(temp, sizeof(DATA)*size, p_mData, sizeof(DATA)*mSize);
	delete[]p_mData;
	p_mData = temp;
	mCount = size;
	return true;
}

template<typename DATA>
void MyArray<DATA>::removeAll(){
	mSize = 5;
	mCount = 5;
	delete[]p_mData;
	p_Data = new DATA[mSize];
}

template<typename DATA>
void MyArray<DATA>::removeIndex(int index, int nCount=1){
	if (index<0 || index>mSize){
		cout << "输入的索引越界" << endl;
		return;
	}
	if (nCount <0 || (index + nCount)>mSize){
		cout << "输入的数量索引越界" << endl;
		return;
	}
	int shegxia = mSize - nCount - index;
	memmove(p_mData + index, p_mData + index + nCount, sizeof(DATA)*shegxia);
	mSize -= nCount;
}

template<typename DATA>
void MyArray<DATA>::insert(const DATA & data){
	add(data);
}

template<typename DATA>
void MyArray<DATA>::insert(const int index, const DATA & data){
	if (index<0 || index>mSize){
		cout << "插入的数据索引越界" << endl;
		return;
	}
	int size = mCount * 2 + 1;
	int tempSize = 0;
	DATA* temp = NULL;
	if (mSize + 1 > mCount){
		temp = new DATA[size];
		tempSize = size;
	}
	else{
		temp = new DATA[mCount];
		tempSize = mCount;
	}

	memcpy_s(temp, sizeof(DATA)*tempSize, p_mData, sizeof(DATA)*index);
	int tempInedex = index;
	temp[tempInedex++] = data;
	memmove(temp + index+1, p_mData + index , sizeof(DATA)*(mSize - index));
	delete []p_mData;
	p_mData = temp;
	mSize++;
}


template<typename DATA>
int MyArray<DATA>::getLength(){
	return mSize;
}
