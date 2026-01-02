#include <iostream>
#include <chrono>
using namespace std;
void DeretAritmatikaRekursif(int a, int b, int n) {
    if (n == 0) {
        cout << "Deret kosong\n";
    } else if (n == 1) {
        cout << a << "\n";
    } else {
        cout << a << ", ";
        DeretAritmatikaRekursif(a + b, b, n - 1);
    }
}
