//=================================================sorting algo========================================================


/*
//bubble sort
//boj2750
#include<iostream>

using namespace std;

void get_num(int arr[], int n);
void bubbleSort(int arr[], int n);

int main(void) {
	int n;
	cin >> n;

	int arr[1000];
	get_num(arr, n);
	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout<< arr[i]<<"\n";
	}
	return 0;
}

void get_num(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int num=0;
		cin >> num;
		arr[i] = num;
	}
	//return; void함수로 return 값 없음
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
*/