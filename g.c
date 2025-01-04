#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LR 0.01
#define s 395

void strip_quotes(char *str) {
    size_t len = strlen(str);
    if (len > 1 && str[0] == '"' && str[len - 1] == '"') {
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}

int main() {
    double grad[7] = {0, 0, 0, 0, 0, 0, 0};
    double pred[s];
    double real[s];
    double data[6][s] = {0}; 
    FILE *file = fopen("student-mat.csv", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    int row = 0;
    char line[1024];
    fgets(line, sizeof(line), file); 

    while (fgets(line, sizeof(line), file)) {
        char *token;
        int col = 0;  
        token = strtok(line, ";");
        for (int i = 0; token && i < 33; i++) {
            strip_quotes(token); 

            if (i == 22) {  
                if (strcmp(token, "yes") == 0) {
                    data[col][row] = 1.0;
                } else if (strcmp(token, "no") == 0) {
                    data[col][row] = 0.0;
                }
                col++;  
            } else if (i == 30) {  
                data[col][row] = atof(token);
                col++;
            } else if (i == 31) {  
                data[col][row] = atof(token);
                col++;
            } else if (i == 13) {  
                data[col][row] = atof(token);
                col++;
            } else if (i == 14) {  
                data[col][row] = atof(token);
                col++;
            } else if (i == 29) {  
                data[col][row] = atof(token);
                col++;
            } else if (i == 32) {  
                real[row] = atof(token);  
            }           
            token = strtok(NULL, ";");
        }       

        row++;  
    }

    fclose(file);

    for (int i = 0; i < 5; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < 6; j++) {
            printf("%.2f ", data[j][i]);
        }
        printf("| Real: %.2f\n", real[i]);
    }

    return 0;
}