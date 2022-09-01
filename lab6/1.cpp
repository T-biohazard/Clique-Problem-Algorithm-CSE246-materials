#include <bits/stdc++.h>
#include<deque>
using namespace std;
vector<int>V[100],traversed;
deque<int>Q;
void BFS(int node)
{
int white,gray,black,inf,des;
int color[node],prev[node];
white = 0;
gray = 1;
black = 2;
inf = 10000;
int s,i,u,j,x;
for(i=1;i<=node;i++)
{
    color[i] = white;
    prev[i] = inf;
}
cin>>s>>des;
color[s] = gray;
prev[s] = NULL;
Q.push_back(s);

while(!Q.empty())
{
    u = Q.front();
    traversed.push_back(u);
    Q.pop_front();
    for(j=0;j<V[u].size();j++)
    {
        x = V[u][j];
        if(color[x]==white)
        {
            color[x] = gray;
            prev[x] = u;
            Q.push_back(x);
        }

    }
    color[u] = black;
}
vector<int>path;
int sc=-1;
path.push_back(NULL);
path.push_back(des);
if( color[des] == white)
{
    cout<<inf<<endl;
}
else
{
    while(sc!=s)
    {
        sc = prev[des];
        des = sc;
        path.push_back(des);
    }
    cout<<path.size()-2<<endl;
}
}
int main()
{
int node,edge,u,v;
cin>>node>>edge;
for(int i=1;i<=edge;i++)
{
    cin>>u>>v;
    if(u==v)
    {
        V[u].push_back(v);
    }
    else
    {
        V[u].push_back(v);
        V[v].push_back(u);
    }

}
BFS(node);
}


