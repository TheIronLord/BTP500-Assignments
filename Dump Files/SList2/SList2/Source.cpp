#include "Header.h"

void main(){
	SList<int> l;
	l.pop_Back();
	l.pop_Front();
	l.push_Back(15);
	l.push_Front(10);
	l.pop_Back();
	l.pop_Front();
	l.print();
	int i;
	cin >> i;
}