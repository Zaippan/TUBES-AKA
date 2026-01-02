#include <iostream>
#include <chrono>
using namespace std;

void DeretAritmatikaIteratif_Print(int a, int b, int n) {
    int i;
    int suku;
    suku = a;
    for (i = 1; i <= n; i++) {
        cout << suku;
        suku += b;
    }
}
