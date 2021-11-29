#include<bits/stdc++.h>

using namespace std;

#define MAXN 12000000

bool composto[MAXN];

long long crivo(long long n) {
	long long primo_pos = 0;
	
	for(long long i = 2; i < MAXN; i++) {
		if(!composto[i]) {
			primo_pos++;
			
			if(primo_pos == n) return i;
			
			/* Reflita o porque j = i*i */
			for(long long j = i*i; j < MAXN; j+=i) {
				composto[j] = 1;
			}
		}
	}
	return -1;
}

int main() {
	long long n;

	cin >> n;
	
	memset(composto, 0, sizeof(composto));
	
	cout << crivo(n) << endl;
	
	return 0;
}
