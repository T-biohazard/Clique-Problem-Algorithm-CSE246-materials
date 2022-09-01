#include<iostream>
#include <queue>
#include <vector>
//dfs
using namespace std;
int j,v,s,e,x,y,tm=0;
int mccu( int j,int temp[],vector <int> adj[]){
temp[j]=1;
for (int i=0; i<adj[j].size(); i++){
if(temp[adj[j][i]]==-1){
    tm=1;
    return 1+ mccu(adj[j][i],temp,adj);
}}
if (tm==0){
return 0;}}

int main()
{
cin>>v>>e;
vector <int> adj[v+1];
for ( int i=0; i<e ; i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
int temp[v+1];
int cnt=0,arr[10];
for(int i=1; i<v+1; i++)
{
temp[i]=-1;
}
for (j=1; j<v; j++)
{
if(temp[j]==-1)
{
    arr[cnt]=mccu(j,temp,adj);
    cnt++;}}
int maxx=0;
for(int i=0; i<cnt; i++){
if (arr[i]>maxx){
    maxx=arr[i];}}
cout<<maxx;
}
/*
#include<bits/stdc++.h>
using namespace std;
vector <int> graph[1000000];
vector <int> storing;
int counter=0;
bool visited[5000000];
  vector <int> vv,tmp;
void dfs(int source){
    counter++;
    vv.push_back(source);
    visited[source] = 1;
    for(int i=0;i < graph[source].size(); i++){
        int next = graph[source][i];
        if (visited[next] == 0){
             dfs(next);
        }
    }
}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
   int maxi=0;
   for(int k=1;k<=edges;k++){
        for(int h=1;h<=edges;h++){
            visited[h]=false;
        }
        for(int i=1;i<=edges;i++){
                counter=0;
            if(visited[i]==false){
            visited[i]=true;
               dfs(i);
           maxi=max(maxi,counter);
        }}}

    cout<<maxi<<endl;
}
*/
