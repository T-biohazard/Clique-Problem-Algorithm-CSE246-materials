#include <bits/stdc++.h>
using namespace std;
void Pi_Array (char T [], char P [], int SIZE, int Pi []);
void KMP (char T [], char P []) {
    int SIZE_T = strlen (T);
    int SIZE_P = strlen (P);
    int Pi [SIZE_P];
    Pi_Array (T, P, SIZE_P, Pi);
    int i = 0, j = 0;
    while (i < SIZE_T) {
        if (P [j] == T [i]) {
            j++;
            i++;
        }
        else {
            if (j != 0) {
                j = Pi [j - 1];
            }
            else {
                i++;
            }
        }
        if (j == SIZE_P) {
            cout << i - j << " " << i - 1 << endl;

            j = Pi [j - 1];
        }
    }
}
void Pi_Array (char T [], char P [], int SIZE_P, int Pi []) {
    int Y = SIZE_P;
    int length = 0;
    Pi [0] = 0;
    for (int i = 1; i < Y; i++) {
        if (P [i] == P [length]) {
            length++;
            Pi [i] = length;
        }
        else {
            Pi [i] = 0;
            length = 0;
        }
    }
}
int main (void) {
    char T [100000];
    char P [1000];
    cin >> T;
    cin >> P;
    KMP (T, P);
    return 0;
}
