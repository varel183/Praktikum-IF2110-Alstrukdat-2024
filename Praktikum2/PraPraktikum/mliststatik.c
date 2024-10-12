#include <stdio.h>
#include <stdbool.h>
#include "liststatik.c"

int main() {
    ListStatik l;
    ElType val;
    IdxType idx;

    // Initialize the list
    CreateListStatik(&l);

    // Read elements into the list
    printf("Enter the number of elements and the elements themselves:\n");
    readList(&l);

    // Print the list
    printf("Initial list: ");
    printList(l);
    printf("\n");

    // Insert an element at the beginning
    printf("Enter a value to insert at the beginning: ");
    scanf("%d", &val);
    insertFirst(&l, val);
    printf("List after inserting at the beginning: ");
    printList(l);
    printf("\n");

    // Insert an element at a specific index
    printf("Enter a value and index to insert at: ");
    scanf("%d %d", &val, &idx);
    insertAt(&l, val, idx);
    printf("List after inserting at index %d: ", idx);
    printList(l);
    printf("\n");

    // Insert an element at the end
    printf("Enter a value to insert at the end: ");
    scanf("%d", &val);
    insertLast(&l, val);
    printf("List after inserting at the end: ");
    printList(l);
    printf("\n");

    // Delete the first element
    deleteFirst(&l, &val);
    printf("List after deleting the first element (deleted value: %d): ", val);
    printList(l);
    printf("\n");

    // Delete an element at a specific index
    printf("Enter an index to delete at: ");
    scanf("%d", &idx);
    deleteAt(&l, &val, idx);
    printf("List after deleting at index %d (deleted value: %d): ", idx, val);
    printList(l);
    printf("\n");

    // Delete the last element
    deleteLast(&l, &val);
    printf("List after deleting the last element (deleted value: %d): ", val);
    printList(l);
    printf("\n");

    // Sort the list in ascending order
    sortList(&l, true);
    printf("List after sorting in ascending order: ");
    printList(l);
    printf("\n");

    // Sort the list in descending order
    sortList(&l, false);
    printf("List after sorting in descending order: ");
    printList(l);
    printf("\n");

    return 0;
}