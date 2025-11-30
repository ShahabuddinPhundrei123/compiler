//Manual Implementation of Comment Line Recognition using C
#include <stdio.h>
#include <string.h>
int main() {
    char line[100];

    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);
    if ((line[0] == '/' && line[1] == '/') || (line[0] == '/' && line[1] == '*')) {
        printf("This is a comment line\n");
    } else {
        printf("This is not a comment line\n");
    }
    return 0;
}

