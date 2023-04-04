/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:15:18 by adi-stef          #+#    #+#             */
/*   Updated: 2023/04/03 11:03:57 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	logic;

	count = 0;
	logic = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' )
	{
		logic = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10;
		count = count + (str[i] - 48);
		i++;
	}
	if (str[i] != 0)
		return (0);
	return (count * logic);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str1;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	str1 = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str1)
		return (0);
	i = -1;
	while (s1[++i])
		str1[i] = s1[i];
	j = 0;
	while (s2[j])
		str1[i++] = s2[j++];
	str1[i] = '\0';
	free(s1);
	return (str1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
