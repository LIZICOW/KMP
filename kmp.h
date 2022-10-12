#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

class KMP
{
private:
    int (*dp)[256];
    string pat;
    int len;

public:
    KMP(string pat);
    ~KMP();
    int search(string txt);
};

KMP::KMP(string Pat)
{
    pat = Pat;
    int N = pat.length();
    len = N;
    dp = new int[N][256];
    memset(dp, 0, sizeof(dp));
    if (dp == nullptr)
    {
        throw runtime_error("Dynamic memory request failed!");
    }

    //只有遇到pat[0]才更新X到1
    dp[0][pat[0]] = 1;

    int X = 0;

    for (int i = 1; i < N; i++)
    {
        for (int c = 0; c < 256; c++)
        {
            if (pat[i] == c)
            {
                dp[i][c] = i + 1;
            }
            else
            {
                dp[i][c] = dp[X][c];
            }
        }
        X = dp[X][pat[i]];
    }
}

KMP::~KMP()
{
    if (dp != nullptr)
        delete[] dp;
}

int KMP::search(string txt)
{
    int ltxt = txt.length();
    int j = 0;
    for (int i = 0; i < ltxt; i++)
    {
        j = dp[j][txt[i]];
        if (j == len)
            return i - len + 1;
    }
    return -1;
}