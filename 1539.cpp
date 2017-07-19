#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int P[250000];
class Vertex {
	int n;
	unsigned int h;
	Vertex *left, *right;
public:
	Vertex() {
		n = NULL;
		left = nullptr;
		right = nullptr;
	}
	Vertex(int _n, int _h) {
		n = _n;
		h = _h;
		left = nullptr;
		right = nullptr;
	}
	int getN() {
		return n;
	}
	unsigned int getH() {
		return h;
	}
	void setN(int _n) {
		n = _n;
	}
	void setH(unsigned int _h) {
		h = _h;
	}
	void setLeft(Vertex *_left) {
		left = _left;
	}
	void setRight(Vertex *_right) {
		right = _right;
	}
	Vertex* getLeft() {
		return left;
	}
	Vertex* getRight() {
		return right;
	}
};
int insert(Vertex *V, int X) {
	int result = 0;
	if (V == nullptr)
		printf("%d  ", V->getN());
	if (X < V->getN()) {
		if (V->getLeft() != nullptr) {
			result = insert(V->getLeft(), X);
		}
		else {
			V->setLeft(new Vertex(X, V->getH() + 1));
			return V->getH() + 1;
		}
	}
	else {
		if (V->getRight() != nullptr) {
			result = insert(V->getRight(), X);
		}
		else {
			V->setRight(new Vertex(X, V->getH() + 1));
			return V->getH() + 1;
		}
	}
	return result;
}

int main() {
	int N;
	//cin >> N;
	//cin >> P[0];
	scanf("%d", &N);
	scanf("%d", &P[0]);
	Vertex root(P[0], 1);
	unsigned int result = 1;
	for (int i = 1; i < N; i++) {
		scanf("%d", &P[i]);
		//cin >> P[i];
		result += insert(&root, P[i]);
	}
	//cout << result << endl;
	printf("%u\n", result);
	return 0;
}