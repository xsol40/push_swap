#include <stdio.h>
#include <stdlib.h>
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

int main()
{
	char str[] = "4   ";
	char **res = ft_split(str, ' ');
	int i = 0;
	while (res[i])
		printf("%s\n",res[i++]);
}