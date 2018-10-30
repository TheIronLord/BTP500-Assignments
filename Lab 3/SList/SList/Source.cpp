

#include "Dlist.h"
#include "Slist.h"

void foo(int arr[]){
	int arrr[10];

	int i = sizeof(arrr);

	cout << "SIZE: " << i << endl;

	cin >> i;
}
void main(void){
	int arr[10];
	int j = sizeof(arr);
	cout << "SIZEE: " << j << endl;
	foo(arr);

}
	/*DList<int> list;
	SList<int> list2;
	list.push_front(10);
	list.print();    //10
	cout << "*****1******" << endl;
	list.push_front(5);
	list.push_front(15);
	list.print();    //15 5 10
	cout << "*****2******" << endl;
	list.pop_back();
	list.print();   //15 5
	cout << "*****3******" << endl;
	list.pop_back();
	list.pop_back();
	list.print();  //list is empty (should print nothing)
	cout << "*****4******" << endl;
	list.push_back(1);
	list.print();   //1
	cout << "*****5******" << endl;
	list.push_back(2);
	list.push_back(3);
	list.print();   //1 2 3 
	cout << "*****6******" << endl;
	list.pop_front();
	list.print();   //2 3 
	cout << "*****7******" << endl;
	list.pop_front();
	list.pop_front();
	list.print();   //prints nothing, list is empty 
	cout << "*****8******" << endl;
	list.push_back(20);
	list.push_front(21);
	list.push_back(22);
	list.push_front(23);
	list.print();  //prints: 23 21 20 22 

	list2.push_front(10);
	list2.print();    //10
	cout << "*****A******" << endl;
	list2.push_front(5);
	list2.push_front(15);
	list2.print();    //15 5 10
	cout << "*****B******" << endl;
	list2.pop_back();
	list2.print();   //15 5
	cout << "*****C******" << endl;
	list2.pop_back();
	list2.pop_back();
	list2.print();  //list2 is empty (should print nothing)
	cout << "*****D******" << endl;
	list2.push_back(1);
	list2.print();   //1
	cout << "*****E******" << endl;
	list2.push_back(2);
	list2.push_back(3);
	list2.print();   //1 2 3 
	cout << "*****F******" << endl;
	list2.pop_front();
	list2.print();   //2 3 
	cout << "*****G******" << endl;
	list2.pop_front();
	list2.pop_front();
	list2.print();   //prints nothing, list2 is empty 
	cout << "*****H******" << endl;
	list2.push_back(20);
	list2.push_front(21);
	list2.push_back(22);
	list2.push_front(23);
	list2.print();  //prints: 23 21 20 22 

	int i;
	cin >> i;
}*/