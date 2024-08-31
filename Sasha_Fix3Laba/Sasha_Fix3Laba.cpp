#include<iostream>

using namespace std;

struct stack {
    int info;
    stack* next;
}*start, * t;

stack* push(stack* p, int in)
{
    t = new stack;
    t->info = in;
    t->next = p;
    return t;
}

void show(stack* p)
{
    t = p;
    while (t != NULL) {
        cout << " " << t->info;
        t = t->next;
    }
    cout << endl;
}

stack* delite(stack* p)
{
    stack* z = p, * t;
    while (z->next != NULL)
    {
        t = z->next;
        if (t->info % 10 != 0 && t->info % 5 == 0) {
            z->next = t->next;
            delete t;
        }
        else
            z = z->next;
    }
    z = p;
    if (z->info % 10 != 0 && z->info % 5 == 0) {
        p = z->next;
        delete z;
    }
    return p;
}

void sort1(stack** p)
{
    t = NULL;
    stack* t1, * r;
    if ((*p)->next->next == NULL) return;
    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next)
            if (t1->next->info > t1->next->next->info)
            {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        t = t1->next;

    } while ((*p)->next->next != t);
}

void sort2(stack* p)
{
    t = NULL;
    stack* t1;
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next)
            if (t1->info > t1->next->info)
            {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        t = t1;
    } while (p->next != t);
}


int main()
{
    setlocale(LC_ALL, "Rus");

    int i, in, n;
    stack* p = NULL;

    cout << "Введите кол-во элементов стека" << endl;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> in;
        start = push(start, in);
    }

    cout << "Изначальный вид стека: ";
    show(start);

    cout << "Удаление элементов, оканчивающихся на 5: ";
    start = delite(start);
    show(start);

    cout << "Сортировка стека перестановкой адресов: " << endl;
    sort1(&start);
    show(start);

    cout << "Сортировка стека перестановкой информации: " << endl;
    sort2(start);
    show(start);

    return 0;
}