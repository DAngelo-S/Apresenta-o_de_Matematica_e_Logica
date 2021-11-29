#include<bits/stdc++.h>

using namespace std;

int main () {
    float p;
    
    if (p == 0 || p == 0.5 || p == 1) {
        cout << "Tanto faz o jogo\n";
    } else if (p > 0 && p < 0.5) {
        cout << "O jogo 1 é mais vantajoso!";
    } else {
        cout << "O jogo 2 é mais vantajoso!"
    }
}