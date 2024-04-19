/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:25:25 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 21:05:29 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	ft_process(&a, argc, argv);
	if (!a || ft_checkdup(a))
		ft_free_error(&a);
	if (!checksorted(a))
	{
		if (ft_lstsize(a) == 2)
			ft_sa(&a, 0);
		else if (ft_lstsize(a) == 3)
			ft_sort_tree(&a);
		else if (ft_lstsize(a) <= 5)
			ft_sort_five(&a, &b);
		else
			ft_sort(&a, &b, ft_lstsize(a));
	}
	ft_free_stack(&a, &b);
}
