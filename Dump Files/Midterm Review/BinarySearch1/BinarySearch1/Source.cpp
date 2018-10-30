#include <iostream>
using namespace std;

int factorialLinear(int n){
	int value;
	if (n == 1){
		return 1;
	} else if (n == 0){
		return 0;
	}
	else{
		value = n;
		while (n > 1){
			if (n - 1 != 0){
				value = value * (n - 1);
				n--;
			}
		}
	}
	return value;
}

int factorialRecursion(int n){
	int rc;
	if (n == 1 || n == 0){
		return 1;
	}
	else{
		 rc = n * factorialRecursion(n - 1);
	}
	return rc;
}

int fibonacciLinear(int n){
	int rc;
	if (n == 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	} else{
		int i = 1;
		rc = 1;
		int nex = 0;
		int ans;
		while (i < n){
			ans = rc + nex;
			nex = rc;
			rc = ans;
			
			++i;
		}
	}
	return rc;
}

int fibonacciRecursive(int n){
	int rc;
	if (n <= 2){
		return 1;
	}
	else{
		rc = fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
	}
	return rc;
}

int BinarySearch(int arr[], int size, int key){
	int rc = -1;
	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high && rc == -1){
		mid = (low + high) / 2;

		if (arr[mid] > key){
			high = mid - 1;
		} else if (arr[mid] < key){
			low = mid + 1;
		} else{
			rc = mid;
		}
	}

	return rc;
}

void main(){
	int arry[5] = { 1, 2, 3, 4, 5 };
	int ans = BinarySearch(arry, 5, 4);

	cout << "Position is at :" << ans << endl;

	int f = 5;
	ans = factorialLinear(f);

	cout << "FactorialLinear :" << ans << endl;

	f = 5;
	ans = factorialRecursion(f);

	cout << "FactorialRecursion :" << ans << endl;

	f = 5;
	ans = fibonacciLinear(f);

	cout << "FibonacciLinear :" << ans << endl;

	f = 5;
	ans = fibonacciRecursive(f);

	cout << "FibonacciRecursive :" << ans << endl;

	int i;
	cin >> i;
}