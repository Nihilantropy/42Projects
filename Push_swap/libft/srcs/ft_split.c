/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:01:44 by crea              #+#    #+#             */
/*   Updated: 2024/03/18 22:36:01 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(const char *str, char c)
{
	int sep;
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		sep = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			if (!sep)
			{
				count++;
				sep = 1;
			}
			i++;
		}
	}
	return (count);
}

static char *alloc_word(const char *str, char c)
{
	int len;
	char *word;
	int i;

	len = 0;
	i = 0;
	while (str[len] != c && str[len])
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(const char *str, char c)
{
	if (!str)
		return (NULL);
	char **matrix;
	int words_nbr;
	int i;

	i = 0;
	words_nbr = count_words(str, c);
	matrix = (char **)malloc(sizeof(char *) * words_nbr + 1);
	if (!matrix)
		return (NULL);
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
			matrix[i] = alloc_word(str, c);
		i++;
		while (*str != c && *str != '\0')
			str++;
	}
	matrix[i] = NULL;
	return (matrix);
}
