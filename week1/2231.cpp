#include<iostream>
using namespace std;

int add_digit(int n) {
	int add = 0;

	for (int i = n; i > 0; i /= 10) {
		add += i % 10;
	}
	return add;
}
int main(void) {
	int N;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		if (i + add_digit(i) == N) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
