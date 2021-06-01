// The solution code for https://programmers.co.kr/learn/courses/30/lessons/72416
// Pay attention to how `Hash[i]` stores a list.

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

const int SZ = 300010;

using namespace std;

int bn;
int dp[SZ][2];
vector<int> price;

struct node{
    int num;
    node* next;
    node* alloc(int _num, node* _next){
        num = _num;
        next = _next;
        return this;
    }
}*Hash[SZ], buf[SZ];

void search_tree(int key) {
    // 1. make tree
    for (node* p = Hash[key]; p != NULL; p = p->next) {
        search_tree(p->num);
    }

    // 2. leaf caculate
    bool flag = true;
    int ans = 100000;
    dp[key][1] = price[key - 1];

    for (node* p = Hash[key]; p != NULL; p = p->next) {
        flag = false;
        dp[key][0] += dp[p->num][0];
        dp[key][1] += dp[p->num][0];
        ans = min(ans, dp[p->num][1] - dp[p->num][0]);
    }
    dp[key][0] = min(ans + dp[key][0], dp[key][1]);
    if (flag) dp[key][0] = 0;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;

    int N = sales.size();
    price = sales;

    for (vector<int> data : links) Hash[data[0]] = buf[bn++].alloc(data[1], Hash[data[0]]);

    search_tree(1);

    return dp[1][0];
}
