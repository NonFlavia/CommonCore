#include <unistd.h>
int main(int argc, char **argv)
{

    int i = 0;
    if (argc == 4 && (! argv[2][1] && ! argv[3][1]))
    {
        char tofix = argv[3][0];
        char c = argv[2][0];
        while (argv[1][i])
        {
            if (argv[1][i] == c)
                argv[1][i] = tofix;
            i++;
        }
        for (i = 0; argv[1][i]; i++)
            write(1, &argv[1][i], 1);
    }
    write(1, "\n", 1);
}
