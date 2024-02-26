/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:51:13 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/02/25 18:38:09 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstnew(int nb)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == 0)
		return (0);
	ptr -> nb = nb;
	ptr -> next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL && new == NULL)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

static int	count_words(char const *s, char del)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != del && (!s[i + 1] || s[i + 1] == del))
			count++;
		i++;
	}
	return (count);
}

static int	get_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_result(char **result, int i)
{
	while (i >= 0)
		free(result[i--]);
	free(result);
}

static char	**fill_array(char const *s, char c, char **result, int words_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < words_count)
	{
		while (*s && *s == c)
			s++;
		result[i] = malloc(get_word_len(s, c) + 1);
		if (!result[i] && (free_result(result, i - 1), 1))
			return (NULL);
		j = 0;
		while (*s && *s != c)
			result[i][j++] = *s++;
		result[i++][j] = '\0';
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result = malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	result = fill_array(s, c, result, words_count);
	return (result);
}

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	number;
	int	signe;

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
		str++;
	}
	if ((number * signe) > 2147483647 || (number * signe) < -2147483648)
		ft_error();
	return (number * signe);
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
		if (valid_nb(tmp[i]))
			ft_error();
		j = ft_atoi(tmp[i]);
		ft_lstadd_back(a, ft_lstnew(j));
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
