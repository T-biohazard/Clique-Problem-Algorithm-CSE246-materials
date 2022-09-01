#include<iostream>
#include <queue>
#include <vector>
using namespace std; //bfs
//initial -1, Q e boshle 0, visited hole 1
//sesh prjntw node 0 thakle cycle hoi
int main()
{
int v,s=1,n,x,y;
cin>>v>>n;
vector <int> adj[v+1];
for ( int i=0; i<n;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);}
queue<int> node;
int temp[v+1];
for(int i=1; i<v+1; i++)
{
temp[i]=-1;
}
node.push(s);
temp[s]=0;
bool i=true;
while (node.empty()!=i){
if(temp[node.front()]==0)
{
int temp2=node.front();
node.pop();
temp[temp2]=1;
for (int j=0; j<adj[temp2].size(); j++)//**
{
    if(temp[adj[temp2][j]]==-1)
    {
        node.push(adj[temp2][j]);
        temp[adj[temp2][j]]=0;
    }
    else if(temp[adj[temp2][j]]==0)
    {
        cout<<"YES";
        i=false;
        break;
    }
}}}
if(i==true){
cout<<"NO";}}
