/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:24:57 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/10 11:15:38 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_min(int *tab, int size)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < size)
	{
		if (tab[i] <= tab[n])
			n = i;
		i++;
	}
	return (n);
}

int	ft_max(int *tab, int size)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < size)
	{
		if (tab[i] >= tab[n])
			n = i;
		i++;
	}
	return (n);
}
