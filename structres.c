
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    float height;
};

struct Person *createPerson(char *name, int age, float height) {
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));

    if (newPerson == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strncpy(newPerson->name, name, sizeof(newPerson->name) - 1);
    newPerson->name[sizeof(newPerson->name) - 1] = '\0';  
    newPerson->age = age;
    newPerson->height = height;

    return newPerson;
}

void showPerson(struct Person p) {
    printf("My name  is %s\n", p.name);
    printf("I am %d\n years old \n", p.age);
    printf("My height is %.2f m\n\n", p.height);
}

int main()
{
    struct Person * friends[3];
    friends[0] = createPerson("Dasha",19, 1.60);
    friends[1] = createPerson("Didi",19, 1.65);
    friends[2] = createPerson("Sofi",19, 1.75);
    for (int i=0; i<3; i++) {
       showPerson(*friends[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        free(friends[i]);
    }
    return 0;
}
