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
	//return; void�Լ��� return �� ����
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


//boj2587
//2750����
/*
#include<iostream>
#define N   5
using namespace std;

void get_num(int arr[]);
void bubbleSort(int arr[]);

static int tot = 0;

int main(void) {
	int arr[N];

	get_num(arr);
	bubbleSort(arr);
	//���ڷ� arr[N]�� ���� �� �迭�� �ƴ� ���� �ϳ� �Ѿ

	cout << tot / 5 << "\n" << arr[2];

	return 0;
}
void get_num(int arr[]) {
	for (int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;
		tot += num;
		arr[i] = num;
	}
}

void bubbleSort(int arr[]) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
*/

//selectSort
//boj25305
#include <iostream>
using namespace std;

void selectionSort(int arr[],int n);
void get_num(int arr[],int n);

int main(void) {
	int score[1000];
	int n,k;

	cin>>n>>k;
	get_num(score, n);
	selectionSort(score,n);
	
	cout << score[n-k];

	return 0;
}

void get_num(int arr[],int n) {
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		arr[i] = num;
	}
}

/*
void selectionSort(int arr[],int n) {
	for (int i = 0; i < n; i++) {
		int Max;

		for (int j = 0; j <n-i; j++) {
			Max = 0;
			if (arr[Max] < arr[j])
				Max = j;
			else continue;
		}
		int tmp;
		tmp = arr[n - i];
		arr[n - i] = arr[Max];
		arr[Max] = tmp;
	}
}
*/

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) { // n-1�� �ݺ�
		int minIndex = i; // �ּҰ��� �ε����� i�� �ʱ�ȭ

		// i ������ ���� �߿��� �ּҰ��� ã��
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		// �ּҰ��� ���� ��ġ(i)�� ��ȯ
		if (minIndex != i) {
			int tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
		}
	}
}
