//Simple Sorts
#include<iostream>
using namespace std;

void bubbleSort(int arry[], int size){

	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (arry[j] > arry[j + 1]){
				int temp = arry[j + 1];
				arry[j + 1] = arry[j];
				arry[j] = temp;
			}
		}
	}
}

void selectionSort(int arry[], int size){
	int hold = 0;
	int swapIndx = 0;
	bool swap = false;
	for (int i = 0; i < size - 1; i++){
		for (int j = i; j < size - 1; j++){
			if (arry[j] > arry[j + 1]){
				hold = arry[j + 1];
				swapIndx = j + 1;
				swap = true;
			}
		}
		if (swap){
			int temp = arry[i];
			arry[i] = hold;
			arry[swapIndx] = temp;
			swap = false;
		}
	}
}

void insertionSort(int arry[], int size){
	int i, j;

	for (i = 0; i < size; i++){
		int curr = arry[i];

		for (j = i; j > 0 && arry[j - 1] > curr; j--){
			arry[j] = arry[j - 1];
		}
		arry[j] = curr;
	}
}

int main(){
	int arry[5]{5, 4, 3, 2, 1};

	//bubbleSort(arry, 5);
	//selectionSort(arry, 5);
	insertionSort(arry, 5);

	int j = 0;
	while (j < 5){
		cout << arry[j] << endl;
		j++;
	}
	double m = 14 % 15;
	cout << "MODULOUS: " <<  m << endl;


	int i = 0;
	cin >> i;
}

