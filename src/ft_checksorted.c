/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:16:18 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 20:10:47 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksorted(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = a->nb;
	while (a)
	{
		if (i > a->nb)
			return (0);
		i = a->nb;
		a = a->next;
	}
	return (1);
}
