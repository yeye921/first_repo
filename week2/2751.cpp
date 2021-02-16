#include <iostream>
using namespace std;
int main(void) {
	int N;
	bool cnt[1000001] = {false};  // 중복된 값이 없으므로 boolean 배열이용

	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cnt[arr[i]] = true;
	}

	for (int i = 0; i < 1000001; i++) {
		if (cnt[i] == true) {
			cout << i;
			if (i != 1000000)
				cout << endl;
		}
	}
	delete []arr;
	return 0;
}