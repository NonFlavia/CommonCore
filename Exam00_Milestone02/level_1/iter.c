//


int issamechar(char c, char d)
{
    if (c == d)
        return (1);
    return (0);
}

/* str          str2
    c i a o     s c i s t r a o
    i          j */

void inter(char *str, char *str2)
{
    int i;
    i = 0;
    int j;
    j = 0;
    if (! str || ! str2)
        return;
   
    while (str[i])
    {
        while (str2[j] != '\0')
        {
            if (issamechar(str[i], str[j]))
                write(1, &str[j], 1);
            j++
        }
        j = 0;
        i++;
    }
    write (1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return;
    inter(argv[1], "ciaoooo");
    return(0);
}
