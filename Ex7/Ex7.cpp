// Дан двунаправленный список. Если в нем есть симметричные элементы то заменить
// все кратные 5 их квадратами.
// 1 2 3 5 12321 6 15 51 40 0

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
int sim(int p, int s, int con)
{
    if (s == 0) return 0;

    int l = 1;
    for (int i = 1; i < s; i++)
    {
        l *= 10;
    }
    
    int r = p / l;
    return sim(p % l, s - 1, con) + (r * pow(10, con - s));

}
int f1(list* p)
{
    if (p == NULL) return 0;
    int i = kol(p->info);
    if (sim(p->info, i, i) == p->info)return f1(p->next) + 1;
    return f1(p->next);
}
void f2(list* p)
{

    if (p != NULL)
    {
        if (p->info % 5 == 0) p->info = pow(p->info, 2);

        cout << setw(7) << p->info;

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
   
    if (f1(p) > 0)
    {
        p = head;
        f2(p);
    }
    else
    {
        cout << "Not found simmetric number";
    }

}