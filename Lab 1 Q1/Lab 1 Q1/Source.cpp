#include <iostream>
using namespace std;
void bubbleSort(int array[], int n);
int binarySearch(int key, int array[], int n);
int main(){
	int i = 1;
	cout << i / 2 << endl;
	cin >> i;
	/*int i = 0;
	int array[8] = { 1, 4, 3, 1, 5, 6, 7, 8 };
	int n = sizeof(array) / sizeof(*array);

	bubbleSort(array, n);
	for (int i = 0; i < n; i++){
		cout << array[i];
	}
	cout << endl;
	int index = binarySearch(4, array, n);
	cin >> i;*/
	return 0;
}

// bubbleSort
void bubbleSort(int array[], int n){
	for (int i = 0; i < (n - 1); i++){
		// run for loop n - i times
		for (int j = 1; j < (n - i); j++){
			// swap if array[j - 1] > array[j]
			if (array[j - 1] > array[j]){
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}// if
		}// inner for
	}// outter for
}// bubbleSort


// binarySearch
int binarySearch(int key, int array[], int n){
	n = n - 1;
	int mid = n / 2;
	int prev = 0;
	bool found = false;
	cout << array[0] << "ARRY 0" << array[n - 1] << "ARRY N" << endl;
	if (array[0] > key || array[n] < key){
		return -1;
	} else{
		while (!found){
			if (array[mid] < key){
				mid = (mid + n) / 2;
				if (prev == mid){
					mid++;
				}
			} else if (array[mid] == key){
				found = true;
			} else{
				mid /= 2;
				if (prev == mid){
					mid++;
				}
			}
			prev = mid;
		} // while
	} // else
	return mid;
}// binarySearch