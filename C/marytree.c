#include <stdio.h>
#include <stdlib.h>

struct node {
        void            *val;
        struct node     *parent;
        struct node     *left;
        struct node     *right;
};

void mktree(struct node *head, int depth);
void traverse(struct node *head);
void freetree(struct node *head);

int main(int argc, char *argv[])
{
        struct node head;
        
        head.parent = NULL;
        mktree(&head, atoi(argv[1]));
        traverse(&head);
        return 0;
}

void mktree(struct node *head, int d)
{
        if (d <= 0) {
                head -> left = NULL;
                head -> right = NULL;
                return;
        }
        if ((head -> left = malloc(sizeof(struct node))) == NULL || (head -> right = malloc(sizeof(struct node))) == NULL) {
                fprintf(stderr, "%s\n", "malloc() err");
                return;
        }
        head -> left -> parent = head;
        head -> right -> parent = head;
        mktree(head -> left, d - 1);
        mktree(head -> right, d - 1);
}

void traverse(struct node *head)
{
        if (!head -> left && !head -> right)
                return freetree(head);
        traverse(head -> left);
        traverse(head -> right);
}

void freetree(struct node *head)
{
        if (!head)
                return;
        if (head -> left)
                free(head -> left);
        if (head -> right)
                free(head -> right);
        freetree(head -> parent);
}
