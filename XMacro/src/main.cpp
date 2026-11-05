#include <stdio.h>
#define ListOfFruits \
    X(Apples ,10) \
    X(Oranges ,20) \
    X(Bananas ,30)


#define X(arg, value) \
int arg ## _function(){ \
    return value ; \
}
ListOfFruits
#undef X

int main() {
    #define X(arg, value) #arg,
    const char *FruitNames[] = {  ListOfFruits};
    #undef X
    #define X(name, value) name = value,

    enum Fruit {
    ListOfFruits
    };

    #undef X

    printf("Value of Apples: %d\n", Apples_function());

  
    for( size_t i = 0; i < sizeof(FruitNames)/sizeof(FruitNames[0]); i++) {
        printf("%s\n", FruitNames[i]);
        
    }


   
    
    return 0;
}