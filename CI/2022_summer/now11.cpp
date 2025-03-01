/*
前言:这次的卷子也不是很难，除了最后一题有点考察数学那边最小二乘法有点思维的转换，其他的基本都是
按照题意模拟即可，不过这里考察了一个遍历文件夹，也是需要准备一下相关的库函数的使用。
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2022_summer/infections.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans11.txt", ios::out);
    if (!fin.is_open()) assert(0);
    string str; fin >> str;
    vector<int> vec; //先处理文件输入读到vec里面
    int num = 0;
    for (auto ch : str) { //直接暴力逐字符读取, 可能有直接用库以冒号切割的方法
        if (ch == ':') {
            vec.push_back(num);
            num = 0;
        } else num = num * 10 + ch - '0';
    }
    vec.push_back(num);
    // 找第10大的去重后的数字
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    assert(vec.size() >= 10);
    fout << vec[vec.size() - 10] << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}