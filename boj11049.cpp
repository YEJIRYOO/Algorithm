#include <iostream>
#include <algorithm>

using namespace std;

int r[500], c[500];     //��� ����
int DP[500][500];       //��� �� ����

int func(int x, int y) {
    if (DP[x][y] > 0) return DP[x][y];  //����� ������ �� ��Ȱ��
    if (x >= y) return 0;
    int ans = 1000000000;   //min���� ����Ұű⶧���� ū������ �ʱ�ȭ

    //��͹��, top-down
    for (int k = x; k < y; k++) {
        ans = min(ans, func(x, k) + func(k + 1, y) + r[x] * c[k] * c[y]);
    }
    return DP[x][y] = ans;
}

int main(void) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> r[i] >> c[i];
    cout << func(0, N - 1);
    return 0;
}