/*
按照题意模拟，c++要注意精度问题，由于没有数据文件，不知道题目的精度要求怎么样，保险起见用long long和long double尽量保持精度，除法也是最后再除
*/
#include <bits/stdc++.h>
#define int long long
#define db long double
using namespace std;
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2022_summer/infections.txt",
                 ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans21.txt", ios::out);
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
    db mx = -1e9, mn = 1e9;
    int sum = 0, n = vec.size();
    for (int i = 3; i < n - 3; i++) {
        int tem = 0;
        for (int k = -3; k <= 3; k++)
            tem += vec[i + k];
        db ave = (db) tem / 7.0;
        mx = max(mx, ave), mn = min(mn, ave);
        sum += tem; //c++有浮点误差，尽量用整数，最后再统一除7.0
    }
    fout << fixed << setprecision(4) << "max ave = " << mx << "\n"
    << "min ave = " << mn << "\n"
    << "sum of ave = " << (db)((db)sum / 7.0) << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}