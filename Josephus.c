#include <stdio.h>
#include <stdlib.h>

#define N NULL

int count = 0;

struct node {
    int data;
    struct node *next;
};

struct sll {
    struct node *last;
};

void insert(struct sll *list, int x) {
    struct node *pnode = (struct node *)malloc(sizeof(struct node));
    pnode->data = x;
    pnode->next = N;
    if (count == 0) {
        pnode->next = pnode;
        list->last = pnode;
        count++;
    } else {
        pnode->next = list->last->next;
        list->last->next = pnode;
        list->last = pnode;
        count++;
    }
}

void show(struct sll *list) {
    struct node *p = list->last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != list->last->next);
    printf("\n");
}

void removes(struct sll *list, int x) {
    struct node *temp = list->last;
    struct node *f;
    
    if (list->last->data == x) {
        f = list->last->next;
        while (f->next != list->last) {
            f = f->next;
        }
        f->next = list->last->next;
        list->last = list->last->next;
        count--;
        return;
    } else {
        for (int i = 0; i < count; i++) {
            if (temp->data == x)
                break;
            f = temp;
            temp = temp->next;
        }
        f->next = temp->next;
        if (temp == list->last)
            list->last = list->last->next;
        count--;
    }
}

void delete1(struct sll *list, int k) {
    struct node *p = list->last;
    printf("Elements deleted in order are:\n");
    while (count > 1) {
        for (int i = 0; i < k; i++) {
            p = p->next;
        }
        int x = p->data;
        printf("%d\n", p->data);
        removes(list, x);
        p = list->last; // Reset p to the new last
    }
    printf("Last element left: %d\n", list->last->data);
}

int main() {
    struct sll s;
    s.last = N;
    insert(&s, 1);
    insert(&s, 2);
    insert(&s, 3);
    insert(&s, 4);
    insert(&s, 5);
    show(&s);
    delete1(&s, 2);
    return 0;
}
