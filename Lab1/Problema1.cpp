#include <iostream>

int strToInt(char* str) {
    int rez = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') { 
            rez = rez * 10 + (*str - '0');
        }
        str++;
    }
    return rez;
}

int main() {
    FILE* file;
    if (fopen_s(&file, "ini.txt", "r") != 0) {
        printf("Eroare deschidere fisier\n");
        return 0;
    }

    char line[25]; //am presupus ca numerele nu au mai mult de 24 de caractere
    int sum = 0;

    while (fgets(line, sizeof(line), file)) {
        sum += strToInt(line);
    }

    fclose(file);

    printf("%d\n", sum);
    return 0;
}
