#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string N, sum, newN;
	int cnt = 0, temp;
	cin >> N;
	if (N.size() < 2)
		N = "0" + N;
	newN = N;
	do {
		cnt++;
		temp = newN.at(0) - '0';
		temp += newN.at(1) - '0';
		sum = to_string(temp);
		if (sum.size() > 1)
			sum = sum.at(1);
		newN = newN.at(1) + sum;
	} while (strcmp(N.c_str(), newN.c_str()) != 0);
	cout << cnt << endl;
	return 0;
}