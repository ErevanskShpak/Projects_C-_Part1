#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "����������, ��������� ����� �������\n";

    for (int i = 10; i >= 1; i--) {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << i << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "\n�� �����\n";

    system("pause");
    return 0;
}