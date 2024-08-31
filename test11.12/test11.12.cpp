#include <iomanip>
#include <fstream>
#include <windows.h> 
#include <iostream> 
#include <locale.h>
#include <string> 
#include<vector>
#include<stdexcept>
#include <algorithm>
#include <conio.h>
#include <Windows.h>

using namespace std;

template<class T>
class Transaction {
    T* currentState = nullptr;
    T* prevState = nullptr;
public:
    Transaction() :prevState(NULL), currentState(new T) {}
    Transaction(T object) : prevState(nullptr), currentState(new T(object)) {}
    Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}
    ~Transaction() {
        delete currentState;
        delete prevState;
    }

    void beginTransactions() {
        delete prevState;
        prevState = currentState;
        currentState = new T(*prevState);
    }
    void commit() {
        delete prevState;
        prevState = NULL;
    }
    void deleteTransactions() {
        if (prevState != NULL) {
            delete currentState;
            currentState = prevState;
            prevState = NULL;
        }
    }
    Transaction& operator=(const Transaction& obj) {
        if (this != &obj) {
            delete currentState;
            currentState = new T(*(obj.currentState));
        }
        return *this;
    }
    T* operator->() {
        return currentState;
    }
};
bool isNumeric() {
    if (cin.get() == '\n')
        return true;
    else {
        cin.clear();
        cin.ignore(1024, '\n');
        return false;
    }
}
class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "Произошла пользовательская ошибка \n";
    }
};
class Meal
{
public:
    string name;
    int cost;
    Meal(string name, int cost) : name(name), cost(cost) {}
    Meal()
    {
        name = "Рис";
        cost = 399;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_cost(int cost)
    {
        this->cost = cost;
    }
    string get_name() { return name; }
    int get_cost() { return cost; }
    void showProduct()
    {
        cout << "\nНазвание блюда: " << get_name();
        cout << "\nЦена: " << get_cost();
    }
};
ostream& operator << (ostream& res, const Meal& meal)
{
    res << meal.name << " " << meal.cost << " ";
    return res;
}
istream& operator >>(istream& result, Meal& meal) {
    getline(result, meal.name, ' ');
    result >> meal.cost;
    result.ignore();
    return result;
}

class User {

private:
    string maskedInput() {
        const char BACKSPACE = 8;
        const char RETURN = 13;

        string input_password;
        char ch = 0;

        while ((ch = _getch()) != RETURN) {
            if (ch == BACKSPACE) {
                if (input_password.length() != 0) {
                    cout << "\b \b";
                    input_password.resize(input_password.length() - 1);
                }
            }
            else {
                cout << '*';
                input_password += ch;
            }
        }
        cout << endl;
        return input_password;
    }

public:
    string username;
    string password;

    bool login() {
        string input_username, input_password;
        bool isLoggedIn = false;
        while (!isLoggedIn) {
            cout << "Enter username: ";
            cin >> input_username;
            cout << "Enter password: ";
            input_password = maskedInput();

            if (input_username == username && input_password == password) {
                cout << "Login successful as User.\n";
                isLoggedIn = true;
            }
            else {
                cout << "Login failed. Invalid username or password. Please try again.\n";
            }
        }
        return isLoggedIn;
    }

    void logout() {
        cout << "Вы вышли из аккаунта.\n";
    }

    void saveToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << username << "\n";
            file << password << "\n";
            file.close();
        }
        else {
            cout << "Unable to open file for saving.\n";
        }
    }

    void readFromFile(string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            getline(file, username);
            getline(file, password);
            file.close();
        }
        else {
            cout << "Unable to open file for reading.\n";
        }
    }
};

class Order
{
    bool isEmpty() {
        if (!chek.size()) {
            cout << "Вы еще ничего не купили!\n";
            return 1;
        }
        return 0;
    }
public:
    vector<Meal> meals;
    vector<Meal> chek;
    int size = 0;
    Order()
    {
        /* meals.resize(4);
         meals[0] = Meal("Фунчоза", 200);
         meals[1] = Meal("Чисбургер", 100);
         meals[2] = Meal("Кофе", 50);
         meals[3] = Meal("Ангус", 100);*/

    }
    void showAll() {
        cout << endl;
        cout << "----------------------------------------------------\n";
        cout << "|" << setw(10) << left << "Номер" << setw(21) << left << "|Название" << setw(16) << left << "|Цена" << "|\n";
        cout << "----------------------------------------------------\n";
        for (int i = 0; i < meals.size(); i++) {
            cout << "|" << setw(10) << i + 1 << "|" << setw(20) << meals[i].get_name() << "|" << setw(14) << meals[i].get_cost() << "|\n";
            cout << "----------------------------------------------------\n";
        }
        cout << endl;
    }
    void AddProduct(Meal meal) {
        meals.push_back(meal);
    }
    void Input_file_menu(ofstream& file) {
        for (Meal& meal : meals)
            file << meal;
    }
    void Output_file_menu(ifstream& file)
    {
        Meal meal;
        while (file >> meal)
        {
            meals.push_back(meal);
        }
    }
    void Input_file_check(ofstream& file) {
        for (Meal& meal : chek)
            file << meal;
    }
    void Output_file_check(ifstream& file)
    {
        Meal meal;
        while (file >> meal)
        {
            chek.push_back(meal);
        }
    }
    void purchase()
    {
        cout << "Введите порядковый номер блюда, который хотите заказать:";
        try
        {
            int k;
            int i;
            cin >> i;
            if (cin.fail()) { throw MyException(); }
            if (!(i >= 1 && i <= meals.size())) { throw MyException(); }
            cout << "Вы добавили " << meals[i - 1].get_name() << " стоимостью " << meals[i - 1].get_cost() << " рублей " << endl;
            chek.push_back(meals[i - 1]);
            cout << "!!! СПАСИБО ЗА ПОКУПКУ !!!" << endl;
        }
        catch (const MyException& e) {
            cout << e.what();
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    }
    void showCheck()
    {
        if (isEmpty()) { return; }
        double summ = 0;
        cout << endl;
        cout << "----------------------------------------------------\n";
        cout << "|" << setw(10) << left << "Номер" << setw(21) << left << "|Название" << setw(16) << left << "|Цена" << "|\n";
        cout << "----------------------------------------------------\n";
        for (int k = 0; k < chek.size(); k++) {
            cout << "|" << setw(10) << k + 1 << "|" << setw(21) << chek[k].get_name() << "|" << setw(16) << chek[k].get_cost() << "|\n";
            cout << "----------------------------------------------------\n";
            summ += chek[k].get_cost();
        }
        cout << endl;
        cout << summ << " бунов " << endl;
        cout << endl;
    }
    Meal* FindMealByName(const string& searchname, int& i)
    {
        for (Meal& instrument : meals)
        {
            i += 1;
            if (instrument.get_name().find(searchname) != string::npos)
            {
                cout << "Название: " << meals[i].get_name() << endl << "Цена: " << meals[i].get_cost() << endl;
                return &instrument;
            }
        }
        return nullptr;
    }
    Meal* FindCheckByName(const string& searchname, int& i)
    {
        for (Meal& instrument : chek)
        {
            i += 1;
            if (instrument.get_name().find(searchname) != string::npos)
            {
                cout << "Название: " << chek[i].get_name() << endl << "Цена: " << chek[i].get_cost() << endl;
                return &instrument;
            }
        }
        return nullptr;
    }
    void Delete_meal(int i) {
        int last = meals.size() - 1;
        auto iter = meals.cbegin();
        meals.erase(iter + i);
    }
    void Delete_check(int i) {
        int last = chek.size() - 1;
        auto iter = chek.cbegin();
        chek.erase(iter + i);
    }
};

void Fun(string name, Order order)
{
    int i = -1;
    cout << "Введите название блюда: ";
    cin >> name;
    Meal* founMeal = order.FindMealByName(name, i);
    if (founMeal)
    {
        founMeal->get_name();
    }
    else
    {
        cout.setf(ios::right);
        cout.width(50);
        cout << "Блюдо с таким названием не найдено." << endl;
    }
}
void terminateFunc()
{
    cout << "\nНаша платформа завершила работу, из-за некоректного ввода. Пожалуйства в следущий раз будьте осторожнее со своим выбором." << endl;
    exit(-1);
}

class Admin : public User {
private:
    string maskedInput() {
        const char BACKSPACE = 8;
        const char RETURN = 13;

        string input_password;
        char ch = 0;

        while ((ch = _getch()) != RETURN) {
            if (ch == BACKSPACE) {
                if (input_password.length() != 0) {
                    cout << "\b \b";
                    input_password.resize(input_password.length() - 1);
                }
            }
            else {
                cout << '*';
                input_password += ch;
            }
        }
        cout << endl;
        return input_password;
    }

public:
    bool login() {
        string input_username, input_password;
        bool isLoggedIn = false;
        while (!isLoggedIn) {
            cout << "Enter username: ";
            cin >> input_username;
            cout << "Enter password: ";
            input_password = maskedInput();

            if (input_username == username && input_password == password) {
                cout << "Login successful as User.\n";
                isLoggedIn = true;
            }
            else {
                cout << "Login failed. Invalid username or password. Please try again.\n";
            }
        }
        return isLoggedIn;
    }

    void deleteUser(User& user) {
        cout << "User " << user.username << " has been deleted.\n";
    }

    void changeUserCredentials(User& user, string newUsername, string newPassword) {
        user.username = newUsername;
        user.password = newPassword;
        cout << "User credentials have been updated.\n";
    }

    void changeMenu(vector<string>& menu) {
        int choice;
        cout << "Menu options:\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i] << endl;
        }
        cout << "Enter the number of the dish you want to modify: ";
        cin >> choice;
        if (choice >= 1 && choice <= menu.size()) {
            string newDish;
            cout << "Enter the new name for this dish: ";
            cin >> newDish;
            menu[choice - 1] = newDish;
            cout << "Menu item has been updated.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int res;
    User user;
    Admin admin;
    Order order;
    Order chek;
    Meal meal;
    ofstream menu("Menu.txt", ofstream::app);
    ifstream mune("Menu.txt");
    ofstream check("Check.txt", ofstream::app);
    ifstream cheku("Check.txt");
    user.readFromFile("user.txt");
    admin.readFromFile("admin.txt");
    chek.Output_file_check(cheku);
    chek.Output_file_menu(mune);
    order.Output_file_menu(mune);
    int cost;
    string name;

    while (1) {
        try {
            cout << "1. User Login\n2. Admin Login\n3. Новый пользователь\n4. Новый админ\n0. Завершение программы \nEnter choice: ";
            int choice;
            int number;
            cin >> choice;
            switch (choice) {
            case(1):
            {
                user.login();
                res = 1;
                while (res != 0) {
                    try {
                        int sw;
                        cout << endl;
                        cout << "Пользователь" << endl;
                        cout << "1. Сделать заказ" << endl;
                        cout << "2. Показать корзину" << endl;
                        cout << "3. Поиск блюда по названию в меню." << endl;
                        cout << "4. Удалить блюдо из заказа." << endl;
                        cout << "5. Просмотреть все меню." << endl;
                        cout << "0. Выход из аккаунта." << endl;
                        cin >> sw;
                        switch (sw) {
                        case(1):
                        {
                            chek.purchase();
                            break;
                        }
                        case(2):
                        {
                            chek.showCheck();
                            break;
                        }
                        case(3):
                        {
                            Fun(name, order);
                            break;
                        }
                        case(4):
                        {
                            int i = -1;
                            cout << "Введите название продукта: ";
                            cin >> name;
                            Meal* found_meal = chek.FindCheckByName(name, i);
                            if (found_meal) { chek.Delete_check(i); }
                            else {
                                cout.setf(ios::right);
                                cout.width(50);
                                cout << "Продукт с таким названием не найден." << endl;
                            }
                            break;
                        }
                        case(5):
                        {
                            order.showAll();
                            break;
                        }
                        case(6):
                        {
                            cout << "запись в файл" << endl;
                            fstream file("Check.txt", ios::out | ios::trunc);
                            file.close();
                            cheku.close();
                            cheku.open("Check.txt");
                            chek.Input_file_menu(check);
                            check.close();
                            cout << "Данные успешно записаны";
                            break;
                        }
                        case(0):
                        {

                            res = 0;
                        default:
                        {
                            break;
                        }
                        }
                        }
                    }
                    catch (const MyException& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                    catch (const exception& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                }
                break;
                cout << endl;
            }
            case(2):
            {
                admin.login();
                int action;
                res = 1;
                while (res != 0)
                {
                    try {
                        int s;
                        cout << endl;
                        cout << "Админ" << endl;
                        cout << "1. Удалить логин и пароли" << endl;
                        cout << "2. Изменить лоиг и пароль пользователя." << endl;
                        cout << "3. Добавить новое блюдо в меню." << endl;
                        cout << "4. Удалить блюдо из меню." << endl;
                        cout << "5. Показать все меню." << endl;
                        cout << "6. Запись в файл." << endl;
                        cout << "0. Выход из аккаунта." << endl;
                        cin >> s;
                        switch (s) {
                        case(1):
                        {
                            // В этом примере, admin может удалять только аккаунт пользователя
                            User userToDelete;
                            cout << "Enter the username of the user to delete: ";
                            cin >> userToDelete.username;
                            admin.deleteUser(userToDelete);
                            break;
                        }
                        case(2):
                        {
                            string newUsername, newPassword;
                            cout << "Enter username of the user to change credentials for: ";
                            cin >> newUsername;
                            cout << "Enter new username: ";
                            cin >> newUsername;
                            cout << "Enter new password: ";
                            cin >> newPassword;
                            admin.changeUserCredentials(user, newUsername, newPassword);
                            break;
                        }
                        case (3):
                        {
                            while (true) {

                                cout << "Название: ";
                                cin >> name;
                                cout << "Цена: ";
                                cin >> cost;
                                while (!isNumeric || !(cost >= 0)) {
                                    cout << "Некорректный ввод, цена не может быть отрицательной\n";
                                    cin >> cost;
                                    cout << endl;
                                }
                                meal.name = name;
                                meal.cost = cost;
                                order.AddProduct(meal);
                                break;
                            }
                            break;
                        }
                        case (4):
                        {
                            int i = -1;
                            cout << "Введите название блюда: ";
                            cin >> name;
                            Meal* found_meal = order.FindMealByName(name, i);
                            if (found_meal) { order.Delete_meal(i); }
                            else {
                                cout.setf(ios::right);
                                cout.width(50);
                                cout << "Блюдо с таким названием не найден." << endl;
                            }
                            break;
                        }
                        case (5):
                        {
                            order.showAll();
                            break;
                        }
                        case (6):
                        {
                            cout << "запись в файл" << endl;
                            fstream file("menu.txt", ios::out | ios::trunc);
                            file.close();
                            mune.close();
                            mune.open("Filegiat.txt");
                            order.Input_file_menu(menu);
                            menu.close();
                            cout << "Данные успешно записаны";
                        }
                        case(0):
                        {
                            res = 0;
                        default:
                        {
                            break;
                        }
                        }
                        }
                    }
                    catch (const MyException& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                    catch (const exception& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                }
                cout << endl;
                break;
            }
            case(3):
            {

                cout << "Enter user username: ";
                cin >> user.username;
                cout << "Enter user password: ";
                cin >> user.password;

                user.saveToFile("user.txt");
                break;
            }
            case(4):
            {
                cout << "Enter admin username: ";
                cin >> admin.username;
                cout << "Enter admin password: ";
                cin >> admin.password;
                admin.saveToFile("admin.txt");

                break;
            }
            case(0):
            {
                return 0;
            default:
            {
                break;
            }
            }
            }
        }
        catch (const MyException& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}
