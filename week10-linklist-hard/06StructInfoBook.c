#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_info {
    char *name;
    char *surname;
    char *sex;
    unsigned int age;
    char *id;
    double gpa;
};

int main(){

    struct student_info s;
    s.name    = (char*) malloc(sizeof(char) * 61);
    s.surname = (char*) malloc(sizeof(char) * 61);
    s.sex     = (char*) malloc(sizeof(char) * 10);
    s.id      = (char*) malloc(sizeof(char) * 13);
    char *title = (char*) malloc(sizeof(char) * 10);

    scanf("%s %s %s %u %s %lf", s.name, s.surname, s.sex, &s.age, s.id, &s.gpa);

    if(strcmp(s.sex, "Male") == 0){
        strcpy(title, "Mr");
    } else {
        strcpy(title, "Miss");
    }

    printf("%s %c %s (%u) ID: %s GPA %.2f\n", title, s.name[0], s.surname, s.age, s.id, s.gpa);

    free(s.name);
    free(s.surname);
    free(s.sex);
    free(s.id);
    free(title);

    return 0;
}
