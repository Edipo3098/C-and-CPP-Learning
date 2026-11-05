#include <stdio.h>

typedef struct {
    char name[50];
    int edad;
    float nota_media;
} Student;

void print_student(const Student *s) {
    printf("Name: %s\n", s->name);
    printf("Edad: %d\n", s->edad);
    printf("Nota media: %.2f\n", s->nota_media);
}


void GetBetterGrade( Student * students, int n) {
    if (students == NULL || n <= 0) {
        return;
    }
    int best_index = 0;

    for (int i = 1; i < n; i++) {
        if (students[i].nota_media > students[best_index].nota_media) {
            best_index = i;
        }
    }
    students[best_index].nota_media += 0.5; // Modificamos la nota del mejor estudiante
    printf("\nMejor estudiante:\n");
    print_student(&students[best_index]);
}


void GetBetterGrade_noMod( const Student * students, int n) {
    if (students == NULL || n <= 0) {
        return;
    }
    int best_index = 0;

    for (int i = 1; i < n; i++) {
        if (students[i].nota_media > students[best_index].nota_media) {
            best_index = i;
        }
    }

    printf("\nMejor estudiante:\n");
    print_student(&students[best_index]);
}
int main() {
    Student students[3] = {
        {"Juan", 20, 8.5},
        {"Ana", 22, 9.1},
        {"Luis", 19, 7.8}
    };

    int n = sizeof(students) / sizeof(students[0]);
    GetBetterGrade(students, n);
    GetBetterGrade(&students[0], n);

    return 0;
}