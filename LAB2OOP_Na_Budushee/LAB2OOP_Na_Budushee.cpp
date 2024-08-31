#include <iostream>

using namespace std;

class Matrix {
    int** arr;
    int rows;
    int cols;
public:
    Matrix() : arr(NULL), rows(0), cols(0) {}
    Matrix(int rows, int cols) : arr(new int* [rows]), rows(rows), cols(cols) {
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
    }
    Matrix(const Matrix& ob) : arr(NULL), rows(0), cols(0) {
        rows = ob.rows;
        cols = ob.cols;
        arr = new int* [rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = ob.arr[i][j];
            }
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix.arr[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                is >> matrix.arr[i][j];
            }
        }
        return is;
    }
};
struct Spis {
    Matrix info;
    Spis* next;
};

void create(Spis*&, Spis*&, Matrix&);
void show(Spis*&);
void pop_all(Spis*&);

void create(Spis*& begin, Spis*& end, Matrix& in) {
    Spis* t = new Spis;
    t->info = in;
    t->next = NULL;
    if (begin == NULL)
        begin = end = t;
    else {
        end->next = t;
        end = t;
    }
}
void show(Spis*& begin)
{
    Spis* tool;
    tool = begin;
    cout << "\tМатрицы\n";
    while (tool != NULL)
    {
        cout << tool->info << endl;
        tool = tool->next;
    }
}
int main()
{
    Spis* begin = NULL, * end = NULL;
    setlocale(LC_ALL, "rus");
    bool menu = 1;
    int lever = 0;
    while (menu)
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить матрицу" << endl;
        cout << "2. Просмотреть определенную матрицу" << endl;
        cout << "3. Просмотреть все матрицы" << endl;
        cout << "4. Удалить все матрицы" << endl;
        cout << "0. Выход" << endl;
        cin >> lever;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Некорректный ввод, повторите попытку." << endl;
            cin >> lever;
        }

        int rows = 0, cols = 0;
        switch (lever)
        {
        case 1:
        {
            cout << "Введите кол-во строк и столбцов матрицы\n";
            cin >> rows;
            cin >> cols;
            Matrix ob(rows, cols);
            cout << "Введите матрицу\n";
            cin >> ob;
            create(begin, end, ob);
            show(begin);
            break;
        }
        case 2:
            break;
        case 3:
            show(begin);
            break;
        case 0:
            menu = 0;
            break;
        default:
            cout << "Некорректный ввод. Повторите попытку\n";
        }
    }
}