#include <stdio.h>
#include <stdlib.h>
typedef struct{
    const char * name;
    int edad;
    float nota_media;
}Student;

void print_student(Student *s){
    printf("Name: %s\n", s->name);
    printf("Edad: %d\n", s->edad);
    printf("Nota media: %.2f\n", s->nota_media);
}

int main(){
    Student *s1 = malloc(sizeof *s1);
    if (s1 == NULL) {
        fputs("Could not allocate student\n", stderr);
        return EXIT_FAILURE;
    } 
    s1->name = "Juan";
    s1->edad = 20;
    s1->nota_media = 8.5;

    print_student(s1);
    free(s1); 

    Student s2 = {"Maria", 22, 9.0};
    print_student(&s2);
    return 0;



}