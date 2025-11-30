//Computation of FOLLOW Sets for a Given Context-Free Grammar
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void follow(char);
void followfirst(char, int, int);
char production[20][20];
char followset[20];
int m = 0, count;
char calc_first[20][20];
void follow(char c) {
    int i, j;
    if (production[0][0] == c)
        followset[m++] = '$';
    for (i = 0; i < count; i++) {
        for (j = 2; j < strlen(production[i]); j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0')
                    followfirst(production[i][j + 1], i, j + 2);
                else if (production[i][0] != c)
                    follow(production[i][0]);
            }
        }
    }
}
void followfirst(char c, int c1, int c2) {
    int i, j = 1;
    if (!isupper(c)) {
        followset[m++] = c;
        return;
    }
    for (i = 0; i < count; i++) {
        if (calc_first[i][0] == c)
            break;
    }
    while (calc_first[i][j] != '\0') {
        if (calc_first[i][j] != '#')
            followset[m++] = calc_first[i][j];
        else {
            if (production[c1][c2] == '\0')
                follow(production[c1][0]);
            else
                followfirst(production[c1][c2], c1, c2 + 1);
        }
        j++;
    }
}
int main() {
    int i, j, n;
    char lhs, rhs[20];
    printf("Enter number of productions: ");
    scanf("%d", &count);
    printf("Enter productions (Format: X=abc):\n");
    for (i = 0; i < count; i++)
        scanf("%s", production[i]);
    printf("\nEnter number of FIRST entries: ");
    scanf("%d", &n);
    printf("Enter FIRST table (Format: Axyz):\n");
    for (i = 0; i < n; i++)
        scanf("%s", calc_first[i]);
    printf("\nFOLLOW Sets:\n");
    for (i = 0; i < count; i++) {
        char c = production[i][0];
        m = 0;
        follow(c);
        printf("FOLLOW(%c) = { ", c);
        for (j = 0; j < m; j++)
            printf("%c ", followset[j]);
        printf("}\n");
    }
    return 0;
}

