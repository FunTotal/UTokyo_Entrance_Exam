/*
本题主要难在要提前准备好遍历文件夹的方式
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int get_Nf(string path) {
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
    // 找第10大的去重后的数字
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    assert(vec.size() >= 10);
    return vec[vec.size() - 10];
}
namespace fs = filesystem;
void solve() {
    string folder_path = "E:/UTokyo_Entrance_Exam/CI/2022_summer/data_forder/";
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans12.txt", ios::out);
    int res = 0;
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (entry.is_regular_file()) { 
            string file_path = entry.path().string();
            try {
                int nf = get_Nf(file_path);
                res += nf;
            } catch (const exception& e) {
                cout << "Error processing file " << file_path << ": "
                     << e.what() << endl;
            }
        }
    }
    fout << res << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}