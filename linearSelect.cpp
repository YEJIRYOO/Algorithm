//알고리즘 5-2
//최악경우 선형시간 선택 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition1(vector<int>& A, int p, int r, int piv);
int partition2(vector<int> A, int p, int r);
int getMed(vector<int>& A, int p, int r);
int med(vector<int>& A, int p, int r);
int select(vector<int> A, int p, int r, int i);
int linearSelect(vector<int> A, int p, int r, int n);

int partition1(vector<int>& A, int p, int r, int piv) {//piv값 주입
    int np = 0;
    int n = p - 1;

    for (int i = p; i <= r; i++) {
        if (A[i] < piv) {
            n++;
            swap(A[n], A[i]);
        }

        if (A[i] == piv) {
            np = i;
        }
    }
    swap(A[n+1], A[np]);
    return n+1;
}

int partition2(vector<int> A, int p, int r) {//piv값 마지막
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] < x) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);

    return i + 1;
}

// 중앙값 찾기
int getMed(vector<int>& A, int p, int r) {
    int mid = (p + r) / 2;

    sort(A.begin(), A.end());

    return A[mid];
}

int med(vector<int>& A, int p, int r) {
    vector<int> medGroup;
    vector<vector<int>> bundle;

    if ((r - p) < 5) {
        return getMed(A, p, r);
    }

    //5개씩 묶음
    vector<int> tmp;//임시 공간
    for (int i = p; i <= r; i += 5) {
        for (int j = i; j < i + 5 && j <= r; j++) {
            tmp.push_back(A[j]);
        }
        bundle.push_back(tmp);
        tmp.clear();//tmp 공간 비우기
    }

    for (auto& g : bundle) {
        medGroup.push_back(getMed(g, 0, g.size() - 1));
    }

    //중앙값의 중앙값
    if (medGroup.size() == 1) {
        return medGroup[0];
    }
    else {
        return med(medGroup, 0, medGroup.size() - 1);
    }
}

int select(vector<int> A, int p, int r, int i) {
    if (p == r) return A[p]; // 원소 하나

    int q = partition2(A, p, r);
    int k = q - p + 1;

    if (i == k) return A[q]; // 기준원소 == 찾는 원소
    else if (i < k) return select(A, p, q - 1, i); // 왼쪽 그룹으로 범위 좁힘
    else return select(A, q + 1, r, i - k); // 오른쪽 그룹으로 범위 좁힘
}

int linearSelect(vector<int> A, int p, int r, int n) {
    int mednum;
    int piv;
    int num;

    if (p == r) { 
        return A[p];
    }

    mednum = med(A, p, r);
    piv = partition1(A, p, r, mednum);
    num = piv - p + 1;

    if (n < num) {
        return linearSelect(A, p, piv - 1, n);//n이 num보다 작을 때 piv 좌측
    }
    else if (n > num) {
        return linearSelect(A, piv + 1, r, n - num);//n이 num보다 클때 piv 우측
    }
    else {
        return A[piv];
    }
}

vector<int> A(100000);

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    time_t start, finish;
    double duration;

    start = time(NULL);
    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 100000; i++) {
            A[i] = rand() % 100000; // 0에서 999999 사이의 랜덤한 값으로 배열 초기화
        }
        cout << "반복횟수:" << j + 1 << " "<< linearSelect(A, 0, 99999, 50000) << "\n";
    }

    finish = time(NULL);

    duration = difftime(finish, start);

    cout << "소요 시간: " << duration << "초" << endl;

    return 0;
}
