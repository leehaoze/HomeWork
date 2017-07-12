//leehaoze
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
const int INF = 1 << 29;
#define INC_SAT(val) (val = ((val)+1 > (val)) ? (val)+1 : (val))
#define ARR_SIZE(a) ( sizeof( (a) ) / sizeof( (a[0]) ) )
#define ULL unsigned long long

#define MAXN 100

int Board[MAXN][MAXN], tile, n;

void ChessBoard(int tr, int tc, int dr, int dc, int size) {
    if (size == 1) return;
    int t = tile++, s = size / 2;

    if (dr < tr + s && dc < tc + s)
        ChessBoard(tr, tc, dr, dc, s);
    else {
        Board[tr + s - 1][tc + s - 1] = t;
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    if (dr < tr + s && dc >= tc + s)
        ChessBoard(tr, tc + s, dr, dc, s);
    else {
        Board[tr + s - 1][tc + s] = t;
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    if (dr >= tr + s && dc < tc + s)
        ChessBoard(tr + s, tc, dr, dc, s);
    else {
        Board[tr + s][tc + s - 1] = t;
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    if (dr >= tr + s && dc >= tc + s) {
        ChessBoard(tr + s, tc + s, dr, dc, s);
    } else {
        Board[tr + s][tc + s] = t;
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

void Input() {
    cout << "请输入矩阵行列数：" << endl;
    cin >> n;
}

void Print(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << Board[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    //freopen("IN.txt", "r", stdin);
#endif
    Input();
    ChessBoard(0, 0, 0, 1, n);
    Print();
}