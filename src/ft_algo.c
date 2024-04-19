/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:58:30 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/20 02:34:04 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_range(t_stack *a)
{
	int	n;

	n = ft_lstsize(a);
	if (n >= 6 && n <= 16)
		return (3);
	else if (n <= 100)
		return (13);
	else if (n <= 500)
		return (30);
	else
		return (45);
}

static int	check_reverse(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		size;

	tmp = *a;
	i = 1;
	size = ft_lstsize(*a);
	while (tmp && i != size)
	{
		if (tmp->nb > tmp->next->nb)
			i++;
		tmp = tmp->next;
		if (!tmp->next)
			break ;
	}
	if (i == size)
		return (1);
	return (0);
}

static void	is_reversed(t_stack **a)
{
	if (check_reverse(a) == 1)
		ft_rra(a, 0);
	else
		ft_ra(a, 0);
}

void	ft_push_b(t_stack **a, t_stack **b, int *tab, int size)
{
	int	i;
	int	range;

	i = 0;
	range = ft_range(*a);
	while (*a)
	{
		if (range + i >= size)
			range = size - 1 - i;
		else if ((*a)->nb > tab[i] && (*a)->nb <= tab[range + i])
		{
			ft_pb (a, b, 0);
			if (ft_lstsize(*b) >= 2 && (*b)->nb < (*b)->next->nb)
				ft_sb(b, 0);
			i++;
		}
		else if ((*a)->nb <= tab[i])
		{
			ft_pb (a, b, 0);
			ft_rb (b, 0);
			i++;
		}
		else
			is_reversed(a);
	}
}
