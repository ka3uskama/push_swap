#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])              
{
    int i;

    i = 1;
    while (argv[i])
    {
        printf("%s\n", argv[i]);
        i++;
    }
    return (0);                       
}   


Elem *sa (Elem *head_of_stack_a)
{
    Elem *elem_1;
    Elem *elem_2;
    Elem *temp;

    elem_1 = (Elem *)malloc(sizeof(Elem));
    elem_2 = (Elem *)malloc(sizeof(Elem));

    if (!head_of_stack_a)
    {
        free(elem_1);
        free(elem_2);
        return (head_of_stack_a);
    }
    elem_1 = head_of_stack_a;
    printf("elem_1:%d\n", elem_1->value);
    elem_2 = head_of_stack_a->next;
    printf("elem_2:%d\n", elem_2->value);
    head_of_stack_a = remove_elem(head_of_stack_a);
    printf("head after removing #1 :%d\n", head_of_stack_a->value);
    head_of_stack_a = remove_elem(head_of_stack_a);
    printf("head after removing #2 :%d\n", head_of_stack_a->value);
    head_of_stack_a = add_new_elem(elem_1->value, head_of_stack_a);
    printf("head after adding #1 :%d\n", head_of_stack_a->value);
    head_of_stack_a = add_new_elem(elem_2->value, head_of_stack_a);
    printf("head after adding #2 :%d\n", head_of_stack_a->value);
    return (head_of_stack_a);
}



void sb (Elem *head_of_stack_b)
{
    int value_1;
    int value_2;
    Elem *try;

    value_1 = head_of_stack_b->value;
    try = head_of_stack_b->next;
    value_2 = try->value;
    if (number_of_elements(head_of_stack_b) <= 1)
        return ;
    head_of_stack_b = remove_elem(head_of_stack_b);
    head_of_stack_b = remove_elem(head_of_stack_b);
    head_of_stack_b = add_new_elem(value_1, head_of_stack_b);
    head_of_stack_b = add_new_elem(value_2, head_of_stack_b);
}