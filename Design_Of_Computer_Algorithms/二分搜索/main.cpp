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

int len;
int *data;

void Input() {
    cout << "请输入数组长度" << endl;
    cin >> len;
    data = new int[len + 1];
    cout << "请按顺序输入数组元素" << endl;
    for (int i = 0; i < len; ++i) {
        cin >> data[i];
    }
}

void view(int left, int right, int value) {
    int mid = (left + right) / 2;
    for (int i = 0; i < len; ++i) {
        if (i != 0)cout << ' ';
        cout << data[i];
    }
    cout << endl;
    for (int i = 0; i < len; ++i) {
        if (i != 0)cout << ' ';
        if(i == mid) {
            cout << 'M';
        }
        else if(i == right){
            cout << "R";
        }
        else if(i == left){
            cout << 'L';
        }
        else{
            cout << ' ';
        }
    }
    cout << endl;
    if (data[mid] == value) {
        cout << "找到结果" << endl;
    } else if (data[mid] > value) {
        cout << "当前值比要查找的值大，缩小right的值" << endl;
    } else {
        cout << "当前值比要查找的值小，扩大left的值" << endl;
    }
}

int BinarySearch(int value) {
    int left = 0, right = len - 1;
    while (left <= right) {
        view(left,right,value);
        int mid = (left + right) / 2;
        if (data[mid] == value) {
            return mid;
        } else if (data[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int BinarySearch(int left, int right, int value) {
    view(left,right,value);
    int mid = (left + right) / 2;
    if (left > right) {
        return -1;
    }
    if (data[mid] == value) {
        return mid;
    } else if (data[mid] > value) {
        return BinarySearch(left, mid - 1, value);
    } else {
        return BinarySearch(mid + 1, right, value);
    }
}

void UI() {
    while (true) {
        cout << "请选择操作:\n"
                "1. 测试程序\n"
                "2. 退出程序" << endl;
        int op;
        cin >> op;
        if (op == 2)break;
        cout << "请输入一个要查找的元素" << endl;
        int value;
        cin >> value;
        cout << "请选择要查找的方式:\n" <<
             "1. 递归方式二分查找\n" <<
             "2. 非递归方式二分查找"
             << endl;
        int order, ans;
        cin >> order;
        if (order == 1) {
            ans = BinarySearch(value) + 1;
        } else {
            ans = BinarySearch(0, len - 1, value) + 1;
        }
        if (ans == 0) {
            cout << "你要查找的值不在数组中" << endl;
        } else {
            cout << "你要查找的值" << value << "在第" << ans << "位" << endl;
        }
    }
}

int main() {
    Input();
    UI();
}