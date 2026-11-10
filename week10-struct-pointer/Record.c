#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char id[10];
    char name[100];
    long salary;
    long sales;
};

int main(){

    int n;
    char target[10];

    scanf("%d", &n);

    struct Record* records = (struct Record*) malloc(sizeof(struct Record) * n);

    for(int i = 0; i < n; i++){
        scanf(" %9s %99s %ld %ld", records[i].id, records[i].name, &records[i].salary, &records[i].sales);
    }

    scanf(" %9s", target);

    for(int i = 0; i < n; i++){
        if(strcmp(records[i].id, target) == 0){
            double commission = records[i].sales * 0.02;
            double total = records[i].salary + commission;

            printf("%s\n", records[i].id);
            printf("%s\n", records[i].name);
            printf("%ld\n", records[i].sales);
            printf("%.2f\n", commission);
            printf("%ld\n", records[i].salary);
            printf("%.2f\n", total);

            free(records);
            return 0;
        }
    }

    printf("ID not found !!!\n");

    free(records);
    return 0;
}
