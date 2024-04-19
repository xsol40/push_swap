/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:51:13 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 20:22:40 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	long	number;
	int		signe;

	number = 0;
	signe = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		number = number * 10 + (*str - '0');
		if ((number * signe) > 2147483647 || (number * signe) < -2147483648)
			ft_error();
		str++;
	}
	return ((int)(number * signe));
}

void	ft_sub_process(t_stack **a, char *argv)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = ft_split(argv, 32);
	if (!tmp[i])
		ft_error();
	while (tmp[i])
	{
		if (!check_error(tmp[i]))
			ft_error();
		j = ft_atoi(tmp[i]);
		ft_lstadd_back(a, ft_lstnew(j));
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	ft_process(t_stack **a, int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc >= 2)
		while (i < argc)
			ft_sub_process(a, argv[i++]);
}
