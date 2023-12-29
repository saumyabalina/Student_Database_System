#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char name[100];
    int age;
    char mail[100];
    int roll;
    char address[100];
} Student;

typedef struct Database
{
    Student students[100];
    int count;
} Database;

Student *add_student(char *name, int age, char *mail, int roll, char *address, Database *db, FILE *fPtr);

Student *age_19(Database *db);

Student *find_mail(Database *db);

Student *find_by_email(char *mail, Database *db);