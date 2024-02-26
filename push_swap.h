/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:27:25 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/02/25 13:11:36 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

//Handle errors
void	ft_error(void);
void	ft_free(t_stack **lst);
int		valid_nb(char *str);
int		ft_checkdup(t_stack *a);

//Stack initiation
void	ft_process(t_stack **a, int argc, char **argv);

//Nodes initiation

//Stack utils

//operation
void	ft_ss(t_stack **a, t_stack **b);
void	ft_sb(t_stack **b);
void	ft_sa(t_stack **a);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_rrb(t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);

//Algorithms

#endif
