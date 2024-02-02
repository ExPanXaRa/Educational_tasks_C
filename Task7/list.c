#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(struct door* door) {
    struct node* door_2 = (struct node*)malloc(sizeof(struct node));
    door_2->door = door;
    door_2->next = NULL;
    return door_2;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* door_2 = (struct node*)malloc(sizeof(struct node));
    door_2->door = door;
    door_2->next = elem->next;
    elem->next = door_2;
    return door_2;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* find_door = NULL;
    struct node* now = root;
    int check = 0;

    while (now != NULL && check != 1) {
        if (now->door->id == door_id) {
            check = 1;
            find_door = now;
        }
        now = now->next;
    }

    return find_door;
}

struct node* remove_door(const struct node* elem, struct node* root) {
    struct node* new_root = root;

    if (elem != NULL && root != NULL) {
        if (root == elem) {
            new_root = root->next;
        } else {
            struct node* now = root;
            struct node* prew = NULL;
            while (now != NULL && now != elem) {
                prew = now;
                now = now->next;
            }
            if (now != NULL) {
                prew->next = now->next;
                free(now->door);
                free(now);
            }
        }
    }
    return new_root;
}

void destroy(struct node* root) {
    while (root != 0) {
        struct node* next = root->next;
        free(root->door);
        free(root);
        root = next;
    }
}