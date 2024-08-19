#include <stdio.h>



int main()
{
    int j[2370];
    int q[395];
    char l[200];
    int fi = 0;
    int se = 0;
    FILE *f = fopen("student-mat.csv" , "r");
    if (f == NULL)
    {
        perror("FILE FAILED 😹😹😹");
        return -1;
    }

    fgets(l, sizeof(l), f);

    while(fgets(l, sizeof(l), f) != NULL)
    {
        char *token;
        int c = 0;

        token = strtok(l, ";");
        while (token != NULL)
        {
            if(c == )
        }
    }
    

    return 0;
}