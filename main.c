#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Types
#define TYPES_TITLE 31
#define TYPES_CHAPTERS 100

typedef struct {
    char title[TYPES_TITLE];
    int sentences;
} chapter;

typedef struct {
    chapter chapters[TYPES_CHAPTERS];
    int numChapters;
} book;

typedef struct bintreenode {
    int value;
    struct bintreenode *left;
    struct bintreenode *right;
} bintree;

// 2. Function to display book
void display(book b) {
    for (int i = 0; i < b.numChapters; i++) {
        printf("%d. chapter: %s, %d sentences\n", i + 1, b.chapters[i].title, b.chapters[i].sentences);
    }
}

// 3. Function to count chapters
int howManyChapters(book b) {
    return b.numChapters;
}

// 4. Function to get max in binary tree
int maxBinTree(bintree *b) {
    if (b == NULL) return -2147483648;
    int maxL = maxBinTree(b->left);
    int maxR = maxBinTree(b->right);
    int max = b->value;
    if (maxL > max) max = maxL;
    if (maxR > max) max = maxR;
    return max;
}

// 5. Implement the zh algorithm
void zh(int X[], int N, int Y[], int M, int Z[], int *P, int *Q) {
    int i = *Q;
    int j = *P;
    int k = 1;
    while (i > 0 && j > 0) {
        if (X[i] > Y[j]) {
            Z[k] = X[i] - Y[j];
            k++;
        }
        i--;
        j--;
    }
    *P = k;
    *Q = i;
    *P = j;
}

// Main function to test
int main() {
    book myBook;
    myBook.numChapters = 2;
    strcpy(myBook.chapters[0].title, "this is the title of the first chapter");
    myBook.chapters[0].sentences = 30;
    strcpy(myBook.chapters[1].title, "this is the title of the second chapter");
    myBook.chapters[1].sentences = 130;

    printf("Book display:\n");
    display(myBook);
    printf("Number of chapters: %d\n", howManyChapters(myBook));

    bintree node3 = {3, NULL, NULL};
    bintree node7 = {7, NULL, NULL};
    bintree node5 = {5, &node3, &node7};
    printf("Max in binary tree: %d\n", maxBinTree(&node5));

    int X[5] = {0, 10, 20, 30, 40};
    int Y[5] = {0, 5, 15, 25, 35};
    int Z[5] = {0};
    int P = 4, Q = 4;
    zh(X, 4, Y, 4, Z, &P, &Q);
    printf("Z array after zh: ");
    for (int i = 1; i < P; i++) printf("%d ", Z[i]);
    printf("\n");

    return 0;
}
