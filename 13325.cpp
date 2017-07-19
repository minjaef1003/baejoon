#include <iostream>
#include <math.h>

int main() {
	int level;
	scanf("%d", &level);
	int cur = level - 1;
	int numOfEdge = (int)pow(2, level+1);
	numOfEdge = numOfEdge - 2;
	int numOfNode = numOfEdge + 1;
	int* edge = new int[numOfEdge];
	for (int i = 0; i < numOfEdge; i++) {
		scanf("%d", &edge[i]);
	}
	int* node = new int[numOfNode];
	memset(node, 0, sizeof(int) * numOfNode);

	int cnt = 0;
	for (int i = numOfNode - (int)pow(2, level) - 1; i > 0; i--) {
		
		int L = edge[i * 2] + node[i*2+1];
		int R = edge[i*2 + 1] + node[i * 2 + 2];
		if (L < R) node[i] = R;
		else node[i] = L;
		cnt++;
		if (cnt == (int)pow(2, cur)) {
			cur--;
			cnt = 0;
		}

	}
	
	if (node[1] + edge[0] < node[2] + edge[1]) node[0] = node[2] + edge[1];
	else node[0] = node[1] + edge[0];
	cnt = 0;
	cur = 0;
	int result = 0;
	for (int i = 0; i < numOfNode - (int)pow(2, level); i++) {
		result = result + node[i] - node[i * 2 + 1];
		result = result + node[i] - node[i * 2 + 2];
		cnt++;
		if (cnt == (int)pow(2, cur)) {
			cur--;
			cnt = 0;
		}
	}
	printf("%d\n", result);
	
	return 0;
}