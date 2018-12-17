#include <iostream>
using namespace std;
#define swap(a,b) a^=b^=a^=b

int main() {
	int a, b;
	while (cin >> a >> b) {
	  bool flag = false;
		if (a > b) swap(a, b);	// Keep a<=b
		while (b % a) {
			if (a > b) swap(a, b);
			if (b > 2 * a) break;
			b -= a;
			flag = !flag; // Give the other activation
		}
    cout << (flag ? "Nova" : "LaoWang") << endl;
	}
}