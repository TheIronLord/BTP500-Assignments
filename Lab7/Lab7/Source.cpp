#include "BST.h"
#include <iostream>

using namespace std;

int main(){

	BST tree;
	
	tree.insert(100);
	//tree.insert(90);
	//tree.insert(150);
	//tree.insert(110);
	//tree.insert(120);
	//tree.insert(170);
	//tree.insert(160);
	//tree.insert(250);



	tree.remove(100);

	tree.print();
	return 0;
}