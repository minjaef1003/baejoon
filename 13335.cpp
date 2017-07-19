#include <iostream>

using namespace std; 

int truck[100];
int bridge[100];
int n, w, L;
int beginTruck = 1;
int endTruck = 0;

int calTime(int k) {
	int j = beginTruck;
	for (int i = w; i > 0; --i) {
		if (j != 0) {
			bridge[i] = bridge[j];
			j--;
		}
		else {
			bridge[i] = 0;
		}
	}
	j = w - beginTruck;
	endTruck += j;
	beginTruck = w+1;
	return j;
}

int addTruck(int k) {
	int j;
	for (int i = w; i > 1; --i) {
		j = i - 1;
		bridge[i] = bridge[j];
	}
	bridge[0] = truck[k];
	beginTruck++;
	return 1;
}

int checkL(int k) {
	int weight = 0;
	for (int i = endTruck; i < beginTruck; ++i) {
		weight += bridge[i];
	}
	weight += truck[k];
	if (weight > L) return 0;
	else return 1;
}

int main() {
	cin >> n >> w >> L;
	
	
	for (int i = 0; i < n; ++i) {
		cin >> truck[i];
	}

	int k = 0;
	int time = 0;
	while (1) {
		if (k > n)
			break;
		if (!checkL(k)) {
			time += calTime(k);
			beginTruck = 0;
			endTruck = 0;
		}
		time += addTruck(k);
		++k;
	}
	cout << time;
	return 0;
}