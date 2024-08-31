#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Пожалуйста, дождитесь конца таймера\n";

    for (int i = 10; i >= 1; i--) {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << i << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "\nТы пидор\n";

    system("pause");
    return 0;
}