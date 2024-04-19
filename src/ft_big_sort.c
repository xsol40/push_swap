/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:35:00 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 20:23:49 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

int	*copy_arr(t_stack *a)
{
	int		*tab;
	t_stack	*current;
	int		i;

	i = 0;
	tab = malloc(sizeof(int) * ft_lstsize(a));
	if (tab == 0)
		return (0);
	current = a;
	while (current)
	{
		tab[i] = current->nb;
		current = current->next;
		i++;
	}
	return (tab);
}

int	get_position(t_stack **b)
{
	t_stack	*current;
	int		i;
	int		max;
	int		temp;

	max = ft_max(*b);
	current = *b;
	i = 0;
	temp = 0;
	while (current)
	{
		if (current->nb == max)
			temp = i;
		i++;
		current = current->next;
	}
	return (temp);
}

void	push_max(t_stack **a, t_stack **b)
{
	int	max;
	int	temp;

	temp = get_position(b);
	max = ft_max(*b);
	if (temp <= ft_lstsize(*b) / 2)
		while ((*b)->nb != max)
			ft_rb(b, 0);
	else
		while ((*b)->nb != max)
			ft_rrb(b, 0);
	ft_pa(a, b, 0);
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	int	*tab;

	tab = sort_int_tab(copy_arr(*a), ft_lstsize(*a));
	ft_push_b(a, b, tab, size);
	free(tab);
	while (*b)
		push_max(a, b);
}
