﻿// Дан двунаправленный список. Если сумма нечетных элементов больше 20, то уменьшить
// все элементы кратные 6 в 3 раза.

#include <iostream>
#include <iostream>
#include <iomanip>
using namespace std;

struct list
{
    int info;
    list* next;
    list* prev;
};

int f1(list* p)
{
    if (p == NULL) return 0;
    if (p->info % 2 != 0)return f1(p->next) + p->info;
    return f1(p->next);
}
void f2(list* p, int s)
{
    
    if (p->info % 6 == 0) p->info /= 3;
    
    cout << setw(3) << p->info;

    if (p->next != NULL)
    {
        f2(p->next, s);
    }
    else
    {
        return;
    }

}


int main()
{

    list* head, * p, * r;
    int x, k = 0;
    head = new list;
    cin >> x;
    head->info = x;
    head->next = NULL;
    p = head;

    cin >> x;

    while (x)
    {
        r = new list;
        r->info = x;
        r->next = NULL;
        p->next = r;
        p = r;
        cin >> x;
    }

    p = head;
    k = f1(p);

    p = head;
    if (k > 20)
    {

        f2(p, k);

    }
   
}