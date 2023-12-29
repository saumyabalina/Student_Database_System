#include "student.h"

int main()
{
    Database db;
    FILE *fPtr = fopen("StudentDatabase.txt", "w");
    if (fPtr == NULL)
    {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    db.count = 0;
    while (true)
    {
        printf("---------Student Database---------\nNumber of students: %d\n", db.count);
        printf("0:Add Student\n1:Students with age 19\n2:Students whose e-mail address starts with 'I' or 'T' and have even numbers\n3:Display student detail when e-mail is given\n4:To exit\n");
        Student *a;
        char name[100], mail[100], address[100];
        int age, roll;
        printf("Select Mode: ");
        int mode;
        scanf("%d", &mode);
        switch (mode)
        {
        case 0:
            printf("Enter student name: ");
            scanf("%s", name);
            scanf("%[^\n]s", name);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Enter e-mail address: ");
            scanf("%s", mail);
            printf("Enter roll number: ");
            scanf("%d", &roll);
            printf("Enter address: ");
            scanf("%s", address);
            if (age >= 17 && age <= 22)
            {
                a = add_student(name, age, mail, roll, address, &db, fPtr);
            }
            else
            {
                printf("Not a student\n");
            }
            break;
        case 1:
            age_19(&db);
            break;
        case 2:
            find_mail(&db);
            break;
        case 3:
            printf("Enter e-mail address: ");
            scanf("%s", mail);
            Student *b;
            b = find_by_email(mail, &db);
            printf("Student Details\nName: %s\nAge:%d\nRoll Number: %d\nAddress: %s\n\n", b->name, b->age, b->roll, b->address);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    fclose(fPtr);
    return 0;
}