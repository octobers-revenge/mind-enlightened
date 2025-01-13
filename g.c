#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LR 0.005
#define s 395
#define iter 1000

void strip_quotes(char *str) {
    size_t len = strlen(str);
    if (len > 1 && str[0] == '"' && str[len - 1] == '"') {
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}
void predictor(double data[s][6], double param[7], double pred[s]){
    for(int i = 0; i < s; i++){
        double total = 0;
        for(int j = -1; j < 6; j++){
            if(j == -1){
                total += param[0];
            }
            else{
                total += param[j+1] * data[i][j];
            }
            
        }
        pred[i] = total;
    }
}
void err(double pred[s], double real[s]){
    for(int i = 0; i < s; i++){
        pred[i] = pred[i] - real[i];
    }
}
//uses partial derivative (1/m)summation and updates param based on LR
void partial(double data[s][6], double param[7], double pred[s], double gradient[7]){
    double intercept_total = 0;
    for(int i = 0; i < s; i++){
        intercept_total += pred[i];
    }
    intercept_total /= s;
    gradient[0] = intercept_total;
    
    for(int i = 0; i < 6; i++){
        double total = 0;
        for(int j = 0; j < s; j++){
            total += (data[j][i]) * (pred[j]);
        }
        total /= s;
        gradient[i+1] = total;
        total = 0;
    }
    for(int i = 0; i < 7; i ++){
        param[i] = (param[i]) - (LR * gradient[i]);
    }

}

int main() {
    double param[7] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
    double pred[s];
    double real[s];
    double data[s][6];
    double gradient[7];
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
                    data[row][col] = 1.0;
                } else if (strcmp(token, "no") == 0) {
                    data[row][col] = 0.0;
                }
                col++;  
            } else if (i == 30) {  
                data[row][col] = atof(token);
                col++;
            } else if (i == 31) {  
                data[row][col] = atof(token);
                col++;
            } else if (i == 13) {  
                data[row][col] = atof(token);
                col++;
            } else if (i == 14) {  
                data[row][col] = atof(token);
                col++;
            } else if (i == 29) {  
                data[row][col] = atof(token);
                col++;
            } else if (i == 32) {  
                real[row] = atof(token);  
            }           
            token = strtok(NULL, ";");
        }       
        row++;  
    }

    fclose(file);

    
    for(int i = 0; i < 5; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < 6; j++) {
            printf("%.2f ", data[i][j]); 
        }
        printf("| Real: %.2f\n", real[i]);
    }

    
    for(int i = 0; i < 50000; i++){
        predictor(data, param, pred);
        err(pred, real);
        partial(data, param, pred, gradient);
    }
    printf("Intercept %f\n", param[0]);
    printf("StudyTime %f\n", param[1]);
    printf("Failures %f\n", param[2]);
    printf("Internet %f\n", param[3]);
    printf("Abscences %f\n", param[4]);
    printf("G1 %f\n", param[5]);
    printf("G2 %f\n", param[6]);
    return 0;

}