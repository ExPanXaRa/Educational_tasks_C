#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

void find_door_test(struct node* root);

int main() {
    struct door* test1 = (struct door*)malloc(sizeof(struct door));
    struct door* test2 = (struct door*)malloc(sizeof(struct door));
    struct door* test3 = (struct door*)malloc(sizeof(struct door));
    struct door* test4 = (struct door*)malloc(sizeof(struct door));
    struct door* test5 = (struct door*)malloc(sizeof(struct door));

    test1->id = 0;
    test2->id = 1;
    test3->id = 2;
    test4->id = 3;
    test5->id = 4;

    struct node* root = init(test1);
    add_door(root, test2);
    add_door(root, test3);
    add_door(root, test4);
    add_door(root, test5);

    find_door_test(root);

    destroy(root);

    return 0;
}

void find_door_test(struct node* root) {
    struct node* search = find_door(3, root);

    if (search != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    search = find_door(5, root);

    if (search == NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    remove_door(search, root);
}