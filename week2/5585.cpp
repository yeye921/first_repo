#include <iostream>
using namespace std;
int main(void) {
	int n; //���Ǳݾ�
	int cnt = 0; //��������
	int arr[6] = { 500, 100, 50, 10, 5, 1 };

	cin >> n;
	
	int m = 1000 - n; //�Ž�����

	for (int i = 0; i < 6; i++) {
		cnt += m / arr[i];
		m %= arr[i];
	}

	cout << cnt;
	return 0;
}