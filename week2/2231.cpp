#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;

	int gen = -1;

	for (int i = 1; i <= 1000000; ++i)
	{
		int now = i;
		int sum = 0; 

		while (now != 0) {
			sum += (now % 10);
			now /= 10;
		}
		if (N == (i + sum)) {
			gen = i;
			break;
		}
	}
	if (gen == -1)
		cout << 0 << "\n";
	else
		cout << gen << "\n";
	return 0;
}