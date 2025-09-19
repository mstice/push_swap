/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:46:53 by mtice             #+#    #+#             */
/*   Updated: 2024/12/13 14:31:45 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_string_counter(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static char	*ft_string_in_pointer(char const *s, char c, int i, int len)
{
	char	*p;
	int		j;

	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	j = 0;
	while (s[i - len] != c && len - 1 >= 0)
	{
		p[j] = s[i - len];
		len --;
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		len;
	char	**arr;

	i = 0;
	k = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_string_counter(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (s[i] != '\0' && k < ft_string_counter(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		arr[k] = ft_string_in_pointer(s, c, i, len);
		k++;
	}
	arr[k] = NULL;
	return (arr);
}
/*
int	main(void)
{
	char str[] = "Hello my name is";
	char del = ' ';
	char **result;
	int	j;

	result = ft_split(str, del);
	j = 0;
	while (j < ft_string_counter(str, del))
	{
		printf("%s\n", result[j]);
		j++;
	}
	free (result);
	return (0);
}*/