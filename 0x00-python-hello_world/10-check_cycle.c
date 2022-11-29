#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @h: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;
    slow = fast = list;
   
    while(slow && fast && fast->next) {
        /* Slow pointer will move one node per iteration whereas 
        fast node will move two nodes per iteration */
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           return 1;
        }
    }

    return 0;
}
