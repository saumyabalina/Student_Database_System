#include "student.h"

Student *add_student(char *name, int age, char *mail, int roll, char *address, Database *db, FILE *fPtr)
{
    Student *a = &(db->students[db->count++]);
    strcpy(a->name, name);
    a->age = age;
    strcpy(a->mail, mail);
    a->roll = roll;
    strcpy(a->address, address);
    fprintf(fPtr, "Name: %s\nAge: %d\nE-mail Address: %s\nRoll Number: %d\nAddress: %s\n\n", a->name, a->age, a->mail, a->roll, a->address);
    return a;
}

Student *age_19(Database *db)
{
    int num = 0;
    for (int i = 0; i < db->count; i++)
    {
        if (db->students[i].age == 19)
        {
            printf("%s\n", db->students[i].name);
            num++;
            continue;
        }
    }
    printf("\n");
    if (num == 0)
    {
        printf("No students of age 19\n\n");
    }
}

Student *find_mail(Database *db)
{
    int num = 0;
    for (int i = 0; i < db->count; i++)
    {
        if (db->students[i].mail[0] == 'I' || db->students[i].mail[0] == 'T')
        {
            printf("%s\n", db->students[i].name);
            num++;
            break;
        }
    }
    printf("\n");
    if (num == 0)
    {
        printf("No such student exists\n\n");
    }
}

Student *find_by_email(char *mail, Database *db)
{
    Student *b = NULL;
    for (int i = 0; i < db->count; i++)
    {
        if (strcmp(mail, db->students[i].mail) == 0)
        {
            b = &(db->students[i]);
            break;
        }
    }
}
