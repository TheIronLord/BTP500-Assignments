#include"Header.h"

void main(){
	SList<int> l;
	l.push_Front(5);
	l.push_Front(10);
	l.push_Front(15);
	l.push_Back(4);
	l.push_Back(3);
	l.push_Back(2);
	l.push_Back(1);

	l.printf();

	int i;
	cin >> i;
}