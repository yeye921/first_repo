#include <iostream>
int main(void)
{
	int N;
	std::cout << "�����Է�\n";
	std::cin >> N;

	for (int i = 1;i < 10;i++) {
		std::cout << N << " * " << i << " = " << N * i << std::endl;
	}
	return 0;
}