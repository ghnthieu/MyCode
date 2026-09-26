if (b == 0)
    return 1;
ll x = ltbinary(a, b/2);
if (b%2 == 1)
    return x * x * a;
else
    return x * x;