/*
也是简单模拟, c++里面可以对sort函数添加自定义比较规则, 运行的结果是:
N/2th pixel: (254 2 124), index 48312
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define tii tuple<int, int, int>
using namespace std;
struct Node {
    int a, b, c, val, id;
};
bool cmp(Node a, Node b) {
    if (a.val != b.val) return a.val < b.val;
    else return a.id > b.id;
}
int cal(int a, int b, int c) {
    return a * a + b * b + c * c;
}
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2019_summer/image1.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2019_summer/ans3.txt", ios::out);
    vector<tii> vec;
    int num1, num2, num3;
    vector<Node> vec2;
    int cnt = 0;
    while (fin >> num1 >> num2 >> num3) {
        vec.push_back({num1, num2, num3});
        vec2.push_back(Node{num1, num2, num3, cal(num1, num2, num3), cnt++});
    }
    sort(vec2.begin(), vec2.end(), cmp);
    int n = vec2.size();
    Node ans = vec2[n / 2];
    fout << "N/2th pixel: (" << ans.a << " " << ans.b << " " << ans.c << "), index " << ans.id << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}