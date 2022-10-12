#include <iostream>
#include <string>
#include <cstdio>
#include "kmp.h"
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    KMP k(s2);
    cout << k.search(s1);
}