#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDLEN 64

typedef struct {
    int roll;
    char name[MAX_WORDLEN];
    float marks;
    char contact[MAX_WORDLEN];
} Student;

void get_string(char str[], int maxlen) {
    char ch;
    int length;
    while ((ch = getchar()) != '\n' && length < maxlen)
        str[length++] = ch;
    str[length] = '\0';
}

void print_student(const Student *student) {
    printf(
        "%s, roll number %d and contact %s, scored %.1f.\n",
        student->name,
        student->roll,
        student->contact,
        student->marks
    );
}

int main()
{
    Student student;
    printf("Name: ");
    get_string(student.name, MAX_WORDLEN);
    printf("Roll no: ");
    scanf("%d", &(student.roll));
    printf("Marks: ");
    scanf("%f", &(student.marks));
    getchar();
    printf("Contact: ");
    get_string(student.contact, MAX_WORDLEN);

    putchar('\n');
    print_student(&student);
    return 0;
}