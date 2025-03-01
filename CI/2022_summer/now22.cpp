/*
这题也是复用前面遍历文件夹的方法，按照题目的公式模拟一下
*/
#include <bits/stdc++.h>
#define int long long
#define pss pair<string, string>
using namespace std;
namespace fs = filesystem;
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
int cal(string path1, string path2) {
    vector<int> x = readfile(path1), y = readfile(path2);
    if (x.size() < y.size()) swap(x, y);
    int m = x.size(), n = y.size();
    int point = 1e18;
    for (int i = 0; i <= m - n; i++) {
        int tem = 0;
        for (int k = 0; k <= n - 1; k++)
            tem += (x[k + i] - y[k]) * (x[k + i] - y[k]);
        point = min(point, tem);
    }
    return -point;
}
void solve() {
    string folder_path = "E:/UTokyo_Entrance_Exam/CI/2022_summer/data_forder/";
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2022_summer/ans22.txt", ios::out);
    vector<string> paths;
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (entry.is_regular_file()) {
            string file_path = entry.path().string();
            try {
                paths.push_back(file_path);
            } catch (const exception& e) {
                cout << "Error processing file " << file_path << ": "
                     << e.what() << endl;
            }
        }
    }
    int mxpoint = -1e18;
    vector<pss> res;
    for (int i = 0; i < paths.size(); i++)
        for (int j = i + 1; j < paths.size(); j++) {
            int point = cal(paths[i], paths[j]);
            if (point > mxpoint) mxpoint = point, res.clear(), res.push_back({paths[i], paths[j]});
            else if (point == mxpoint) res.push_back({paths[i], paths[j]});
        }
    for (auto [a, b] : res)
        fout << "file names : " << a << " " << "and " << b << "\n";
    fout << "their scores are " << mxpoint << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}