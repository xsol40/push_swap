/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:35:35 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/15 16:15:20 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack *a)
{
	int	i;

	i = a->nb;
	while (a)
	{
		if (i > a->nb)
			i = a->nb;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_stack *a)
{
	int	i;

	i = a->nb;
	while (a)
	{
		if (i < a->nb)
			i = a->nb;
		a = a->next;
	}
	return (i);
}

void	ft_sort_tree(t_stack **a)
{
	int	max;

	max = ft_max(*a);
	if (max == (*a)->nb)
		ft_ra(a, 0);
	else if (max == (*a)->next->nb)
		ft_rra(a, 0);
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a, 0);
}

void	push_min(t_stack **a, t_stack **b)
{
	int		min;
	t_stack	*last;

	last = ft_lstlast(*a);
	min = ft_min(*a);
	while ((*a)->nb != min)
	{
		if (last->nb == min)
			ft_rra(a, 0);
		else
			ft_ra(a, 0);
	}
	ft_pb(a, b, 0);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 4)
	{
		push_min(a, b);
		ft_sort_tree(a);
		ft_pa(a, b, 0);
	}
	if (ft_lstsize(*a) == 5)
	{
		push_min(a, b);
		push_min(a, b);
		ft_sort_tree(a);
		ft_pa(a, b, 0);
		ft_pa(a, b, 0);
	}
}
