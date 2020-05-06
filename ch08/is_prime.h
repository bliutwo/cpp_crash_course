#ifndef ISPRIME_H
#define ISPRIME_H

#include <math.h>

// does not accept 1 or <= 0
inline bool is_prime(int x)
{
    if (x <= 0)
    {
        throw "is_prime does not accept x <= 0";
    }
    else if (x == 1)
    {
        throw "is_prime does not accept 1";
    }
    else if (x == 2)
    {
        return true;
    }
    else if (((x%2) == 0) && (x>3))
    {
        return false;
    }
    else
    {
        for (int i = 3; i < (sqrt(x) + 1); i+=2)
        {
            if((x%i)==0) return false;
        }
        return true;
    }
}

#endif
