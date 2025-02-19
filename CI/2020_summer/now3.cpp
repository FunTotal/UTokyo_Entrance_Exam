#include <bits/stdc++.h>
using namespace std;
/*
INPUT  data2.txt:
29 2a 2b 2c 2d 2e 2f 2a 2b 2c 2d 2e 00 2e 2f 2a 2b 30

OUTPUT  data2.bin:
29 2a 2b 2c 2d 2e 2f 00	06 05 00 00 00 00 08 04 30


HACK!
INPUT data3b.txt:
29 00 2a 29 00 2a

OUPUT:
WRIGHT:  29 00 00 00 2a 00 03 03  (shorter)
WRONG:   29 00 00 00 2a 29 00 00 00 2a
*/
void solve() {
    ifstream fin("D:/3022244257/data3b.txt", ios::in | ios::binary);
    ofstream fout("D:/3022244257/data3b.bin", ios::out);
    vector<int> vec, res;
    char num;
    while (fin.read((char*) &num, sizeof(num)))
        vec.push_back(num);
    for (int i = 0; i < vec.size(); i++) {
        int l = 0, r = -1; // max range that matchs
        for (int j = 0; j < i; j++) { // enumerate the begginning of match part
            int len = 0; // max matched len
            while (j + len < i && i + len < vec.size() && vec[j + len] == vec[i + len])
                len++; // match and notice do not exceed the limit
            if (len > (r - l + 1)) {
                l = j, r = j + len - 1;
            }
        }
        int max_len = r - l + 1;
        bool contain0 = 0;
        for (int i = l; i <= r; i++)
            contain0 |= vec[i] == 0;
        if (r == -1 || (max_len <= 3 && !contain0)) { // choose not to compress
            if (vec[i] == 0) {
                res.push_back(0);
                res.push_back(0);
                res.push_back(0);
            } else
                res.push_back(vec[i]);
        } else {
            int p = i - l;
            int d = max_len;
            res.push_back(0);
            res.push_back(p);
            res.push_back(d);
            i += d - 1;
        }
    }
    for (auto c : res) {
        char ch = c;
        fout.write((char*) &ch, sizeof(ch));
    }
}
signed main() {
    int t = 1;
    while (t--) solve();
    return 0;
}