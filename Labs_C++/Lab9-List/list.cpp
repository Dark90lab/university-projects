#include <iostream>
#include "list.h"

using namespace std;
const int N = 3;
List::Elem::Elem(int v, List::Elem* n) : val(v), next(n) {}

ostream& operator<<(ostream& os, const List& list)
{
    if (!list.head)
        return os;
    //os << "[ ";
    for (List::Elem* ptr = list.head; ptr; ptr = ptr->next)
    {
        os << ptr->val;
        if (ptr->next != nullptr)
            os << "->";
    }
   // os << "]";
    return os;
}

void List::PushBack(int v)
{
    if (tail)
        tail = tail->next = new Elem(v);
    else
        tail = head = new Elem(v);
}

List::List()
{
    this->head = nullptr;
    this->tail = nullptr;
}

List::~List()
{
    clean();
}

bool List::isEmpty()
{
    if (head)
        return false;
    else
        return true;
}

void List::clean()
{
    if (!isEmpty())
    {
        Elem*tmp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        head = nullptr;
        tail = nullptr;
    }
}

List::List(const List& l)
{
   clean();                //l.clear;
    if (l.head == nullptr)
        return;
        head = tail = new Elem(l.head->val);
        if (l.head != l.tail)
        {
            for (Elem* check = l.head->next; check != l.tail; check = check->next)
                tail = tail->next = new Elem(check->val);
            tail = tail->next = new Elem(l.tail->val);
        }
        else
            return;
}

int List::Get()
{
    if (isEmpty())
        return 0;
    Elem* tmp = head;
    int result = tmp->val;
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        return result;
    }
    head = head->next;
    delete tmp;
    return result;
}

 
List& List::operator=(const List& l)
{
clean();                //l.clear;
if (l.head == nullptr)
return *this;
head = tail = new Elem(l.head->val);
if (l.head != l.tail)
{
    for (Elem* check = l.head->next; check != l.tail; check = check->next)
        tail = tail->next = new Elem(check->val);
    tail = tail->next = new Elem(l.tail->val);
    return *this;
}
else
    return *this;
}

void List::PushFront(int v)
{
    if (head)
    {
        Elem* tmp = new Elem(v);
        tmp->next = head;
        head = tmp;
    }
    else
        head = tail = new Elem(v);
 
}

int List::At(int i)
{
    int count = 0;
    Elem* e = head, *tmp=head;
    for (e ; e != nullptr; e = e->next)
        count++;
    if (i >= count || i < 0)
        return 0;
    for (int m= 0; m < i; m++)
        tmp = tmp->next;
    return tmp->val;

}
int List::Max()
{
    int max= 0;
    if (isEmpty())
        return 0;
    for (Elem* e = head; e != nullptr; e = e->next)
    {
        if (e->val > max)
            max= e->val;
    }
    return max;
}

//List List::SubList(int start, int len)
//{
//    List sub;
//    int count = 1;
//    if (start < 0 || isEmpty())
//       return sub;
//    for (Elem* e=head;e!= nullptr; e = e->next)
//    {   
//        if (count >= start && len>0)
//        {
//            sub.PushBack(e->val);
//        }
//        len--;
//        count++;
//    }
//    return sub;
//}


void List::Reverse()
{
    if (isEmpty() || head == tail)
        return;
    List tmp;
    for (Elem* e = head; e != nullptr; e = e->next)
        tmp.PushFront(e->val);
    *this = tmp;
}


int List::GetLast()
{
    if (isEmpty())
       return 0;
    int num = tail->val;
    if (head == tail)
    {
        clean();
        return num;
    }
    Elem* prev = head;
    for (prev; prev->next != tail; prev = prev->next){}
     prev->next = nullptr;
     tail = prev;
    
    return num;
}



int List::GetMax()
{
    if (head != nullptr && tail != nullptr)
    {
        int  x = Max();
        if (tail->val == x)
        {
            Reverse();
            Get();
            Reverse();
        }
        else if (head->val == x)
            Get();
        else
        {
            Elem* check = head;
            for (; check->next->val != x; check = check->next);
            Elem* tmp = check->next;
            check->next = check->next->next;
            delete[] tmp;
        }

        return x;
    }
    return 0;
}
int List::Remove(int v)
{
       int num = 0;
        bool appear;
        do
        {
            appear = false;
            if (head == nullptr)
            {
                tail = nullptr;
                return num;
            }
            else if (v == this->head->val)
            {
                appear = true;
                num++;
                this->Get();
            }
            else
            {
                for (Elem* e = head; e != nullptr; e = e->next)
                {
                    if (e->val == v)
                    {
                        appear = true;
                        break;
                    }
                }
                if (appear)
                {
                    num++;
                    Elem* check = head;
                    for (; check->next->val != v; check = check->next);
                    Elem* tmp = check->next;
                    check->next = check->next->next;
                    delete[] tmp;
                }
            }
        } while (appear != false);
            return num;
}

List& List::addNum(List& l)
{
   
    if (l.head && this->head)
    {
        int count = 0;
        int sum1, sum2,sum3;
        sum1 = sum2 = 0;
        int tmp1[N],tmp2[N];
        l.Reverse();
        this->Reverse();
        Elem* ptr1 = head;
        Elem* ptr2 = l.head;
        while (ptr1)
        {
            tmp1[count] = ptr1->val;
            tmp2[count] = ptr2->val;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            count++;
        }
        for (int i = 2; i >= 0; i--)
        {
            sum1 += pow(10, i) * tmp1[i];
            sum2 += pow(10, i) * tmp2[i];
        }
        clean();
        sum3 = sum1 + sum2;
        while (sum3)
        {
            int num = 0;
            num = sum3 % 10;
            sum3 /= 10;
            this->PushFront(num);

        }
        
    }
    return *this;
}


