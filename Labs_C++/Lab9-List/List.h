#pragma once

#include <iostream>

using namespace std;

class List
{

private:

    class Elem
    {
    public:
        int val;
        Elem* next;
        Elem(int v, Elem* n = nullptr);
        Elem() { val = 0, next = nullptr; };
  
    };

    Elem* head;
    Elem* tail;

    
    void clean();
    // You can add private members if you want

public:

    void PushBack(int v);
    
    // add members needed for part I
    bool isEmpty();
    List();
    ~List();
    List(const List&);
    List& operator=(const List&l);
    void PushFront(int v);
    int Get();
    int Max();
    int At(int i);
    //List SubList(int start, int len);
    void Reverse();
    int GetMax();
    int GetLast();
    int Remove(int v);
    friend bool isEqual(List& l, List& d);
    friend ostream& operator<<(ostream& os, const List& l);
    List& addNum(List& l);
};