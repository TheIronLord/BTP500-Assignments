#include "a1.h"

void main(){
	DList<int> list;
	

	list.push_back(6);
	list.push_back(5);
	list.push_back(1);
	list.push_back(3);
	list.push_back(8);
	list.push_back(4);
	list.push_back(7);




	list.qSort();
	list.print();
	cout << "====================" << endl;
	list.sortIterative();
	list.print();

	int i;
	cin >> i;
}