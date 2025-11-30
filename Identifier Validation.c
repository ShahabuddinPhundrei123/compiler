//Manual Implementation of Identifier Validation using C
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int is_valid_name(char* name) {
    int i;
    if(!isalpha(name[0]) && name[0] != '_')
        return 0;
    for(i = 1; i < strlen(name); i++) {
        if(!isalnum(name[i]) && name[i] != '_')
            return 0;
    }
    return 1;
}
int main() {
    char name[100];
    printf("Enter a variable name: ");
    scanf("%s", name);

    if(is_valid_name(name))
        printf("Valid variable name\n");
    else
        printf("Invalid variable name\n");

    return 0;
}

