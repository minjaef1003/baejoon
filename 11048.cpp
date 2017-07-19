#include <iostream>
#include <cstring>

using namespace std;

int miro[1001][1001];
int N, M;
int dp[1001][1001];

int cal(int X, int Y) {
	int result = 0, temp = 0;

	if (X != N) {
		if (dp[X + 1][Y] == -1) temp = cal(X + 1, Y);
		else temp = dp[X + 1][Y];
	}
	if (result < temp) result = temp;
	if (X != N && Y != M) {
		if (dp[X + 1][Y + 1] == -1) temp = cal(X + 1, Y + 1);
		else temp = dp[X + 1][Y + 1];
	}
	if (result < temp) result = temp;
	if (Y != M) {
		if (dp[X][Y + 1] == -1) temp = cal(X, Y + 1);
		else temp = dp[X][Y + 1];
	}
	if (result < temp) result = temp;

	result += miro[X][Y];
	dp[X][Y] = result;
	return result; 
}

int main() {
	int currentX = 1, currentY = 1;
	for (int i = 0; i < 1001; i++)
		memset(dp[i], -1, sizeof(dp[i]));

	cin >> N >> M;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> miro[i][j];
		}
	}

	cout << cal(currentX, currentY) << endl;
	return 0;
}