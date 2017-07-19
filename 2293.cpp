#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;


int main() {
	int n, k;
	int coin[100] = { 0, };
	int dp[10001] = { 0, };

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + 100, greater<int>());

	dp[0] = 1;
	for (int j = n - 1; j > -1; j--) {
		for (int i = 1; i < k + 1; i++) {
			if (i - coin[j] >= 0 && dp[i - coin[j]] >= 0) {
				dp[i] += dp[i - coin[j]];
			}
		}
	}
	cout << dp[k] << endl;
	return 0;
}