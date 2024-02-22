/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:19 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/22 17:11:00 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_word(char const *s, char sep);
static int	get_word_cnt(char const *s, char sep);
static int	is_sep(char c, char sep);

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*word;
	int		word_cnt;
	int		i;

	word_cnt = get_word_cnt(s, c);
	result = (char **)ft_calloc(sizeof(char *) * (word_cnt + 1));
	i = 0;
	while (i < word_cnt)
	{
		while (*s && (is_sep(*s, c)))
			s++;
		word = get_word(s, c);
		result[i] = word;
		s += ft_strlen(word);
		i++;
	}
	return (result);
}

void	ft_split_free(char **s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		free(s[idx]);
		idx++;
	}
	free(s);
}

static char	*get_word(char const *s, char sep)
{
	char	*word;
	size_t	len;
	size_t	i;

	i = 0;
	while (s[i] && (!is_sep(s[i], sep)))
		i++;
	len = i;
	word = (char *)ft_calloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static int	get_word_cnt(char const *s, char sep)
{
	int		cnt;
	size_t	i;
	int		flag;

	cnt = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if ((!is_sep(s[i], sep)) && flag)
		{
			cnt++;
			flag = 0;
		}
		else if ((is_sep(s[i], sep)) && !flag)
			flag = 1;
		i++;
	}
	return (cnt);
}

static int	is_sep(char c, char sep)
{
	if (ft_isspace(c) || c == sep)
		return (1);
	return (0);
}
