/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:25:57 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/17 16:00:34 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		(*a) = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*b || !((*b)->next))
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		(*b) = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write (1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int i)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	if (i == 0)
		write (1, "rrr\n", 4);
}
