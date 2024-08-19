#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    double j[2765];
    double q[395];
    char l[200];
    int fi = 0;
    int se = 7;
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
            if (c == 13)
            {
                j[fi] == atof(token);
                
            }
            if(c == 14)
            {
                j[fi+395] = atof(token);
            }
            if(c == 21)
            {
                if (strcmp(token, "yes") == 0)
                {
                    j[fi + 2 * 395] = 1;
                }
                else
                {
                    j[fi + 2 * 395] = 2;
                }
            }
            if (c == 29)
            {
                j[fi + 3 * 395] = atof(token);
            }
            if (c == 30)
            {
                j[fi + 4 * 395] = atof(token);
            }
            if (c == 31)
            {
                j[fi + 5 * 395] = atof(token);
            }
            if (c == 32)
            {
                q[fi] = atof(token);
                j[fi + 6 * 395] = 1;
                ++fi;
            }
            token = strtok(NULL , ";");
            ++c;

        }
    }
    

    return 0;
}