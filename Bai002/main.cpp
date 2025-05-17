#include <iostream>
#include <cmath>
using namespace std;
double calculateA() {
    return (sqrt(5) - 1) / 2;
}
int hashFunction(int key, int m, double A) {
    double kA = key * A;
    double fraction = kA - floor(kA);  // lay phan thap phan (k*A mod 1)
    return floor(m * fraction);
}
int main() {
    int m = 1000;
    double A = calculateA();
    int keys[] = {61, 62, 63, 65};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Gia tri A = " << A << endl;
    cout << "Vi tri cua cac khoa trong bang bam:" << endl;
    for (int i = 0; i < n; i++) {
        int position = hashFunction(keys[i], m, A);
        cout << "h(" << keys[i] << ") = " << position << endl;
    }
    return 0;
}
