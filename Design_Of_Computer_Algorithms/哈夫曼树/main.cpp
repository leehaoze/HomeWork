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

string data = "AAAAABBBBCCCDDE";

struct Node {
    char key_;
    int value_;
    Node *father_, *lchild, *rchild;

    Node(char key, int value = 0) : key_(key), value_(value), father_(NULL), lchild(NULL), rchild(NULL) {}
};

int cmp(Node *A, Node *B) {
    return A->value_ < B->value_;
}

class Priority_Queue {
private:
    vector<Node *> data_;
public:
    void push(Node *node) {
        data_.push_back(node);
        sort(data_.begin(), data_.end(), cmp);
    }

    Node *top() {
        return data_[0];
    }

    int size() {
        return (int) data_.size();
    }

    void pop() {
        data_.erase(data_.begin());
    }

    void print() {
        vector<Node *>::iterator iter = data_.begin();
        cout << "当前队列为：" << endl;
        while (iter != data_.end()) {
            cout << (*iter)->key_ << " : " << (*iter)->value_ << ';';
            ++iter;
        }
        cout << endl;
    }
};

Priority_Queue queue1;

void Init() {
    int len = (int) data.length();
    int count[26];
    memset(count, 0, sizeof count);
    for (int i = 0; i < len; ++i) {
        count[data[i] - 'A']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (count[i] == 0)continue;
        queue1.push(new Node(char('A' + i), count[i]));
    }
}


void BuildTree() {
    while (queue1.size() != 1) {
        queue1.print();
        Node *nodeA = queue1.top();
        queue1.pop();
        Node *nodeB = queue1.top();
        queue1.pop();
        Node *father = new Node('#', nodeA->value_ + nodeB->value_);
        father->lchild = nodeA;
        father->rchild = nodeB;
        nodeA->father_ = father;
        nodeB->father_ = father;
        queue1.push(father);
    }
}

void PrintCode(Node *node, string code) {
    if (node->lchild == NULL && node->rchild == NULL) {
        cout << node->key_ << " : " << code << endl;
    }
    if (node->lchild != NULL) {
        PrintCode(node->lchild, code + '0');
    }
    if (node->rchild != NULL) {
        PrintCode(node->rchild, code + '1');
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    Init();
    BuildTree();
    PrintCode(queue1.top(), "");
}