/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:27:25 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 20:24:41 by mel-hiak         ###   ########.fr       */
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
}		t_stack;

//Handle errors_free functions
void	ft_free_error(t_stack **lst);
void	ft_error(void);
void	ft_free(t_stack **lst);
void	ft_free_stack(t_stack **a, t_stack **b);

//Parsing function
void	ft_process(t_stack **a, int argc, char **argv);
int		ft_checkdup(t_stack *a);
void	ft_sub_process(t_stack **a, char *argv);
int		check_error(char *str);
int		checksorted(t_stack *a);

//Stack utils
char	**ft_split(char *s, char c);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int nb);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);

//operation
void	ft_ss(t_stack **a, t_stack **b, int i);
void	ft_sb(t_stack **b, int i);
void	ft_sa(t_stack **a, int i);
void	ft_pb(t_stack **a, t_stack **b, int i);
void	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_rrr(t_stack **a, t_stack **b, int i);
void	ft_rrb(t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rr(t_stack **a, t_stack **b, int i);
void	ft_ra(t_stack **a, int i);
void	ft_rb(t_stack **b, int i);

//Algorithms
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);
void	push_min(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b, int size);
void	ft_push_b(t_stack **a, t_stack **b, int *tab, int size);
int		ft_range(t_stack *a);
void	ft_sort_tree(t_stack **a);

#endif
