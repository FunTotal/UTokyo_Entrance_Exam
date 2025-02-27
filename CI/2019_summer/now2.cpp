/*
简单模拟, 比较严谨的做法是这样枚举每个白色作为第一行的右端点, 检验它竖下来的每个像素是不是
都是白色的。当然其实也可以把白色的像素位置都存起来，肉眼观察第一个是480，直接去check一下480
这个答案对不对，注意下标0开始还是1开始。
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define tii tuple<int, int, int>
using namespace std;
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2019_summer/image1.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2019_summer/ans2.txt", ios::out);
    // freopen("E:/UTokyo_Entrance_Exam/CI/2019_summer/image1.txt", "r", stdin);
    // if (!fin.is_open()) assert(0);
    vector<tii> vec;
    int num1, num2, num3;
    while (fin >> num1 >> num2 >> num3) {
        vec.push_back({num1, num2, num3});
    }
    int n = vec.size();
    vector<int> is_white(n);
    vector<int> whites;
    for (int i = 0; i < n; i++)
        if (vec[i] == tii{255, 255, 255}) {
            is_white[i] = 1;
            whites.push_back(i);
        }
    for (int i = 0; i < whites.size(); i++) {
        // 枚举第一行最右边的白色格子
        int flag = 1;
        for (int j = whites[i]; j < n; j += whites[i] + 1)
            flag &= is_white[j] == 1;
        if (flag) {
            fout << whites[i] + 1 << "\n";
            break;
        }
    }
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}