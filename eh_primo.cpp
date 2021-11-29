#include <iostream>

using namespace std;

bool is_prime(int n) {
    
    if (n < 2) {
        return false;
    }

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main () {
    int n;
    
    cin >> n;
    
    cout << (is_prime(n) ? "É primo!" : "Não é primo!") << endl;

    return 0; 
}