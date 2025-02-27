/*
和上一题基本一样, 运行的结果是:
e(0) pixel: (0 0 0), index 302362
e(1) pixel: (88 88 88), index 30632
e(2) pixel: (124 124 124), index 338140
e(3) pixel: (155 155 155), index 1111164

*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define tii tuple<int, int, int>
using namespace std;
struct Node {
    int a, b, c, val, id;
};
bool cmp(Node a, Node b) {
    if (a.val != b.val)
        return a.val < b.val;
    else
        return a.id > b.id;
}
int cal(int a, int b, int c) {
    return a * a + b * b + c * c;
}
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2019_summer/image2.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2019_summer/ans4.txt", ios::out);
    vector<tii> vec;
    int num1, num2, num3;
    vector<Node> vec2;
    int cnt = 0;
    while (fin >> num1 >> num2 >> num3) {
        vec.push_back({num1, num2, num3});
        vec2.push_back(Node{num1, num2, num3, cal(num1, num2, num3), cnt++});
    }
    sort(vec2.begin(), vec2.end(), cmp);
    int n = vec2.size(), k = 4;
    for (int i = 0; i < 4; i++) {
        Node ei = vec2[n * i / k];
        fout << "e(" << i << ") pixel: (" << ei.a << " " << ei.b << " " << ei.c << "), index " << ei.id << "\n";
    }
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}