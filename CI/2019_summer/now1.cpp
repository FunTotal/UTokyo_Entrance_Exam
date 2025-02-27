/*
本题考察读入, 结果为:129600
*/
#include <bits/stdc++.h>
using namespace std;
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2019_summer/image1.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2019_summer/ans1.txt", ios::out);
    // freopen("E:/UTokyo_Entrance_Exam/CI/2019_summer/image1.txt", "r", stdin);
    // if (!fin.is_open()) assert(0);
    vector<int> vec;
    int num;
    while (fin >> num)
        vec.push_back(num);
    fout << vec.size() / 3 << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}