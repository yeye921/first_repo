#include <iostream>
using namespace std;
int GCD(int a, int b) {
    while (1) {
        int r = a % b;
        if (r == 0) return b;

        a = b;
        b = r;
    }
}
int main(void) {
	int n, m;
	cin >> n >> m;
    
    if (m > n) {
        int tmp = n;
        n = m;
        m = tmp;
    }
    cout << GCD(n, m) << endl;
    
    int LCM = n * m / GCD(n, m);
    cout << LCM;
    
    return 0;
}
