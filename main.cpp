
#include "kmp.h"

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    KMP k(s2);
    cout << k.search(s1);
}