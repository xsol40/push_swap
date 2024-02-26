/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:25:25 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/02/25 18:39:20 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return 1;
	a = NULL;
	ft_process(&a, argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	t_stack *curr = a;
	while (curr)
	{
		printf("%d\n", curr->nb);
		curr = curr->next;
	}
	
//	if (!checksorted(a))
//		ft_sort(&a);
//	ft_free(&a);
	return (0);
}
