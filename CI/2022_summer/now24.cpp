/*
这题有点思维含量，要注意到合理利用第三问的公式，取对数转换为第三问的线性问题。要注意c++没有loge函数，还需要用换底公式 loge x = log2(x) / log2(e), c++中的exp(x)函数是 e ^ x, exp(1) 即为自然对数e
*/
#include <bits/stdc++.h>
#define int long long
#define db long double
#define pii pair<int, int>
using namespace std;
vector<int> readfile(string path) {
    ifstream fin(path, ios::in);
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
    return vec;
}
pii calak(vector<db> vec) { // 给定 x 求线性的最小拟合的 a 和 k
    db sum_ixi = 0, sum_i = 0, sum_i2 = 0, sum_xi = 0;
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        sum_ixi += i * vec[i];
        sum_i += i;
        sum_xi += vec[i];
        sum_i2 += i * i;
    }
    db a =
        ((db)n * sum_ixi - sum_i * sum_xi) / (n * sum_i2 - (sum_i) * (sum_i));
    db k =
        ((db)sum_i2 * sum_xi - sum_ixi * sum_i) / (n * sum_i2 - sum_i * sum_i);
    return {exp(a) * 10000, exp(k) * 10000};
}
void solve() {
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans24.txt", ios::out);
    vector<int> vec = readfile("E:/UTokyo_Entrance_Exam/CI/2022_summer/infections3.txt");
    vector<array<int, 3>> res;
    int mxa = -1e18;
    int n = vec.size();
    for (int s = 0; s < n - 30; s++) {
        vector<db> x;
        for (int i = s; i <= s + 30; i++)    
            x.push_back(log(vec[i] + 1) / log(exp(1)));
        auto [a, k] = calak(x);
        if (a > mxa) mxa = a, res.clear(), res.push_back({s, a, k});
        else if (a == mxa) res.push_back({s, a, k});
    }
    for (auto [s, a, k] : res) {
        fout << fixed << setprecision(4) << "s = " << s << ", a = " << a / 1e4 << ", k = " << k / 1e4 << "\n";
    }
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}