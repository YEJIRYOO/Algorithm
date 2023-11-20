/***********************
과제 5 : 행렬 경로 문제 동적 프로그래밍
20222979 유예지
************************/


#include<iostream>
using namespace std;

//배열 초기화 함수
void getArr(int* arr[],int n) {
	for (int i = 0; i < n + 1; i++) {
		if(i!=0) cout << i<<"행 입력 : ";
		for (int j=0; j < n + 1; j++) {
			if (i == 0 || j == 0)arr[i][j] = 0;
			else {
				cin >> arr[i][j];
			}
		}
	}
}

//큰 값 반환 함수
int Max(int a, int b) {
	a = a > b ? a : b;

	return a;
}

//이동 경로 출력
void path(int n, int* c[]) {
	int l = n;
	int r = n;
	int s = 2 * n - 1;
	int* al = new int[s];//x좌표 저장 배열
	int* ar = new int[s];//y좌표 저장 배열

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
	
	//배열 할당 해제
	delete[] al;
	delete[] ar;
}

//행렬 경로
void matrixPath(int n) {

	//n*n_2배열 동적 할당 및 초기화_0으로
	int** arr = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = new int[n + 1];
	}

	//행렬 값 입력
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
			
	//최댓값 출력
	cout<<"최대값 : " << c[n][n] << endl;

	//경로 출력
	cout << "경로 : ";
	path(n, c);

	//배열 할당 해제
	for (int i = 0; i < n+1; i++)
		delete[] arr[i];
	delete[] arr;

	//2배열 할당 해제
	for (int i = 0; i < n + 1; i++)
		delete[] c[i];
	delete[] c;
}

int main(void) {
	int n=0;

	cout << "n 값 입력: ";
	cin >> n;

	matrixPath(n);

	return 0;
}