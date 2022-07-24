#include <bits/stdc++.h>
using namespace std;
int knap_sack(int b[], int w[], int N, int W)
{
    int i,j;
    int temp[2][W+1];
    for(i=0; i<=N; i++)
        {
        for(j=0; j<=W; j++)
        {
            if(i==0 || j==0)
                temp[i%2][j]=0;
            else if(w[i-1]<=j)
                temp[i%2][j]=max(b[i-1]+temp[(i-1)%2][j-w[i-1]],temp[(i-1)%2][j]);
            else
                temp[i%2][j]=temp[(i-1)%2][j];
        }
    }
    return temp[N%2][W];
}
int main()
{
    while(1)
        {
            int N,W,i;
            cin >> N;
            cin >> W;
            int b[N];
            int w[N];
            for(i=0; i<N; i++)
                {
                cin >> b[i];
        }
            for(i=0; i<N; i++)
                {
                cin >> w[i];
        }
        cout << knap_sack(b, w, N, W);
        cout << endl;
        cout << endl;
   }


    return 0;
}
