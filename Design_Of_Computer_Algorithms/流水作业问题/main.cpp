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

const int N = 5;

struct Job {
    int key, index;
    bool job;
};

bool cmp(Job A,Job B){
    return A.key < B.key;
}

int Prepare_Job(int n, int a[], int b[]) {
    Job *d = new Job[n];
    for (int i = 0; i < n; ++i) {
        d[i].key = a[i] < b[i] ? a[i] : b[i];
        d[i].job = a[i] <= b[i];
        d[i].index = i;
    }
    sort(d, d + n,cmp);// 按照升序对关键字key进行排序
    deque<int> job_queue;//采用双端队列实现
    for (int i = 0; i < n; ++i) {
        if (d[i].job)
            job_queue.push_front(d[i].index);
        else
            job_queue.push_back(d[i].index);
    }
    int j = a[job_queue.at(0)];
    int k = j + b[job_queue.at(0)];
    for (int i = 1; i < n; i++) {
        j += a[job_queue.at(i)];//M1在执行c[i]作业的同时，M2在执行c[i-1]号作业，最短执行时间取决于M1与M2谁后执行完
        k = j < k ? k + b[job_queue.at(i)] : j + b[job_queue.at(i)];//计算最优加工时间
    }
    delete d;
    cout << "编号从0开始，作业调度的顺序为：" << endl;
    for (int i = 0; i < N; i++) {
        cout << job_queue[i] << " ";
    }
    cout << endl;
    return k;
}

int main() {
    int a[] = {2, 4, 3, 6, 1};
    int b[] = {5, 2, 3, 1, 7};

    cout << "作业在机器1上的运行时间为：" << endl;
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "作业在机器2上的运行时间为：" << endl;
    for (int i = 0; i < N; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    int minTime = Prepare_Job(N, a, b);

    cout << "完成作业的最短时间为：" << minTime << endl;

    return 0;
}
