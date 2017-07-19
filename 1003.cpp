#include <iostream>

using namespace std;

int zeroCnt, oneCnt;

int fibonacci(int n) {
	if (n == 0) {
		zeroCnt++;
		return 0;
	}
	else if (n == 1) {
		oneCnt++;
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main() {
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		zeroCnt = 0;
		oneCnt = 0;

		fibonacci(N);

		cout << zeroCnt << " " << oneCnt << endl;

	}

	return 0;
}