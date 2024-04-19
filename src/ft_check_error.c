/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:08:13 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/04 18:13:19 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_signe(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	check_error(char *str)
{
	while (*str)
	{
		if (!ft_signe(*str) && !ft_digit(*str))
			return (0);
		if (ft_signe(*str))
		{
			str++;
			if (!ft_digit(*str))
				return (0);
		}
		else if (ft_digit(*str))
		{
			str++;
			if (*str == '\0')
				break ;
			if (!ft_digit(*str) && !ft_space(*str))
				return (0);
		}
		str++;
	}
	return (1);
}

int	ft_checkdup(t_stack *a)
{
	t_stack	*current;
	t_stack	*next;

	current = a;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->nb == next->nb)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}
