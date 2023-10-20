#include<iostream>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	int val = n;
	int check = n;
	while (check > k) {
		val += check / k;
	}

	cout << val;

	return 0;
}