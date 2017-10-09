#include "enclave_t.h"

struct node_t {
    uint32_t value;
    struct node_t* next;
    struct node_t* prev;
};

int generate_random_number() {
    ocall_print("Processing random number generation...");
    return 42;
}

struct node_t * head = NULL;
struct node_t * tail = NULL;

int add_number(uint32_t value) {
    struct node_t* new_node = (struct node_t*) malloc(sizeof(node_t));
    if (new_node == NULL) {
        return 0;
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    return 1;
}

int del_number(uint32_t value) {
    // list empty? 
    if (head == NULL) {
        return 0;
    }

    // does list have only one node?
    if (head == tail) {
        if (head->value == value) {
            free(head);
            head = tail = NULL;
            return 1;
        } else {
            return 0;
        }
    }

    // list has many nodes.
    struct node_t* ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        if (ptr->value == value) {
            ptr->prev->next = ptr->next;
            if (ptr->next != NULL) {
                ptr->next->prev = ptr->prev;
            }
            free (ptr);
            return 1;
        }
    }
    return 0;
}

uint32_t get_sum(void) {
    struct node_t* ptr;
    uint32_t sum = 0;
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        sum += ptr->value;
    }
    return sum;
}
