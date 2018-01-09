#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
}Node;

Node *buildTree(int begin, int end, int *array)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
       printf("malloc error");
       exit(-1);
    }
    int avg = (begin + end) / 2;
    if (begin > end) {
        return NULL;
    } else if (begin == end) {
        node->left = NULL;
        node->right = NULL; 
    } else {
        node->left = buildTree(begin, avg - 1, array);
        node->right = buildTree(avg + 1, end, array);
    }
    node->value = array[avg];
    return node;
}

void printTree(Node *node)
{
    if (node) {
        printTree(node->left);
        printf("%d ", node->value);
        printTree(node->right);
    }
}

void main()
{
    int array[N];
    int i;
    for(i = 0; i < N; i++) {
        array[i] = i;
    }

    Node *rootNode;
    rootNode = buildTree(0, N-1, array);
    printTree(rootNode);
}
