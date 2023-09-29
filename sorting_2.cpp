//MergeSort

/*
#include<iostream>
#define SIZE 10
using namespace std;

void get_array(int arr[]);
void merge(int arr[], int left,int mid, int right);
void mergeSort(int arr[],int left,int right);

int sorted[SIZE];

void get_array(int arr[]) {
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
}

void merge(int arr[], int left,int mid, int right) {
	int i, j, k,l;
	//���ĵ� ���� ����Ʈ �ε���, ���ĵ� ������ ����Ʈ �ε���, ���� ���� ����Ʈ �ε���
	i = left;
	j = mid + 1;
	k = left;

	//sorted�� �����ϸ� �� ä���
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j])
			sorted[k++] = arr[i++];//�� �־��ְ� ���� ��ҷ� �Ѿ
		else
			sorted[k++] = arr[j++];
	}
	
	if (i > mid) {//������ ���ҵ鸸 ���� ��� �ϰ� ����
		for (l = i; l <= right; l++) {
			sorted[k++] = arr[l];
		}
	}
	else{
		for (l = i; l <= mid; l++) {
			sorted[k++] = arr[l]; //!!!!�� �߸� ������Ŵ!!!!
		}
	}

	for (int i = left; i <= right; i++)
		arr[i] = sorted[i];
}

void mergeSort(int arr[],int left,int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		for (int i = left; i <= right; i++) {
			sorted[i] = arr[i];
		}
		merge(sorted, left, mid, right);
	}
}

int main(void) {
	int arr[SIZE];

	get_array(arr);
	mergeSort(arr, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
		cout << arr[i];

	return 0;
}*/
/*
#include<iostream>
#define SIZE 10

using namespace std;

void get_array(int arr[]);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int sorted[SIZE];

void get_array(int arr[]) {
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
}

void merge(int arr[], int left, int mid, int right) {
	int i, j, k;

	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	while (i <= mid)
		sorted[k++] = arr[i++];
	while (j <= right)
		sorted[k++] = arr[j++];

	for (int i = left; i <= right; i++)
		arr[i] = sorted[i];
}

void mergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main(void) {
	int arr[SIZE];

	get_array(arr);
	mergeSort(arr, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";

	return 0;
}
*/

//�������
//radix sort

//boj2751

#include <iostream>
#include <queue>

using namespace std;

#define MAX_NUM (1000001)

void Input();
void RadixSort();
void PrintAnswer();

int N, maxValue;
queue<int> q[10];
int radixArray[MAX_NUM];

int main()
{
	// sync off
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	RadixSort();
	PrintAnswer();
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> radixArray[i];
	}
}

void RadixSort()
{
	int radix = 1;

	// ������ ����� ���� �����Ѵ�.
	for (int i = 0; i < N; i++)
	{
		radixArray[i] += 1000000;

		if (radixArray[i] > maxValue)
		{
			maxValue = radixArray[i];
		}
	}

	// ��� ���� ����
	while ((maxValue / radix) > 0)
	{
		for (int i = 0; i < N; i++)
		{
			q[((radixArray[i] / radix) % 10)].push(radixArray[i]);
		}

		int index = 0;
		for (int i = 0; i < 10; i++)
		{
			while (!q[i].empty())
			{
				radixArray[index++] = q[i].front();
				q[i].pop();
			}
		}

		radix *= 10;
	}

	// ������� ����ġ�� �ٽ� ���ش�.
	for (int i = 0; i < N; i++)
	{
		radixArray[i] -= 1000000;
	}
}

void PrintAnswer()
{
	for (int i = 0; i < N; i++)
	{
		cout << radixArray[i] << "\n";
	}
}