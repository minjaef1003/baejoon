#include<stdio.h>
#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int n, p[1000];
bool compare(int n1, int n2) {
	if (n1 > n2) return true;
	return false;
}

int main() {
	int result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	sort(p, p+n, compare);
	for (int i = 0; i < n; i++) {
		result += p[i] * (i+1);
	}
	printf("%d\n", result);
	return 0;
}