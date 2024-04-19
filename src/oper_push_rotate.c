/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:18:02 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/15 21:35:24 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (i == 0)
		write (1, "pb\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (i == 0)
		write (1, "pa\n", 3);
}

void	ft_ra(t_stack **a, int i)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (i == 0)
		write (1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (i == 0)
		write (1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int i)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	if (i == 0)
		write (1, "rr\n", 3);
}
