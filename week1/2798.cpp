#include <iostream>
int main(void) {
	int N, M;
	int tmp = 0;
	int max = 0;

	std::cin >> N >> M;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	for (int i = 0; i < N-2; i++)
		for (int j = i + 1; j < N-1; j++)
			for (int k = j + 1; k < N; k++)
			{
				if (arr[i] + arr[j] + arr[k] <= M)
					tmp = arr[i] + arr[j] + arr[k];

				if (tmp > max)
					max = tmp;
			}

	std::cout << max << std::endl;
	return 0;
}
