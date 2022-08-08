#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int find(int index, int pre_index, int n, int a[],
vector<vector<int> >& dp)
{
if (index == n) {
return 0;
}
if (dp[index][pre_index + 1] != -1) {
return dp[index][pre_index + 1];
}
int inc_not_Take = 0 + find(index + 1, pre_index, n, a, dp);
int take = INT_MIN;
if (pre_index == -1 || a[index] > a[pre_index]) {
take = 1 + find(index + 1, index, n, a, dp);
}
return dp[index][pre_index + 1] = max(take, inc_not_Take);
}
int longest_Increasing_Subsequence(int n, int a[])
{
vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
return find(0, -1, n, a, dp);
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
cout << longest_Increasing_Subsequence(n, a);
return 0;
}
