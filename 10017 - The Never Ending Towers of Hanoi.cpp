#include <stdio.h>


int pegA[350], pegB[350], pegC[350];


int topA, topB, topC;


int step;


void printState() {
    if (step < 0)
        return;

    int i;
    printf("A=>");
    for (i = 0; i < topA; i++) {
        if (!i) printf("  ");
        printf(" %d", pegA[i]);
    }

    printf("\nB=>");
    for (i = 0; i < topB; i++) {
        if (!i) printf("  ");
        printf(" %d", pegB[i]);
    }

    printf("\nC=>");
    for (i = 0; i < topC; i++) {
        if (!i) printf("  ");
        printf(" %d", pegC[i]);
    }

    puts("\n");
    step--;
}


void moveDisk(char from, char to) {
    if (from == 'A' && to == 'B')
        pegB[topB++] = pegA[--topA];
    if (from == 'A' && to == 'C')
        pegC[topC++] = pegA[--topA];
    if (from == 'B' && to == 'A')
        pegA[topA++] = pegB[--topB];
    if (from == 'B' && to == 'C')
        pegC[topC++] = pegB[--topB];
    if (from == 'C' && to == 'A')
        pegA[topA++] = pegC[--topC];
    if (from == 'C' && to == 'B')
        pegB[topB++] = pegC[--topC];

    printState();
}


void hanoi(int n, char from, char aux, char to) {
    if (step < 0)
        return;

    if (n == 1) {
        moveDisk(from, to);
        return;
    } else {
        hanoi(n - 1, from, to, aux);
        moveDisk(from, to);
        hanoi(n - 1, aux, from, to);
    }
}


int main() {
    int n, caseNumber = 0;

    while (scanf("%d %d", &n, &step) == 2) {
        if (n == 0 && step == 0)
            break;

        printf("Problem #%d\n\n", ++caseNumber);

        topA = topB = topC = 0;


        for (int i = n; i >= 1; i--)
            pegA[topA++] = i;

        printState();
        hanoi(n, 'A', 'B', 'C');
    }

    return 0;
}
