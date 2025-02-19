#include <bits/stdc++.h>
using namespace std;
/*
INPUT  data2.bin:
29 2a 2b 2c 2d 2e 2f 00	06 05 00 00 00 00 08 04 30

OUTPUT  data2.txt:
29 2a 2b 2c 2d 2e 2f 2a 2b 2c 2d 2e 00 2e 2f 2a 2b 30
total: 18 bytes
*/
void solve() {
    ifstream fin("D:/3022244257/data2.bin", ios::in | ios::binary);
    ofstream fout("D:/3022244257/data2.txt", ios::out);
    if (!fin.is_open()) assert(0);
    vector<int> vec;
    char num;
    while (fin.read((char*) &num, sizeof(char))) { // input data
        vec.push_back(num);
    }
    vector<char> res;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            // if byte not equal to 0, append directly
            res.push_back(vec[i]);
            // cout << "Writing b'" << (char)vec[i] << "'\n";
        }
        else {
            int p = vec[i + 1], d = vec[i + 2];
            i += 2;
            if (p < d) swap(p, d);
            // cout << "p = " << p << " " << "d = " << d << "\n";
            if (d == 0) res.push_back(0); // if d = 0, append 0
            else {
                int sz = res.size();
                // copy the needed range bytes from restoration part
                for (int j = sz - 1 - p + 1; j <= sz - 1 - (p - d + 1) + 1; j++) {
                    res.push_back(res[j]);
                    // cout << "Writing b'" << (char)res[j] << "'\n";
                }
            }
        } 
    }
    for (auto ch : res) {
        fout.write((char*)&ch, sizeof(ch));
    }
    // cout << res.size() << "\n";
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}