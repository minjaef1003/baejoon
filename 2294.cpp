#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

int main() {
	int n, k;
	int coin[100] = {0,};
	int dp[10001];
	int temp;


	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + n, greater<int>());

	dp[0] = 0;
	for (int i = 1; i < k + 1; i++) {
		for (int j = n - 1; j > -1; j--) {
			if (i - coin[j] >= 0 && dp[i - coin[j]] >= 0) {
				temp = dp[i - coin[j]] + 1;
				if (temp < dp[i] || dp[i] == -1)
					dp[i] = temp;
			}
			else if (i - coin[j] < 0)
				break;
		}
	}


	cout << dp[k] << endl;
	
	return 0;
}
