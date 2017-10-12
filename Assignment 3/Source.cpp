#include <iostream>
#include "threadedtree.h"

using namespace std;

int main(){
	ThreadedTree<int> tree;

	tree.insert(20);
	tree.insert(30);
	tree.insert(10);
	tree.insert(15);
	tree.insert(5);
	tree.insert(25);
	tree.insert(27);
	tree.insert(18);
	tree.insert(16);

	tree.begin();
	tree.end();
	ThreadedTree<int>::iterator it;
	it = tree.find(17);
	it = tree.find(16);
	return 0;
}