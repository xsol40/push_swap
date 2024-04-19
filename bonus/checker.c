/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:04:45 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 21:04:43 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_check_operation(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		ft_sa (a, 1);
	else if (!ft_strncmp(line, "sb\n", 3))
		ft_sb (b, 1);
	else if (!ft_strncmp(line, "ss\n", 3))
		ft_ss (a, b, 1);
	else if (!ft_strncmp(line, "pa\n", 3))
		ft_pa (a, b, 1);
	else if (!ft_strncmp(line, "pb\n", 3))
		ft_pb (a, b, 1);
	else if (!ft_strncmp(line, "ra\n", 3))
		ft_ra (a, 1);
	else if (!ft_strncmp(line, "rb\n", 3))
		ft_rb (b, 1);
	else if (!ft_strncmp(line, "rr\n", 3))
		ft_rr (a, b, 1);
	else if (!ft_strncmp(line, "rra\n", 4))
		ft_rra (a, 1);
	else if (!ft_strncmp(line, "rrb\n", 4))
		ft_rrb (b, 1);
	else if (!ft_strncmp(line, "rrr\n", 4))
		ft_rrr (a, b, 1);
	else
		ft_free_error(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	ft_process(&a, argc, argv);
	if (!a || ft_checkdup(a))
		ft_free_error(&a);
	size = ft_lstsize(a);
	line = get_next_line(0);
	while (line)
	{
		ft_check_operation(&a, &b, line);
		free (line);
		line = get_next_line(0);
	}
	if (!checksorted(a) || size != ft_lstsize(a))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	ft_free_stack(&a, &b);
}
