#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int n, number = 1;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    clock_t start = clock();
    for (int i = n - 1, j = -1; i > j; i--) {
        if (arr[i] == number) {
            j = i;
            i = n;
            number++;
        }
    }

    cout << number - 1;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}