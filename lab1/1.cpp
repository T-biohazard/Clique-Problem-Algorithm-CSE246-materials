
#include <bits/stdc++.h>
using namespace std;
int UpperBound(int A[], int S, int low, int high) {
    int m = (low+high)/2;
    int num=high;
    int i, temp=1;
    while(low<=high) {
        if(A[m]==S) {
            for(i=0; i<num-m; i++) {
                if(A[m+i]==A[m+i+1]) {
                    temp=i+1;
                }
            }
            return m+temp;
            break;
        }
        else if(A[m]<S) {
            low = m+1;
        }
        else if(A[m]>S) {
            high = m-1;
        }
        m = (low+high)/2;
    }
    if(low>high) {
        int j, tempp;
        for(j=0; j<num; j++) {
            if(A[low]==A[low+j]) {
                tempp=j;
            }
        }
        return low+tempp;
    }
}

int lowerBound(int A[], int S, int low, int high) {
    int m = (low+high)/2;
    int i, temp;

    while(low<=high) {
        if(A[m]==S) {
            for(i=0; i<m; i++) {
                if(A[m]==A[m-i]) {
                    temp=i;
                }
            }
            return m-temp;
            break;
        }
        else if(A[m]<S) {
            low = m+1;
        }
        else if(A[m]>S) {
            high = m-1;
        }
        m = (low+high)/2;
    }
    if(low>high) {
        int j, tempp;
        for(j=1; j<low; j++) {
            if(A[low-1]==A[low-j]) {
                tempp=j;
            }
        }
        return low-tempp;
    }
}
void upper_Bound(int A[], int l, int n) {
    int x = UpperBound(A, l, 0, n-1);
    cout << x << " ";
}
void lower_Bound(int A[], int l, int n) {
    int y = lowerBound(A, l, 0, n-1);
    cout << y << " ";
}
int main() {
    int x,y;
    cin >> x;
    cin >> y;
    cout << endl;
    int A[x];
    for(int i = 0; i<x; i++) {
        cin >> A[i];}
    cout << endl;
    upper_Bound(A, y, x);
    lower_Bound(A, y, x);
}
