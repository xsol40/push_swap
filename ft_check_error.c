/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:08:13 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/02/25 13:11:18 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		ft_signe(char c)
// {
// 	if (c == '-')
// 		return 
// }

// int check_error(char **argv, int i, int j)
// {
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			if (signe(argv[i][j]))
// 			{
// 				j++;
// 				if (!ft_digit(argv[i][j])
// 						return (0);
// 			}
// 			else if (ft_digit(argv[i][j]))
// 			{
// 				j++;
// 				if (argv[i][j] == '\0')
// 					break ;
// 				if (!ft_digit(argv[i][j]) && !ft_space(argv[i][j]))
// 					return (0);
// 			}
// 			j++;
// 		}
// 	}
// }

int	valid_nb(char *str)
{
	if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	return (0);
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
