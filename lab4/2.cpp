#include<bits/stdc++.h>
using namespace std;
int store[1000];
void  cp(int tables[],int n,int k) {
  int temp_table[n+1];
  temp_table[0] = 0;
  int temp_table2[n+1];
  temp_table2[0] = 0;
  for(int j=1;j<=n;j++) {
    int mini=INT_MAX;
    int coin=0;

    for(int i=1;i<=k;i++) {
      if(j>= tables[i]) {
        if((1+temp_table[j-tables[i]]) < mini) {
          mini = 1+temp_table[j-tables[i]];
          coin = i;
        }
      }
    }
    temp_table[j]=mini;
    temp_table2[j]=coin;
  }
  int l = n;
  while(l>0) {
    store[tables[temp_table2[l]]]++;

    l=l-tables[temp_table2[l]];
  }
  for(int i=0;i<10000;i++){
    if(store[i]>0){
            cout<<i<<" "<<store[i]<<endl;
    }
  }
}

int main() {
  int n,k;
  cin>>n>>k;
  int coins[n+1];
  for(int i=1;i<=n;i++){
   cin>>coins[i];
  }

  cp(coins,k,n);
  return 0;
}
