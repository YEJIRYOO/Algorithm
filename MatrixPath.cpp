/***********************
���� 5 : ��� ��� ���� ���� ���α׷���
20222979 ������
************************/


#include<iostream>
using namespace std;

//�迭 �ʱ�ȭ �Լ�
void getArr(int* arr[],int n) {
	for (int i = 0; i < n + 1; i++) {
		if(i!=0) cout << i<<"�� �Է� : ";
		for (int j=0; j < n + 1; j++) {
			if (i == 0 || j == 0)arr[i][j] = 0;
			else {
				cin >> arr[i][j];
			}
		}
	}
}

//ū �� ��ȯ �Լ�
int Max(int a, int b) {
	a = a > b ? a : b;

	return a;
}

//�̵� ��� ���
void path(int n, int* c[]) {
	int l = n;
	int r = n;
	int s = 2 * n - 1;
	int* al = new int[s];//x��ǥ ���� �迭
	int* ar = new int[s];//y��ǥ ���� �迭

	while (l > 0 && r > 0) {
		//		cout << "(" << l << "," << r << ")";
		s--;
		ar[s] = r;
		al[s] = l;
		if (c[l][r - 1] > c[l - 1][r]) r--;
		else l--;
	}

	for (int i = 0; i < 2*n-1; i++) {
		cout << "(" << al[i] << "," << ar[i] << ")";
		if (i < 2 * n - 2)cout << "->";
	}
	
	//�迭 �Ҵ� ����
	delete[] al;
	delete[] ar;
}

//��� ���
void matrixPath(int n) {

	//n*n_2�迭 ���� �Ҵ� �� �ʱ�ȭ_0����
	int** arr = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = new int[n + 1];
	}

	//��� �� �Է�
	getArr(arr, n);

	int** c = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		c[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++) c[i][j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			c[i][j] = arr[i][j] + Max(c[i - 1][j], c[i][j - 1]);
	}
			
	//�ִ� ���
	cout<<"�ִ밪 : " << c[n][n] << endl;

	//��� ���
	cout << "��� : ";
	path(n, c);

	//�迭 �Ҵ� ����
	for (int i = 0; i < n+1; i++)
		delete[] arr[i];
	delete[] arr;

	//2�迭 �Ҵ� ����
	for (int i = 0; i < n + 1; i++)
		delete[] c[i];
	delete[] c;
}

int main(void) {
	int n=0;

	cout << "n �� �Է�: ";
	cin >> n;

	matrixPath(n);

	return 0;
}