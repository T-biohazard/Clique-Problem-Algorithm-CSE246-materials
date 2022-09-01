#include<bits/stdc++.h>
using namespace std;
vector <int> grp[1000000];
//dfst sort ascending orde e
int v[5000000];
vector <int> storing;
void dfs(int key)
{
v[key] = 1;
vector <int> current=grp[key];
sort(current.begin(),current.end(),greater<int>());
for (int i = 0; i < current.size(); i++){
int next = current[i];
if (v[next] == 0)
{
dfs(next);
}
}
storing.push_back(key);
}
int main()
{
int v, e;
cin >> v >> e;
for (int i = 0; i < e; i++){
int u, v;
cin >> u >> v;
grp[u].push_back(v);
}
for(int i=v;i>=1;i--)
{
if(v[i]==0)
{
dfs(i);
}
}
reverse(storing.begin(),storing.end());
for(int i=0;i<storing.size();i++){
cout<<storing[i]<<endl;}
return 0;}
