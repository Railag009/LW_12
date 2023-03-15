// Дан двунаправленный список. Уменьшить на количество трёхзначных все элементы
// списка, ПОСЛЕ которых стоят четные.

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

int kol(int p)
{
    if (p > 0)
    {
        p /= 10;
        return kol(p) + 1;
    }
    else
    {
        return 0;
    }
}
int f1(list* p)
{
    if (p == NULL) return 0;   
    if (kol(p->info) == 3)return f1(p->next) + 1;
    return f1(p->next);
}
void f2(list* p, int s)
{
    
    if (p->next != NULL)
    {
        if (p->next->info % 2 == 0) p->info -= s;

        cout << setw(4) << p->info;

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
    f2(p, k);

}