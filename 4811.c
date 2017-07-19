#include<stdio.h>
long long Dynamic[31][31];
long long cal(int k, int Wcount, int Hcount) {
	long long count = 0;
	if (Dynamic[Wcount][Hcount] != -1)
		count = Dynamic[Wcount][Hcount];
	else {
		if (k == 0) {
			count++;
		}
		else {
			//calW
			if (Wcount != 0)
				count = cal(k - 1, Wcount - 1, Hcount);
			//calH
			if (Hcount > Wcount)
				count += cal(k - 1, Wcount, Hcount - 1);
			Dynamic[Wcount][Hcount] = count;
		}
	}
	return count;
}
int main() {
	int n;
	int Wcount, Hcount;
	long long count;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			Dynamic[i][j] = -1;
		}
	}
	
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
			Wcount = n;
			Hcount = n;
			count = cal(2 * n, Wcount, Hcount);
			printf("%lld\n", count);
	}
	return 0;
}