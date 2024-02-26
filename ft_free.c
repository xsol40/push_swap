/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:20:21 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/02/25 11:44:19 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nb = 0;
		free(*lst);
		*lst = tmp;
	}
}

// int main()
// {
// 	t_stack *node1 = malloc(sizeof(t_stack));
// 	t_stack *node2 = malloc(sizeof(t_stack));
// 	t_stack *node3 = malloc(sizeof(t_stack));
// 	t_stack *node4 = malloc(sizeof(t_stack));
// 	t_stack *node5 = malloc(sizeof(t_stack));
// 	t_stack *node6 = malloc(sizeof(t_stack));
// 	node1->nb = 30;
// 	node2->nb = 90;
// 	node3->nb = 50;
// 	node4->nb = 70;
// 	node5->nb = 90;
// 	node6->nb = 5;
// 	node1->next = node2;
// 	node2->next= node3;
// 	node3->next = node4;
// 	node4->next = node5;
// 	node5->next = node6;
// 	node6->next = NULL;
// 	t_stack	*current = node1;
// 	while (current)
// 	{
// 		printf("%d\n", current->nb);
// 		current = current->next;
// 	}
// 	printf("***********************************\n");
// 	ft_free(&node1);
// 	current = node1;
// 	while (current)
// 	{
// 		printf("%d\n", current->nb);
// 		current = current->next;
// 	}
// }
