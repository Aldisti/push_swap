/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:28:39 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/14 13:30:16 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_map(int *tab, int size)
{
	int	*ord;
	int	i;
	int	j;

	ord = ft_tabdup(tab, size);
	if (!ord)
		return ;
	ft_tabord(ord, size);
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size && tab[i] != ord[j])
				j++;
		tab[i] = j;
	}
	free(ord);
}

void	ft_getpile(int argc, char **argv, int *pile, int size)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (++k < argc)
	{
		tmp = ft_split(argv[k], 32);
		if (!tmp)
			return ;
		j = -1;
		while (tmp[++j])
			pile[i++] = ft_atoi(tmp[j]);
		ft_free(tmp);
	}
	ft_map(pile, size);
}

void	ft_tabord(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	if (!tab)
		return ;
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

int	*ft_tabdup(int *tab, int size)
{
	int	*new;
	int	i;

	new = (int *) malloc (size * sizeof(int));
	if (!new)
		return (0);
	i = -1;
	while (++i < size)
		new[i] = tab[i];
	return (new);
}
