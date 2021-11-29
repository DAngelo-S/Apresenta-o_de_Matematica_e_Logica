#include <bits/stdc++.h>

using namespace std;

#define MAXN 999999

vector<int> primos;
bool composto[MAXN];

void crivo () {
    for (int i = 2; i < MAXN; i++) {
        if (!composto[i]) {
            primos.push_back(i);

            /* Reflita, por que nao usamos vector.erase() ? */
            /* O que acontece se mudarmos 2 * i por i * i ? */
            for(int j = i + i; j < MAXN; j+=i) {
                composto[j] = true;
            }
        }
    }
}

int main () {
    memset(composto, false, sizeof(composto));

    crivo();

    for (int i = 0; i < primos.size(); i++) {
        cout << primos[i] << " ";
    }
    cout << endl;

    return 0;
}