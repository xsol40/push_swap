/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:55 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/15 21:35:11 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int i)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = tmp->next->next;
	(*a)->next = tmp;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int i)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = tmp->next->next;
	(*b)->next = tmp;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	ft_sa(a, 1);
	ft_sb(b, 1);
	if (i == 0)
		write (1, "ss\n", 3);
}
