/*
按照题意简单模拟，引入了差分的概念
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int cal(int num) {
    int res = 0;
    while (num) num /= 10, res++;
    return res;
}
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2022_summer/infections1.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans13.txt", ios::out);
    if (!fin.is_open())
        assert(0);
    string str;
    fin >> str;
    vector<int> vec;  // 先处理文件输入读到vec里面
    int num = 0;
    for (auto ch : str) {  // 直接暴力逐字符读取, 可能有直接用库以冒号切割的方法
        if (ch == ':') {
            vec.push_back(num);
            num = 0;
        } else
            num = num * 10 + ch - '0';
    }
    vec.push_back(num);
    vector<int> diff;
    diff.push_back(vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        diff.push_back(vec[i] - vec[i - 1]);
    }
    int cnt = 0;
    for (auto it : diff) {
        if (it >= 0) fout << "+" << it;
        else fout << it;
        cnt += 1 + cal(abs(it));
    }
    fout << "\n" << "the number of characters is " << cnt << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}