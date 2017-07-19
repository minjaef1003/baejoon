#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int main() {
	string S, SAdd = "", tempS = "";
	string charI = "", charTemp = "";
	int temp;
	cin >> S;
	temp = S.size() - 1;

	for (int i = 0; i < S.size(); i++) {
		if (i == temp) {
			break;
		}
		if (S[i] != S[temp]) {
			if (!tempS.empty()) {
				i = i - tempS.size();
				for (int j = tempS.size() - 1; j > i; j--)
					tempS.pop_back();
				for (int j = 0; i < i; j++)
					SAdd.push_back(tempS[j]);
				tempS.clear();
				temp = S.size() - 1;
			}
			SAdd.push_back(S[i]);
		}
		else {
			tempS.push_back(S[i]);
			temp--;
		}
	}

	if (!SAdd.empty()) {
		for (int i = SAdd.size() - 1; i > -1; i--) {
			S.push_back(SAdd[i]);
		}
	}

	cout << S.size() << endl;
	return 0;
}
