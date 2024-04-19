/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:20:21 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 20:10:39 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_error(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	write (1, "Error\n", 5);
	exit(1);
}

void	ft_error(void)
{
	write (1, "Error\n", 5);
	exit(1);
}

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

void	ft_free_stack(t_stack **a, t_stack **b)
{
	t_stack	*current;

	while (*a)
	{
		current = (*a)->next;
		free(*a);
		*a = current;
	}
	if (*b)
	{
		while (*b)
		{
			current = (*b)->next;
			free(*b);
			*b = current;
		}
	}
}
