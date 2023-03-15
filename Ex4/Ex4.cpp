// Дан двунаправленный список. Увеличить элементы расположенные ПОСЛЕ оканчивающихся на 3, в 2 раза.
//

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
void f2(list* p)
{

    if (p->info % 10 == 3) p->next->info *= 2;
    cout << setw(3) << p->info;

    if (p->next != NULL)
    {
        f2(p->next);
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
    f2(p);

}


