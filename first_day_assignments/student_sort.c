#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDLEN 64

typedef struct {
    int roll;
    char *name;
    float marks;
    char *contact;
} Student;

char lower_char(char ch) {
    return (ch>='A' && ch<='Z') ? ch-'A'+'a' : ch;
}

void sort_by_roll(Student arr[], int len) {
    int i, j;
    Student temp;
    for (i = 1; i < len; ++i)
        for (j = i-1; j >= 0; --j)
            if (arr[i].roll < arr[j].roll) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                --i;
            }
}

void sort_by_name(Student array[], int len) {
    int i, j, k;
    Student temp;
    int n_longest_name = 0;

    // finding max length
    for (i = 0; i < len; ++i) {
        int comparison = strlen(array[i].name);
        n_longest_name = (strlen(array[i].name) * comparison) + (n_longest_name * !comparison);
    }
    
    // starting from right to left
    for (i = n_longest_name-1; i >= 0; --i)

        // sorting words on the basis of columns
        for (j = 1; j < len; ++j)
            for (k = j-1; k >= 0; --k)
                if (lower_char(array[j].name[i]) < lower_char(array[k].name[i])) {
                    temp = array[j];
                    array[j] = array[k];
                    array[k] = temp;
                    --j;
                }
}

void sort_by_marks(Student arr[], int len) {
    int i, j;
    Student temp;
    for (i = 1; i < len; ++i)
        for (j = i-1; j >= 0; --j)
            if (arr[i].marks < arr[j].marks) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                --i;
            }
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
    Student students[] = {
        { 123, "Meow Kumar", 120.0, "+91 3253252345" },
        { 23, "Kuru Singh", 130.0, "+91 9912344532" },
        { 2, "Honey Mehta", 99.5, "+91 7737884323" },
        { 43, "Rizz Kumar", 20.5, "+91 8910332156" },
        { 60, "Chad Chottopadhyay", 150.0, "+91 7763422521" },
        { 5, "Dharam Paul", 130.0, "+91 2243113567" },
    };

    int i, length = 6;

    sort_by_roll(students, length);
    printf("Sorted by roll number\n");
    for (i = 0; i < length; ++i)
        print_student(&students[i]);

    sort_by_name(students, length);
    printf("\nSorted by name\n");
    for (i = 0; i < length; ++i)
        print_student(&students[i]);

    sort_by_marks(students, length);
    printf("\nSorted by marks\n");
    for (i = 0; i < length; ++i)
        print_student(&students[i]);

    return 0;
}
