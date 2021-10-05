#include <iostream>
#include <cmath>
using namespace std;

int X;
int DP[1000001];

int recur(int N, int count) {
	int a, b, c;

	if (N == 1) {
		return count;
	}

	++count;

	if (N % 3 == 0) {
		a = recur(N / 3, count);
	}
	if (N % 2 == 0) {
		b = recur(N / 2, count);
	}
	c = recur(N - 1, count);

	return min(min(a, b),c);
}

int main() {
	cin >> X;

	//if (X == 1) { cout << 0 << "\n"; return 0;
	// cout << recur(X, 0) << "\n";

	for (int i = 2; i <= X; ++i) {
		DP[i] = DP[i - 1] + 1;
		
		if (i % 2 == 0)
			DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)
			DP[i] = min(DP[i], DP[i / 3] + 1);
	}
	cout << DP[X] << "\n";

	return 0;
}