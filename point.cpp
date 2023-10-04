/*#include<iostream>
using namespace std;

class AAA {
public:
	AAA() {
		cout << "empty ovject" << endl;//디폴트 생성자와 유사: 호출 기능 추가된...
	}
	void ShowYourName() {
		cout << "I'm class AAA" << endl;
	}
};

class BBB {
private:
	AAA& ref;
	const int &num;
public:
	BBB(AAA& r, const int& n)
		:ref(r), num(n) {//empty constructor body
	}
	void ShowYourName() {
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void) {
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();

	return 0;
}
*/
/*
class SoSimple {
private:
	int num;
public:
	SoSimple(int n):num(n){}
};

int main(void) {
	SoSimple simObj(10);//객체 생성됨
}
*/
/*
#include<iostream>
#include<cstring>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) :num(n) {
		cout << "num=" << num << ",";
		cout << "address=" << this << endl;
	}
	void ShowSimpleData() {
		cout << num << endl;
	}
	SoSimple* GetThisPointer() {
		return this;
	}
};

int main(void) {
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ",";
	ptr1->ShowSimpleData();
}
*/
/*
#include<iostream>
using namespace std;

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ofstream outFile("my.out", ios::out);
	if (!outFile) {
		cerr << "cannot open my.out" << endl;//표준오류 장치
		//cerr는 에러처리 stream
		return;
	}
	int n = 50; float f = 20.3;
	outFile << "n: " << n << endl;
	outFile << "f: " << f << endl;
}

#include<iostream>
using namespace std;

int* ip = new int;
delete ip;

int* jp = new int[10];	
delete[]jp;


#include<iostream>
using namespace std;

int Get_num(void) {
	int k;
	cin >> k;
	return k;
}

void Get_ab(int n, int k, char* result) {
	if (n == k) {
		cout << result << endl;
		return;
	}
	else {
		result[k] = 'a';
		Get_ab(n, k + 1, result);
		result[k] = 'b';
		Get_ab(n, k + 1, result);
	}
}

int main(void) {
	int n;
	n = Get_num();

	char* result = new char[n];
	Get_ab(n, 0, result);

	delete[]result;
	return 0;

void Fibonacci(int n) {
	//피보나치 수 Fn계산
	if (n <= 1)cout << n << endl; //F0=0과 F1=1
	else {
		int fn; int fnm2 = 0; int fnm1 = 1;
		for (int i = 2; i <= n; i++) {
			fn = fnm1 + fnm2;
			fnm2 = fnm1;
			fnm1 = fn;
		}
		cout << fn << endl;
	}
}
*/

