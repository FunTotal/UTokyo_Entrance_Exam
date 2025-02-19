#include <bits/stdc++.h>
using namespace std;
int trans(char ch) { // map char to int
    if ('A' <= ch && ch <= 'Z') return ch - 'A';
    if ('a' <= ch && ch <= 'z') return 26 + ch - 'a';
    if (isdigit(ch)) return 26 + 26 + ch - '0';
    if (ch == '@') return 26 + 26 + 10;
    return 26 + 26 + 10 + 1;
}
void solve() {
    string str; cin >> str;
    vector<int> vec;
    for (auto ch : str) {
        int num = trans(ch);
        stack<int> stk;
        for (int i = 0; i < 6; i++) { // change int to binary string
            stk.push(num % 2);
            num /= 2;
        }
        while (!stk.empty())
            vec.push_back(stk.top()), stk.pop();
    }
    for (int i = 310; i <= 320; i++) // output the needed bytes
        cout << vec[i];
    cout << "\n";
}
signed main() {
    if (freopen("D:/3022244257/data1.txt", "r", stdin) == NULL)
        assert(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}