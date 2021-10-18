#include <stdlib.h>
#include "libft.h"

int	words_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*new_str(char const *s, char c)
{
	int		start;
	int		j;

	start = 0;
	j = 0;
	while (s[start + j] != c && s[start + j] != '\0')
	{
		j++;
	}
	return (ft_substr(s, start, j));
}

char	**leak_protect(char **arr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**splitting(char **arr, char const *s, char c, int words)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			arr[j] = new_str(&s[i], c);
			if (!arr)
				return (leak_protect(arr, words));
			while (s[i + 1] != c && s[i + 1] != '\0')
				i++;
		}
		j++;
		i++;
	}
	arr[j] = (void *)0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	words = words_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	splitting(arr, s, c, words);
	arr = splitting(arr, s, c, words);
	if (arr == NULL)
		return (leak_protect(arr, words));
	return (arr);
}
