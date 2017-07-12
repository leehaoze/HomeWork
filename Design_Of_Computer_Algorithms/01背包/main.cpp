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
const int INF = 1<<29;
#define INC_SAT( val ) (val = ((val)+1 > (val)) ? (val)+1 : (val))
#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( (a[0]) ) )
#define ULL unsigned long long

#define MAXN (1000 + 5)

//储存物体信息的结构体
struct Article{
    int value_; //价值
    int weight_;//重量
    Article():value_(0),weight_(0){
    }
};

int T,N,V;
Article articles[MAXN];
int dp[MAXN][MAXN];

//输入
void Input(){
    scanf("%d%d",&N,&V);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&articles[i].value_);
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&articles[i].weight_);
    }
}
//蛮力搜索
int Search(int no,int space){
    if(dp[no][space] != 0)
        return dp[no][space];

    if(no == 0){
        if(space >= articles[no].weight_)
            return dp[no][space] = articles[no].value_;
        else
            return dp[no][space] = 0;
    }
    if(space >= articles[no].weight_)
        return dp[no][space] = max(Search(no - 1,space),Search(no - 1,space - articles[no].weight_) + articles[no].value_);
    else
        return dp[no][space] = Search(no - 1,space);
}
//普通DP
int DP(){
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= V; ++j){
            if(j >= articles[i].weight_){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - articles[i].weight_] + articles[i].value_);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][V];
}
//化简为一位数组的DP
int best[MAXN];
int DP2(){
    for (int i = 1; i <= N; ++i) {
        for (int j = V; j >= articles[i].weight_; --j) {
            best[j] = max(best[j],best[j - articles[i].weight_] + articles[i].value_);
        }
    }
    return best[V];
}

int main() {
    scanf("%d",&T);
    while(T--){
        Input();
        memset(dp,0,sizeof dp);
        memset(best,0,sizeof best);
        printf("%d\n",DP2());
    }
}