#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// hi, this code was made by flavides during the 42 Common Core!

int ft_atoi(const char *s)
{
    int i;
    int res;
    int sign;
    i = 0;
    res = 0;
    sign = 1;
    // remember to skip spacesssss
    if (s[0] && (s[0] == '-' || s[0] == '+' ))
    {
        i = 1;
        if (s[0] == '-')
            sign = -1;
    }
    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
            res = (res * 10) + s[i] - '0';
        i++;
    }
    return (res * sign);
}
/*
int main()
{
    printf("%d num da stringa\n", ft_atoi("234"));
    printf("%d num da stringa\n", atoi("234"));
    return(0);
}*/
