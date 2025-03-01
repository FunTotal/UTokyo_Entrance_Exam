/*
题目给出最小二乘法公式，按照题目计算一下，同样注意精度问题
*/
#include <bits/stdc++.h>
#define int long long
#define db long double
using namespace std;
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2022_summer/infections2.txt",
                 ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans23.txt", ios::out);
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
    
    int sum_ixi = 0, sum_i = 0, sum_i2 = 0, sum_xi = 0;
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        sum_ixi += i * vec[i];
        sum_i += i;
        sum_xi += vec[i];
        sum_i2 += i * i;
    }
    db a = ((db)n * sum_ixi - sum_i * sum_xi) / (n * sum_i2 - (sum_i) * (sum_i));
    db k = ((db)sum_i2 * sum_xi - sum_ixi * sum_i) / (n * sum_i2 - sum_i * sum_i);
    fout << fixed << setprecision(4) << "a = " << a << ", k = " << k << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}