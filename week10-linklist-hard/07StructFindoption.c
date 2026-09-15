#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student_info {
    char name[61];
    char surname[61];
    char sex[10];
    unsigned int age;
    char id[13];
    double gpa;
    int order;
};

int cmpByName(const void *a, const void *b){
    const struct student_info *sa = (const struct student_info*) a;
    const struct student_info *sb = (const struct student_info*) b;
    int r = strcmp(sa->name, sb->name);
    return (r != 0) ? r : (sa->order - sb->order);
}

int cmpBySurname(const void *a, const void *b){
    const struct student_info *sa = (const struct student_info*) a;
    const struct student_info *sb = (const struct student_info*) b;
    int r = strcmp(sa->surname, sb->surname);
    return (r != 0) ? r : (sa->order - sb->order);
}

int cmpById(const void *a, const void *b){
    const struct student_info *sa = (const struct student_info*) a;
    const struct student_info *sb = (const struct student_info*) b;
    int r = strcmp(sa->id, sb->id);
    return (r != 0) ? r : (sa->order - sb->order);
}

int main(){
    int N = 20;
    struct student_info students[N];

    for(int i = 0; i < N; i++){
        scanf("%s %s %s %u %s %lf",
              students[i].name, students[i].surname, students[i].sex,
              &students[i].age, students[i].id, &students[i].gpa);
        students[i].order = i;
    }

    char option[20];
    scanf("%s", option);
    for(int i = 0; option[i] != '\0'; i++){
        option[i] = tolower((unsigned char) option[i]);
    }

    if(strcmp(option, "name") == 0){
        qsort(students, N, sizeof(struct student_info), cmpByName);
    } else if(strcmp(option, "surname") == 0){
        qsort(students, N, sizeof(struct student_info), cmpBySurname);
    } else if(strcmp(option, "id") == 0){
        qsort(students, N, sizeof(struct student_info), cmpById);
    }

    for(int i = 0; i < N; i++){
        char *title = (strcmp(students[i].sex, "Male") == 0) ? "Mr" : "Miss";
        printf("%s %c %s (%u) ID: %s GPA %.2f\n",
               title, students[i].name[0], students[i].surname,
               students[i].age, students[i].id, students[i].gpa);
    }

    return 0;
}
