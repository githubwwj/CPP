#include "MyArray.h"


void main(){

	MyArray<float> arr;

	float i = 0;
	while (i < 10){
		arr.add(i++);
	}
	i = 0;
	arr.removeIndex(5,5);
	int nSize = arr.getLength();
	while (i < nSize){
		cout << arr[i] <<"\t" << arr.getAt(i)<< endl;
		i++;
	}

	arr.insert(0, 100);
	nSize = arr.getLength();
	cout << "size=" << nSize<<endl;
	i = 0;
	while (i < nSize){
		cout << arr[i] << "\t" << arr.getAt(i) << endl;
		i++;
	}

	system("pause");
}