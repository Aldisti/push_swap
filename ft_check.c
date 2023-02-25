/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:06:28 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/14 13:23:42 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* returns 0 if (num > MAX_INT || num < MIN_INT) else 0 */
int	ft_chknbr(char *str)
{
	char	*nbr;
	int		i;

	nbr = "2147483647";
	if (str[0] == 45 || str[0] == 43)
	{
		if (str[0] == 45)
			nbr = "2147483648";
		str++;
	}
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) < 10)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] > nbr[i])
			return (0);
		else if (str[i] < nbr[i])
			return (1);
		i++;
	}
	return (1);
}

/* returns 1 if it's sorted else 0*/
int	ft_chkord(int *tab, int size)
{
	int	*ord;
	int	i;

	ord = ft_tabdup(tab, size);
	ft_tabord(ord, size);
	i = 0;
	while (i < size && tab[i] == ord[i])
		i++;
	free(ord);
	if (i == size)
		return (1);
	return (0);
}

/* returns 0 if there's a dup number else 1 */
int	ft_chkdup(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] == tab[j])
				return (0);
		}
	}
	return (1);
}

/* returns 0 if the input is not ok else the len of the array */
int	ft_check(int argc, char **argv)
{
	char	**tmp;
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], 32);
		if (!tmp)
			return (0);
		j = -1;
		while (tmp[++j])
		{
			if (!ft_atoi(tmp[j]) && (tmp[j][0] != 48 && tmp[j][1] != 48))
				return (ft_free(tmp));
			else if (!ft_chknbr(tmp[j]))
				return (ft_free(tmp));
			else
				c++;
		}
		ft_free(tmp);
	}
	return (c);
}

int	ft_free(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	return (0);
}
