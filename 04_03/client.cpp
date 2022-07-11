#include<iostream>

#include "list.h"

int main() {
    List l = List();

    l.append(10);
    l.append(20);
    l.append(30);
    l.append(40);
    l.append(50);

    display(l.begin(), l.end());
    cout << acc3(l.begin(), l.end(), 60, Add());
    return 0;
}