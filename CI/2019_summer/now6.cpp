/*
这题意思就是利用上一题聚类，把颜色相近的用一个代表颜色替代后，就可以用尽可能少的颜色表示
同样的一张图片，并把那些替代后的像素元组写入image.tif按照题中的格式。所以第五题的代码得
写对，然后比较考察第六题的阅读理解，看懂怎么按照格式输出才使得图片能打得开。

一个比较无语的地方是，题面里说图片是squre，但是发现不是一个完全平方数，参考了楼上的py代码后
发现应该意思是矩形，然后根据第二问里面的白色像素的方法来判断长宽是1600 1250，然后直接这样来
输出一下，打开图片发现确实是这样，再去考虑用第五题的聚类算法来压缩。实际测下来发现我的代码跑
得飞快，而且目测效果比楼上的py代码更好(因为他第五题的代码就是有bug的)
*/
#include <bits/stdc++.h>
#define int long long
#define tii tuple<int, int, int>
using namespace std;
struct Node {
    int a, b, c, val, id;
};
bool cmp(Node a, Node b) {
    if (a.val != b.val)
        return a.val < b.val;
    else
        return a.id > b.id;
}
int cal(int a, int b, int c) {
    return a * a + b * b + c * c;
}
int dis(Node a, Node b) {
    return abs(a.a - b.a) + abs(a.b - b.b) + abs(a.c - b.c);
}
void solve() {
    ifstream fin("E:/UTokyo_Entrance_Exam/CI/2019_summer/image2.txt", ios::in);
    ofstream fout("E:/UTokyo_Entrance_Exam/CI/2019_summer/image2.tif", ios::out | ios::binary);
    vector<tii> vec;
    int num1, num2, num3;
    vector<Node> vec2;
    int cnt = 0;
    while (fin >> num1 >> num2 >> num3) {
        vec.push_back({num1, num2, num3});
        vec2.push_back(Node{num1, num2, num3, cal(num1, num2, num3), cnt++});
    }
    sort(vec2.begin(), vec2.end(), cmp);
    int n = vec2.size(), k = 32;
    vector<Node> repre(k);  // k个代表元素
    vector<int> bel(n); // 记录每个像素的代表元素编号
    vector<int> is_repre(n);
    for (int i = 0; i < k; i++) {
        Node ei = vec2[n * i / k];
        repre[i] = ei;
        is_repre[ei.id] = 1;
    }
    for (int repeat = 1; repeat <= 10; repeat++) {
        vector<vector<Node>> group;
        group.resize(k);  // 开 k 个vector, 存每个group里面有哪些三元组
        for (int i = 0; i < k; i++)
            group[i].push_back(repre[i]);  // 先把代表元素放进去
        // 枚举三元组, 遍历找最近的聚类
        for (int i = 0; i < n; i++) {
            Node now = vec2[i];
            if (is_repre[now.id])
                continue;   // 去掉代表元素
            int i_bel = 0;  // 当前元素属于的聚类编号
            for (int j = 1; j < k; j++) {
                if (dis(now, repre[j]) < dis(now, repre[i_bel]) ||
                    dis(now, repre[j]) == dis(now, repre[i_bel]) &&
                        repre[j].id > repre[i_bel].id) {
                    // 距离更近或者距离相同编号更大
                    i_bel = j;
                }
            }
            group[i_bel].push_back(now);
        }
        // 重新算每个聚类里的代表元素
        for (int i = 0; i < k; i++) {
            Node centroid = Node{0, 0, 0, 0, 0};  // 每个聚类的重心
            for (auto [a, b, c, val, id] : group[i]) {
                centroid.a += a, centroid.b += b, centroid.c += c;
            }
            // c++整形默认向下整除, 也可以用浮点数再floor取整, 可能还得加个eps
            centroid.a /= group[i].size(), centroid.b /= group[i].size(),
                centroid.c /= group[i].size();
            // 找组里离重心最近的作为新的代表元素
            Node newrepre = repre[i];
            for (auto it : group[i]) {
                if (dis(it, centroid) < dis(newrepre, centroid) ||
                    dis(it, centroid) == dis(newrepre, centroid) &&
                        it.id > newrepre.id) {
                    newrepre = it;
                }
            }
            is_repre[repre[i].id] = 0;
            repre[i] = newrepre;
            is_repre[repre[i].id] = 1;
            for (auto it : group[i])
                bel[it.id] = newrepre.id;
        }
    }
    

    // 下面处理按照对应格式输出
    // 先求出图片的长宽，利用第二问的白色来判断
    int W = 1600, H = 1025, S = W * H * 3;
    int w[4], h[4], s[4];
    for (int i = 3; i >= 0; i--)
        w[i] = W & 255, W >>= 8;
    for (int i = 3; i >= 0; i--)
        h[i] = H & 255, H >>= 8;
    for (int i = 3; i >= 0; i--)
        s[i] = S & 255, S >>= 8;
    vector<int> tp = {77, 77, 0,  42, 0,  0,  0,  8, 0,  7,   1, 0,  0, 4, 0,
                      0,  0,  1,  w[0], w[1], w[2], w[3], 1, 1,  0,   4, 0,  0, 0, 1,
                      h[0], h[1], h[2], h[3], 1,  2,  0,  3, 0,  0,   0, 3,  0, 0, 0,
                      98, 1,  6,  0,  3,  0,  0,  0, 1,  0,   2, 0,  0, 1, 17,
                      0,  4,  0,  0,  0,  1,  0,  0, 0,  104, 1, 21, 0, 3, 0,
                      0,  0,  1,  0,  3,  0,  0,  1, 23, 0,   4, 0,  0, 0, 1,
                      s[0], s[1], s[2], s[3], 0,  0,  0,  0, 0,  8,   0, 8,  0, 8};
    for (auto it : tp) {
        char ch = it;
        fout.write((char*)&ch, sizeof(ch));
    }
    for (int i = 0; i < n; i++) {
        auto [r, g, b] = vec[bel[i]];
        char chr = r, chg = g, chb = b;
        fout.write((char*)&chr, sizeof chr);
        fout.write((char*)&chg, sizeof chg);
        fout.write((char*)&chb, sizeof chb);
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}