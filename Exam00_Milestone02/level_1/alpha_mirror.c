#include <unistd.h>

// hi, this code was made by flavides during the 42 Common Core!

void alpha_mirror(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] =  'z' + 'a' - s[i];
        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] =  'Z' + 'A' - s[i];
        write(1, &s[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        alpha_mirror(av[1]);
    write(1, "\n", 1);
    return (0);
}
