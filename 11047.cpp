#include <stdio.h>
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS


using namespace std;

int a[10];
bool compare(int n1, int n2) {
	if (n1 > n2) return true;
	return false;
}

int main() {
	int n, k;
	int result = 0;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n, compare);

	for (int i = 0; i < n; i++) {
		result += k / a[i];
		k = k % a[i];
	}

	printf("%d\n", result);
	return 0;
}