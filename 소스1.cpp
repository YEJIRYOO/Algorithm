/*class Duck {
private:
	char name[20];
	int age;
public:
	void quack();
	void fly();
};

class RubberDuck :Duck { //상속
public:
	void fly{
		//dont
	}
};
*/
/*
#include<iostream>
using namespace std;

int Get_num(void) {
    int k;
    cin >> k;
    return k;
}

void Get_ab(int n, char* result, int j) {
    if (n >= 0) {
        if (j % 2 == 1) {
            result[n] = 'a';
            j++;
        }
        else {
            result[n] = 'b';
            j++;
        }
        Get_ab(n - 1, result, j); // 재귀 호출
    }
    return;
}

int main(void) {
    int n;
    n = Get_num();
    char* result = new char[n];
    Get_ab(n - 1, result, 1); // Get_ab 함수의 인자 수정
    for (int i = 0; i < (1 << n); i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << result[j];
        }
        cout << endl;
    }
    delete[]result;
    return 0;
}
*/

//잘못된 풀이!!
/*
#include<iostream>
#include<string>
using namespace std;

int Get_num(void) {
    int k;
    cin >> k;
    return k;
}

void Get_ab(int n, int k, char* result) {
    if (n == k) {
        cout << result << endl;
   }
   else {
        result[k] = 'a';
        result[k] = 'b';
        Get_ab(n, ++k, result);
    }
}

int main(void) {
    int n;
    n = Get_num();
    
    char* result = new char[n];
    Get_ab(n - 1, 0, result);

    delete[]result;
    return 0;

}
*/

#include<iostream>
#include<string>
using namespace std;

int Get_num(void) {
    int k;
    cin >> k;
    return k;
}

void Get_ab(int n, int k, string result,char c) {
    if (n == k) {
        cout << result << endl;
    }
    else {
        result[k] = c;
        Get_ab(n, k+1, result,'a');
        Get_ab(n, k+1, result, 'b');
    }
}

int main(void) {
    int n;
    n = Get_num();

    string* result = new string[n];
    Get_ab(n - 1, 0, result[n], " ");

    delete[]result;
    return 0;

}
