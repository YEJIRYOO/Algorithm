/*#include<iostream>
using namespace std;

int Get_num(void) {
	int k;
	cin >> k;
	return k;
}

void Get_ab(int n,char *result) {
	if (n >= 0) {
		static int j = 1;
		if (j%2 == 1) {
			result[n-1] = 'a';
			j++;
		}
		else {
			result[n-1] = 'b';
		}
		return Get_ab(n -2, result);
	}
	else return;
}
int main(void) {
	int n;
	n = Get_num();

	char* result = new char[n];
	Get_ab(n, result);

	delete[]result;
	return 0;

}
*/
/*
#include<iostream>
using namespace std;

int GCD(int a, int b) {
	int r = a % b;
	if (r == 0)return b;
	else {
		GCD(b, r);
	}
}
*/