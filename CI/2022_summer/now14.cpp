/*
这题考察的是经典dp中的最大子段和，不过还需要记录一下最大子段和的位置
*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
int cal(int num) {
    int res = 0;
    while (num)
        num /= 10, res++;
    return res;
}
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2022_summer/infections2.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans14.txt", ios::out);
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
    int mxsum = diff[0], nowsum = diff[0], mnlen = 1, nowlen = 1;
    vector<pii> res;
    res.push_back({1, 1});
    for (int i = 1; i < diff.size(); i++) {
        nowsum += diff[i], nowlen++;
        if (nowsum > mxsum || nowsum == mxsum && nowlen < mnlen) { //更大或者相等且更短
            mxsum = nowsum, mnlen = nowlen;
            res.clear();
            res.push_back({i + 1 - nowlen + 1, i + 1});
        }
        else if (nowsum == mxsum && nowlen == mnlen) {
            res.push_back({i + 1 - nowlen + 1, i + 1});
        }
        else if (nowsum <= 0) {
            nowsum = nowlen = 0;
        }
    }
    for (auto [l, r] : res)
        fout << "From Day" << l << " to " << r << "\n";
    fout << "the sum of that period is " << mxsum << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}