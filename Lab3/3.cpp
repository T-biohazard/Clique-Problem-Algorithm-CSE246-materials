#include <bits/stdc++.h>
using namespace std;

void Arr (char P [], int SIZE, int Pi []);
void Arr2 (int Pi [], int Y);

void KMP (char P []) {

    int SIZE = strlen (P);
    int Pi [SIZE];

    Arr (P, SIZE, Pi);
}
void Arr (char P [], int SIZE, int Pi []) {
    int Y = SIZE;
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
    Arr2 (Pi, Y);
}
void Arr2 (int Pi [], int Y) {

    for (int i = 0; i < Y; i++) {

        cout << Pi [i] << " ";
    }
}
int main (void) {
    char P [100000];
    cin >> P;
    KMP (P);

    return 0;
}
