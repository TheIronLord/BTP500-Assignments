#include "a1.h"

#include <iostream>
using namespace std;

class DListTester{
	bool check;
public:
	DListTester(){
		check = true;
	}
	void pop_front_test(){
		DList<int> testPopFront;

		cout << "pop_front Test" << endl;
		cout << "==============" << endl;

		int arry[3] {1, 2, 3};
		int i = 0;

		testPopFront.push_front(1);
		testPopFront.push_front(2);
		testPopFront.push_front(3);

		testPopFront.pop_front();
		testPopFront.pop_front();
		testPopFront.pop_front();

		DList<int>::iterator it = testPopFront.begin();

		if (!testPopFront.empty()){
			check = false;
		}

		testPopFront.pop_front();

		if (check){
			cout << "*****Passed the pop_front Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the pop_front Test-----" << endl;
			cout << endl;
		}

		check = true;
	}
	void pop_back_test(){
		DList<int> testPopBack;

		cout << "pop_back Test" << endl;
		cout << "==============" << endl;

		int arry[3] {1, 2, 3};
		int i = 0;

		testPopBack.push_front(1);
		testPopBack.push_front(2);
		testPopBack.push_front(3);

		testPopBack.pop_back();
		testPopBack.pop_back();
		testPopBack.pop_back();

		DList<int>::iterator it = testPopBack.begin();

		if (!testPopBack.empty()){
			check = false;
		}

		testPopBack.pop_back();


		if (check){
			cout << "*****Passed the pop_back Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the pop_back Test-----" << endl;
			cout << endl;
		}

		check = true;
	}
	void push_front_test(){
		DList<int> testPushFront;

		cout << "push_front Test" << endl;
		cout << "==============" << endl;

		int arry[3] {3, 2, 1};
		int i = 0;

		testPushFront.push_front(1);
		testPushFront.push_front(2);
		testPushFront.push_front(3);

		DList<int>::iterator it = testPushFront.begin();

		while (it != testPushFront.end()){
			if (arry[i] != *it){
				check = false;
			}
			++it;
			++i;
		}

		if (check){
			cout << "*****Passed the push_front Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the push_front Test-----" << endl;
			cout << endl;
		}

		check = true;
	}
	void push_back_test(){
		DList<int>testPushBack;

		cout << "push_back Test" << endl;
		cout << "==============" << endl;

		int arry[3] {1, 2, 3};
		int i = 0;

		testPushBack.push_back(1);
		testPushBack.push_back(2);
		testPushBack.push_back(3);

		DList<int>::iterator it = testPushBack.begin();

		while (it != testPushBack.end()){
			if (arry[i] != *it){
				check = false;
			}
			++it;
			++i;
		}

		if (check){
			cout << "*****Passed the push_back Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the push_back Test-----" << endl;
			cout << endl;
		}

		check = true;
	}
	void copy_test(){
		DList<int>testCopy;

		cout << "copy_test Test" << endl;
		cout << "==============" << endl;

		DList<int> temp;
		temp.push_back(5);
		temp.push_back(4);
		temp.push_back(6);

		testCopy = temp;

		DList<int>::iterator it = testCopy.begin();
		DList<int>::iterator it2 = temp.begin();

		while (it != testCopy.end() && it2 != temp.end()){
			if (*it != *it2){
				check = false;
			}
			++it;
			++it2;
		}

		if (check){
			cout << "*****Passed the copy_test Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the copy_test Test-----" << endl;
			cout << endl;
		}

		check = true;
	}
	void move_test(){

		cout << "move_test Test" << endl;
		cout << "==============" << endl;
		DList<int> testMveMain;

		testMveMain.push_back(1);
		testMveMain.push_back(2);
		testMveMain.push_back(3);

		DList<int> testMve = std::move(testMveMain);

		if (!testMveMain.empty()){
			check = false;
		}

		int arry[3] = { 1, 2, 3 };
		int i = 0;

		DList<int>::iterator it = testMve.begin();

		while (it != testMve.end()){
			if (*it != arry[i]){
				check = false;
			}
			i++;
			++it;
		}

		if (check){
			cout << "*****Passed the move_test Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the move_test Test-----" << endl;
			cout << endl;
		}

		check = true;
	}
	void empty_test(){
		cout << "empty_test Test" << endl;
		cout << "==============" << endl;
		DList<int>emptyTest;
		if (!emptyTest.empty()){
			check = false;
		}

		if (check){
			cout << "*****Passed the empty_test Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the empty_test Test-----" << endl;
			cout << endl;
		}
	}
	void begin_test(){
		cout << "begin_test Test" << endl;
		cout << "==============" << endl;

		DList<int> beginTest;
		beginTest.push_back(3);
		DList<int>::iterator it = beginTest.begin();

		int num = 3;

		if (*it != num){
			check = false;
		}

		if (check){
			cout << "*****Passed the begin_test Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the begin_test Test-----" << endl;
			cout << endl;
		}
		check = true;
	}
	void end_test(){
		cout << "end_test Test" << endl;
		cout << "==============" << endl;

		DList<int> endTest;
		endTest.push_front(3);
		int num = 3;

		DList<int>::iterator itEnd = endTest.end();
		DList<int>::iterator itBegin = endTest.begin();
		itBegin++;
		if (*itEnd == num){
			check = false;
		}
		if (itBegin != itEnd){
			check = false;
		}

		if (check){
			cout << "*****Passed the end_test Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the end_test Test-----" << endl;
			cout << endl;
		}
		check = true;
	}
	void insert_test(){
		cout << "insert_test Test" << endl;
		cout << "==============" << endl;

		DList<int>insertTest;
		insertTest.push_back(3);
		insertTest.insert(insertTest.end(), 4);
		int temp = 4;
		DList<int>::iterator itEnd = insertTest.end();
		DList<int>::iterator itBegin = insertTest.begin();


		//Check if the data begin inserted ends up at the sentinels m_head & m_tail
		//And see if i put in the m_head and m_tail into the insert function will it be
		//able to handle the situation

		if (*itEnd == temp){
			check = false;
		}

		itBegin--;
		insertTest.insert(itBegin, 5);
		int temp2 = 5;

		if (*itBegin == temp2){
			check = false;
		}
		++itBegin;
		++itBegin;
		insertTest.insert(itBegin, 6);

		DList<int>::iterator it = insertTest.begin();
		int arry[4] = { 5, 6, 3, 4 };
		int i = 0;

		while (it != itEnd){
			if (arry[i] != *it){
				check = false;
			}
			i++;
			++it;
		}

		if (check){
			cout << "*****Passed the insert_test Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the insert_test Test-----" << endl;
			cout << endl;
		}
		check = true;
	}
	void erase_test(){
		cout << "erase_test Test" << endl;
		cout << "==============" << endl;

		DList<int> eraseTest;
		eraseTest.push_back(5);
		eraseTest.erase(eraseTest.begin());

		if (!eraseTest.empty()){
			check = false;
		}

		eraseTest.push_back(5);
		eraseTest.push_back(4);
		eraseTest.push_back(3);
		eraseTest.push_back(2);
		eraseTest.push_back(1);
		eraseTest.push_back(0);

		eraseTest.erase(eraseTest.begin(), eraseTest.end());

		if (!eraseTest.empty()){
			check = false;
		}

		if (check){
			cout << "*****Passed the erase_test Test*****" << endl;
			cout << endl;
		}
		else{
			cout << "-----Failed the erase_test Test-----" << endl;
			cout << endl;
		}
		check = true;
	}
	void test_all(){
		cout << "test_all Test" << endl;
		cout << "==============" << endl;

		pop_front_test();
		pop_back_test();
		push_front_test();
		push_back_test();
		copy_test();
		move_test();
		empty_test();
		begin_test();
		end_test();
		insert_test();
		erase_test();
	}
};
#include <string>

void main(){
	bool contnue = true;
	DListTester listTest;
	int ans;
	
	cout << "Assignment 1 Tester" << endl;
	cout << "===================" << endl;
	cout << "1: Test pop_front()" << endl;
	cout << "2: Test pop_back()" << endl;
	cout << "3: Test push_front()" << endl;
	cout << "4: Test push_back()" << endl;
	cout << "5: Test copy" << endl;
	cout << "6: Test move" << endl;
	cout << "7: Test empty" << endl;
	cout << "8: Test begin/end" << endl;
	cout << "9: Test insert" << endl;
	cout << "10: Test erase" << endl;
	cout << "11: Test All" << endl;
	cout << "0: Exit" << endl;
	while (contnue){

		cout << "#"; cin >> ans;

		switch (ans){
			case 1:
				listTest.pop_front_test();
			break;
			case 2:
				listTest.pop_back_test();
			break;
			case 3:
				listTest.push_front_test();
			break;
			case 4:
				listTest.push_back_test();
			break;
			case 5:
				listTest.copy_test();
			break;
			case 6: 
				listTest.move_test();
			break;
			case 7:
				listTest.empty_test();
			break;
			case 8:
				listTest.begin_test();
				listTest.end_test();
			break;
			case 9:
				listTest.insert_test();
			break;
			case 10:
				listTest.erase_test();
			break;
			case 11:
				listTest.test_all();
			break;
			
			default:
				contnue = false;
			break;
		}
	}
}