#include <unistd.h>
#include <stdio.h>
int ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return(1);
    return(0);
}

int main(int argc, char **argv)
{
    int i;
    i = 0;
    int end;
    end = 0;
    int space = 0;
    if (argc == 2)
    {
        while(argv[1][i])
            i++;
        i  -= 1;
        space = i;
       while ( space >= 0 && ft_isspace(argv[1][space]))
            space--;
        end = space;
        while (space >= 0  && ! ft_isspace(argv[1][space]))
                space--;
        space++;
        while(space <= end)
        {
            write(1, &argv[1][space], 1);
            space++;
        }
    }
    write(1, "\n", 1);
}
