#include <stdio.h>
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class conference {
public:
	int start;
	int finish;
	int time;

};
conference conf[100000];

bool compare(conference c1, conference c2) {
	if (c1.finish < c2.finish)
		return true;
	else if (c1.finish == c2.finish)
		if (c1.time > c2.time)
			return true;
	return false;
}
void sort(int** num) {

}
int main() {
	int n;
	int tmp = 0;
	int result = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(conf[i].start), &(conf[i].finish));
		conf[i].time = conf[i].finish - conf[i].start;
	}

	sort(conf, conf + n, compare);

	
	for (int i = 0; i < n; i++) {
		if (tmp <= conf[i].start) {
			tmp = conf[i].finish;
			result++;
		}
	}
	
	printf("%d\n", result);

	return 0;
}