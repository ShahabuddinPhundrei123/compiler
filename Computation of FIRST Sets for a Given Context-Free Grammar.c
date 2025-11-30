#include <stdio.h>
#include <string.h>
#include <ctype.h>

char productions[20][20];
char firstSet[20];
int prodCount, m = 0;

void findFirst(char c);
void findFirstNext(char c, int pIndex, int pos);

void findFirst(char c) {
    int i;

    // If terminal
    if (!isupper(c)) {
        firstSet[m++] = c;
        return;
    }

    for (i = 0; i < prodCount; i++) {
        if (productions[i][0] == c) {
            if (productions[i][2] == '$')
                firstSet[m++] = '$';
            else
                findFirstNext(productions[i][2], i, 3);
        }
    }
}

void findFirstNext(char c, int pIndex, int pos) {
    int i;

    if (!isupper(c)) {
        firstSet[m++] = c;  
        return;
    }

    for (i = 0; i < prodCount; i++) {
        if (productions[i][0] == c) {
            if (productions[i][2] == '$') {
                if (productions[pIndex][pos] != '\0')
                    findFirstNext(productions[pIndex][pos], pIndex, pos + 1);
                else
                    firstSet[m++] = '$';
            } else {
                findFirstNext(productions[i][2], i, 3);
            }
        }
    }
}

int main() {
    int i, ch;
    char nonTerminal;

    printf("How many productions ?: ");
    scanf("%d", &prodCount);

    printf("Enter %d productions (epsilon=$):\n", prodCount);
    for (i = 0; i < prodCount; i++)
        scanf("%s", productions[i]);

    while (1) {
        printf("Element: ");
        scanf(" %c", &nonTerminal);

        m = 0;
        memset(firstSet, 0, sizeof(firstSet));

        findFirst(nonTerminal);

        printf("\nFIRST(%c)={ ", nonTerminal);
        for (i = 0; i < m; i++)
            printf("%c ", firstSet[i]);
        printf("}\n");

        printf("Press 1 to continue: ");
        scanf("%d", &ch);

        if (ch != 1)
            break;
    }

    return 0;
}

