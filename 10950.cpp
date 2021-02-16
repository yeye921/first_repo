#include<iostream>
int main(void) {
	int A[100], B[100];
	int n;

	std::cin >> n;

	for (int i = 0;i < n;i++) {
		std::cin >> A[i] >> B[i];
	}
	for (int i = 0;i < n;i++) {
		std::cout << A[i] + B[i] << std::endl;
	}
	return 0;
}