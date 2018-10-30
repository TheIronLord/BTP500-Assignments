#include <iostream>
using namespace std;

int factorialLinear(int n){
	int prev = n;

	while (n > 1){
		prev *= (n - 1);
		n--;
	}

	return prev;
}

int factorialRecursion(int n){
	int rc;
	if (n == 1){
		return 1;
	}
	rc = n * factorialRecursion(n - 1);
	return rc;
}

int binarySearch(int arry[], int size, int key){
	int rc = -1;
	int low = 0;
	int high = size - 1;
	int mid = 0;

	while (rc == -1 && low <= high){
		mid = (low + high) / 2;

		if (arry[mid] < key){
			high = mid - 1;
		}
		else if (arry[mid] > key){
			low = mid + 1;
		}
		else{
			rc = mid;
		}
	}
	return rc;
}

int fibonacciLinear(int n){
	int prev = 1;
	int ans;
	int value = 1;
	if (n == 0 || n == 1){
		return 0;
	} else if (n == 2){
		return 1;
	}
	else{
		while (n > 2){
			ans = value + prev;
			prev = value;
			value = ans;
			--n;
		}
	}
	return value;
}

int fibonacciRecursion(int n){
	int rc;
	if (n == 0 || n == 1 || n == 2){
		return 1;
	}
	rc = fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);

	return rc;
}

class StackArry{
	int* arry;
	int back;
	int size;
public:
	StackArry(){
		arry = new int[5];
		back = 0;
		size = 5;
	}
	void push(int data){
		isFull();
		arry[back] = data;
		++back;
	}
	void pop(){
		if ((back - 1) > 0){
			back--;
		}
	}
	void isFull(){
		if (back == (size + 1)){
			int* temp = new int[size * 2];
			int i = 0;
			while (i < back){
				temp[i] = arry[i];
				++i;
			}
			//delete[]arry;
			arry = temp;
		}
	}

	bool isEmpty(){
		return (back == 0);
	}

	int top(){
		return arry[back - 1];
	}
};

class Queue{
	int front;
	int back;
	int* arry;
	int size;
public:
	Queue(){
		arry = new int[5];
		front = 0;
		back = 0;
		size = 5;
	}
	bool isEmpty(){
		return(front == back);
	}
	void isFull(){
		if ((size + 1) == back || back == front){
				int * temp = new int[size * 2];
				int i = 0;
				int f = front - 1;
				while (f < (back - 1)){
					if (f < size){
						temp[i] = arry[f];
					}
					if (f == size){
						f = 0;
						temp[i] = arry[f];
						++f;
						++i;
					} else{
						++f;
						++i;
					}
				}
				arry = temp;
		}
		else if(back == (size + 1) && front != 0){
			back = 0;
		}
	}
	int front_(){
		return arry[front];
	}
	void enqueue(int data){
		isFull();
		arry[back] = data;
		back++;
	}
	void dequeue(){
		++front;
		isFull();
	}
};

int main(){

	int ans;
	ans = factorialLinear(5);
	cout << "FACTORIALLINEAR: " << ans << endl;

	ans = factorialRecursion(5);
	cout << "FACTORIALRECURSION: " << ans << endl;

	int arry[5] = { 1, 2, 3, 4, 5 };
	ans = binarySearch(arry, 5, 3);
	cout << "BINARYSEARCH: " << ans << endl;

	ans = fibonacciLinear(5);
	cout << "FIBONACCILINEAR: " << ans << endl;

	ans = fibonacciRecursion(5);
	cout << "FIBONACCIRECURSION: " << ans << endl;


	StackArry s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	int t = s.top();

	cout << "TOP: " << t << endl;


	cout << "*****IS GROWING*****" << endl;
	s.push(0);
	s.push(5);
	s.pop();

	int j = 6;
	while (j > 0){
		cout << s.top();
		cout << endl;
		s.pop();
		j--;
	}

	Queue q;
	q.enqueue(10);
	q.enqueue(9);
	q.enqueue(8);
	q.enqueue(7);
	q.enqueue(6);
	
	q.dequeue();
	q.enqueue(7);
	q.enqueue(15);

	j = 6;
	while (j > 0){
		cout << q.front_();
		cout << endl;
		q.dequeue();
		j--;
	}
	int i;
	cin >> i;
 
	return 0;
}