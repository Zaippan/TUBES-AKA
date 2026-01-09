#include <iostream>
#include <chrono>
using namespace std;


void DeretAritmatikaIteratif_Print(int a, int b, int n) {
    int suku = a;
    for (int i = 1; i <= n; i++) {
        cout << suku;
        suku += b;
    }
}

void DeretAritmatikaRekursif_Print(int a, int b, int n) {
    if (n == 0) {
        cout << "Deret kosong\n";
    } else if (n == 1) {
        cout << a ;
    } else {
        cout << a ;
        DeretAritmatikaRekursif_Print(a + b, b, n - 1);
    }
}

//untuk tidak ngeprint
long long Iteratif_NoPrint(int a, int b, int n) {
    long long sink = 0;
    int suku = a;
    for (int i = 1; i <= n; i++) {
        sink += suku;
        suku += b;
    }
    return sink;
}

long long Rekursif_NoPrint(int a, int b, int n) {
    if (n <= 0) return 0;
    if (n == 1) return a;
    return a + Rekursif_NoPrint(a + b, b, n - 1);
}


template <typename Func>
long long ukur_ns(Func f) {
    auto start = chrono::high_resolution_clock::now();
    volatile long long x = f(); // volatile biar ga dioptimasi
    (void)x;
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

int main() {
    int a = 1;
    int b = 5;
    int n = 100;

    cout << "\n hasil (tanpa print) ===\n";

    int repeat = 200; // ulang biar hasil lebih stabil

    long long tIter = ukur_ns([&]() {
        long long s = 0;
        for (int r = 0; r < repeat; r++) s += Iteratif_NoPrint(a, b, n);
        return s;
    });

    long long tRek = ukur_ns([&]() {
        long long s = 0;
        for (int r = 0; r < repeat; r++) s += Rekursif_NoPrint(a, b, n);
        return s;
    });

    cout << "n = " << n << " (diulang " << repeat << "x)\n";
    cout << "Iteratif : " << tIter << " ns\n";
    cout << "Rekursif : " << tRek << " ns\n";

    return 0;
}
