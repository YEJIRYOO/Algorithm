#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	cin.clear();

	for (int i = 1; i < n +1; i++) { //�������̰� i=0�������� �ʵ��� ��������
		for(int h=0;h<n-i;h++)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << "*";
		cout << '\n';
	}
	for (int i = n-1 ; i > 0 ; i--) { //�ݴ� �������� -> �� �� �ٿ��������� ��ȯ
		for (int h = 0; h < n - i; h++)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << "*";
		cout <<'\n';
	}

	return 0;
}