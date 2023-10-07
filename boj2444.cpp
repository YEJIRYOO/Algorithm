#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	cin.clear();

	for (int i = 1; i < n +1; i++) { //습관적이게 i=0선언하지 않도록 주의하자
		for(int h=0;h<n-i;h++)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << "*";
		cout << '\n';
	}
	for (int i = n-1 ; i > 0 ; i--) { //반대 방향으로 -> 차 값 줄여나가도록 변환
		for (int h = 0; h < n - i; h++)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << "*";
		cout <<'\n';
	}

	return 0;
}