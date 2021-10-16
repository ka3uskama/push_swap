/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casalaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:20:45 by casalaza          #+#    #+#             */
/*   Updated: 2021/10/10 16:20:50 by casalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Elem 
{
    int value;
    int order;
    int flag;
    struct Elem *next;
} Elem;

typedef struct Check 
{
    int value;
    int index;
} Check;

static long	result(char *str, int sign)
{
	int		i;
	long	res;

	res = 0;
	i = 0;
	while (str[i] >= (int)48 && str[i] <= (int)57)
	{
		if ((res * 10 + str[i] - '0') < res)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	res;
	char	*str1;

	str1 = (char *)str;
	i = 0;
	sign = 1;
	while ((str1[i] == '\v' || str1[i] == '\n' || str1[i] == '\r'
			|| str1[i] == '\f' || str1[i] == '\t' || str1[i] == ' '
			|| str1[i] == '\x1b') && (str1[i] != '\e'))
		i++;
	if (str1[i] == '+')
		i++;
	else if (str1[i] == '-')
	{
		sign = -1;
		i++;
	}
	res = result(&str1[i], sign);
	return ((int)res * sign);
}

void print_all(Elem **new_head_pointer)
{
    Elem current;

    if (!*new_head_pointer)
        return ;
    current = *(*new_head_pointer);
    while (true)
    {
        if (current.next != 0x0)
        {
            printf("%d\n", current.value);
            current = *(current.next);
        }
        else if (current.next == 0x0)
        {
            printf("%d\n", current.value);
            return;
        }
    }
}

Elem *add_new_elem(int value_pointer, Elem **head)
{
    Elem *tmp = (Elem *)malloc(sizeof(Elem));
    tmp->value = value_pointer;
    tmp->flag = 0;

    tmp->next = *head;
    return(tmp);
}

Elem *remove_elem(Elem **head)
{
    Elem *temp;

    if (!*head)
        return (*head);
    temp = *head;
    *head = (*head)->next;
    free(temp);
    return(*head);
}

void free_all(Elem **new_head_pointer)
{
    Elem *temp;
    if (!*new_head_pointer)
        return ;
    else if ((*new_head_pointer)->next != 0x0)
    {
        temp = (*new_head_pointer)->next;
        free(*new_head_pointer);
        free_all(&temp);
    }
    else if ((*new_head_pointer)->next == 0x0)
    {
        free(*new_head_pointer);
        return ;
    }
}

void free_all_check(Check **list)
{
    int i;

    i = 0;
    while (list[i])
    {
        free(list[i]);
        i++;
    }
    free(*list);
}

int number_of_elements(Elem *head_of_stack)
{
    int i;

    i = 0;
    if (!head_of_stack)
        return (0);
    while (head_of_stack)
    {
        head_of_stack = (head_of_stack)->next;
        i = i + 1;
    }
    return (i);
}

int atoi_simple(char *value)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (value[i])
    {
        result = result * 10 + value[i];
        i++;
    }
    return (result - 48);
}

void sa (Elem **head_of_stack_a)
{
    int value;

    value = (*head_of_stack_a)->value;
    (*head_of_stack_a)->value = (*head_of_stack_a)->next->value;
    (*head_of_stack_a)->next->value = value;
}

void sb (Elem **head_of_stack_b)
{
    int value;

    value = (*head_of_stack_b)->value;
    (*head_of_stack_b)->value = (*head_of_stack_b)->next->value;
    (*head_of_stack_b)->next->value = value;
}

void ss (Elem **head_of_stack_a, Elem **head_of_stack_b)
{
    sa(head_of_stack_a);
    sb(head_of_stack_b);
}

void  pa (Elem **head_of_stack_a, Elem **head_of_stack_b)
{
    int num;
    int value;

    num = number_of_elements(*head_of_stack_b);
    if (num == 0)
        return ;
    value = (*head_of_stack_b)->value;
    *head_of_stack_a = add_new_elem(value, head_of_stack_a);
    remove_elem(head_of_stack_b);
}

void  pb (Elem **head_of_stack_a, Elem **head_of_stack_b)
{
    int num;
    int value;

    num = number_of_elements(*head_of_stack_a);
    if (num == 0)
        return ;
    value = (*head_of_stack_a)->value;
    *head_of_stack_b = add_new_elem(value, head_of_stack_b);
    remove_elem(head_of_stack_a);
}

void ra (Elem **head_of_stack_a)
{
    Elem *current;
    Elem *head;

    if (!*head_of_stack_a)
        return ;
    head = *head_of_stack_a;
    current = *head_of_stack_a;
    while (current->next != NULL)
        current = current->next;
    *head_of_stack_a = (*head_of_stack_a)->next;
    current->next = head;
    head->next = NULL;
    return ;
}

void rb (Elem **head_of_stack_b)
{
    Elem *current;
    Elem *head;

    if (!*head_of_stack_b)
        return ;
    head = *head_of_stack_b;
    current = *head_of_stack_b;
    while (current->next != NULL)
        current = current->next;
    *head_of_stack_b = (*head_of_stack_b)->next;
    current->next = head;
    head->next = NULL;
    return ;
}

void rr(Elem **head_of_stack_a, Elem **head_of_stack_b)
{
    ra(head_of_stack_a);
    rb(head_of_stack_b);
}

void rra(Elem **head_of_stack_a)
{
    Elem *current;
    Elem *tmp;
    Elem *first;

    if (!*head_of_stack_a)
        return ;
    first = *head_of_stack_a;
    tmp = *head_of_stack_a;
    current = *head_of_stack_a;
    while (current->next != NULL)
    {
        tmp = current;
        current = current->next;
    }

    *head_of_stack_a = current;
    current->next = first;
    tmp->next = NULL;
    return ;
}

void rrb(Elem **head_of_stack_b)
{
    Elem *current;
    Elem *tmp;
    Elem *first;

    if (!*head_of_stack_b)
        return ;
    first = *head_of_stack_b;
    tmp = *head_of_stack_b;
    current = *head_of_stack_b;
    while (current->next != NULL)
    {
        tmp = current;
        current = current->next;
    }

    *head_of_stack_b = current;
    current->next = first;
    tmp->next = NULL;
    return ;
}

void print_all_check(Check ***list)
{
    int i;
    Check **list_1;

    i = 0;
    list_1 = *(list);
    while (*list_1[i])
    {
        printf("v:%d\n, i:%d\n", list[i]->value, list[i]->index);
        i++;
    }
}
void rrr(Elem **head_of_stack_a, Elem **head_of_stack_b)
{
    rra(head_of_stack_a);
    rrb(head_of_stack_b);
}

int main(int argc, char* argv[])              
{
    Elem *head_of_stack_a;
    Elem *head_of_stack_b;
    Check **list_of_elements;
    Check *new_check;

    int value;
    int i;

    i = argc - 1;
    head_of_stack_a = (Elem *)malloc(sizeof(Elem));
    head_of_stack_b = (Elem *)malloc(sizeof(Elem));
    list_of_elements = (Check **)malloc(sizeof(Check *) * (argc));

    head_of_stack_a = NULL;
    head_of_stack_b = NULL;
    list_of_elements = NULL;
    while (i > 0)
    {
        value = ft_atoi(argv[i]);
        head_of_stack_a = add_new_elem(value, &head_of_stack_a);
        new_check = (Check *)malloc(sizeof(Check));
        new_check->value = value;
        new_check->index = i;
        list_of_elements[i] = new_check;
        i--;
    }
    print_all_check(&list_of_elements);
    free_all_check(&list_of_elements);            
    free_all(&head_of_stack_a);
    free_all(&head_of_stack_b);
    return (0);                       
}   