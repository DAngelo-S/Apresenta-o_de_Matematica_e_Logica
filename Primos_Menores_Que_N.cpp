#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;

    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i <= n; i++){
        if(!isPrime[i]) {
            continue;
        }

        for (int j = 2 * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

  return 0;
}
