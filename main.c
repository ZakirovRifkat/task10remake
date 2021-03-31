#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define size 80
void zadan3(char *str){
    int n=0,i=0;
        while (str[n + 1] != '\0') {
        if (str[n] == str[n + 1]) {
           // str[n] = ' ';
            i = n;
            while (str[i] != '\0') {
               // printf("%d ", i);
                str[i] = str[i + 1];
                i++;
            }
        }
        else {
            n++;
        }


    }


    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
}
int main()
{
    setlocale(LC_ALL,"Rus");
    char *str, *istr, *last, *str_copy, *str_copy_2, *str_copy_3, *str_copy_4;

    str_copy=(char*)malloc(sizeof(char)*size);
    last=(char*)malloc(sizeof(char)*size);
    str=(char*)malloc(sizeof(char)*size);
    str_copy_2=(char*)malloc(sizeof(char)*size);
    str_copy_3=(char*)malloc(sizeof(char)*size);
    str_copy_4=(char*)malloc(sizeof(char)*size);


    printf("Введите строку\n");

    FILE *f;

    f=fopen("text.txt","w");
    fgets(str,size,stdin);
    fputs(str,f);
    fclose(f);

    f=fopen("text.txt", "r");
    fscanf(f,"%[^\n]",str);

    strcpy(str_copy, str);
    strcpy(str_copy_2, str);
    strcpy(str_copy_3, str);

    printf("\nПоследнее слово\n");
    char *a=strtok(str_copy_2," .");
    while (a!=NULL)
    {
        last=a;
        a=strtok (NULL," .");
    }

    char *p=strtok(str_copy_3," .");
    int h=0;
    while (p!=NULL)
    {
        if (strcmp(p,last)!=0)
        {
            fprintf(stdout,"%s ",p);
            for(int i=0; i<strlen(p); i++)
            {
                str_copy_4[h]=p[i];
                h++;

            }
            str_copy_4[h]=' ';
            h++;
        }
        p=strtok(NULL," .");
    }
    str_copy_4[h]='\0';

    fclose(f);
    printf("\n\nудвоенные буковки\n");
    zadan3(str);


    return 0;

}
