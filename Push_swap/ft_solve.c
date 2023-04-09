/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:40:03 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/14 13:06:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_big_solve(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	i;
	int	k;
	int	c;

	k = -1;
	c = ft_binlen(*size_a);
	while (++k < c - 1)
	{
		i = *size_a;
		while (--i >= 0)
		{
			if ((tab_a[0] >> k) % 2 == 1)
				ft_rab(tab_a, *size_a, 0);
			else
				ft_pb(tab_a, size_a, tab_b, size_b);
		}
		while (*size_b > 0)
			ft_pa(tab_a, size_a, tab_b, size_b);
	}
}

void	ft_medium_solve(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	k;
	int	i;

	i = 0;
	while (i++ < (*size_a / 2))
	{
		k = 1;
		if (ft_min(tab_a, *size_a) >= *size_a / 2)
			k = 0;
		while (tab_a[0] > tab_a[ft_min(tab_a, *size_a)])
		{
			if (k)
				ft_rab(tab_a, *size_a, 0);
			else
				ft_rrab(tab_a, *size_a, 0);
		}
		ft_pb(tab_a, size_a, tab_b, size_b);
	}
	ft_small_solve(tab_a, size_a);
	if (tab_b[0] < tab_b[1])
		ft_sab(tab_b, *size_b);
	ft_pa(tab_a, size_a, tab_b, size_b);
	ft_pa(tab_a, size_a, tab_b, size_b);
}

void	ft_small_solve(int *tab_a, int *size_a)
{
	if (*size_a == 2 && tab_a[0] > tab_a[1])
		ft_sab(tab_a, 0);
	else if (tab_a[0] < tab_a[1] && tab_a[0] < tab_a[2] && tab_a[1] > tab_a[2])
	{
		ft_sab(tab_a, 0);
		ft_rab(tab_a, *size_a, 0);
	}
	else if (tab_a[0] > tab_a[1] && tab_a[0] < tab_a[2] && tab_a[1] < tab_a[2])
		ft_sab(tab_a, 0);
	else if (tab_a[0] < tab_a[1] && tab_a[0] > tab_a[2] && tab_a[1] > tab_a[2])
		ft_rrab(tab_a, *size_a, 0);
	else if (tab_a[0] > tab_a[1] && tab_a[0] > tab_a[2] && tab_a[1] < tab_a[2])
		ft_rab(tab_a, *size_a, 0);
	else if (tab_a[0] > tab_a[1] && tab_a[0] > tab_a[2] && tab_a[1] > tab_a[2])
	{
		ft_rab(tab_a, *size_a, 0);
		ft_sab(tab_a, 0);
	}
}

int	ft_solve(t_pile piles)
{
	int	*tab_a;
	int	*tab_b;
	int	*size_a;
	int	*size_b;

	tab_a = piles.pile_a;
	tab_b = piles.pile_b;
	size_a = &(piles.size_a);
	size_b = &(piles.size_b);
	if (*size_a <= 3)
		ft_small_solve(tab_a, size_a);
	else if (*size_a <= 5)
		ft_medium_solve(tab_a, size_a, tab_b, size_b);
	else
		ft_big_solve(tab_a, tab_b, size_a, size_b);
	return (1);
}

int	ft_binlen(int n)
{
	int	i;

	i = 0;
	while (++i && n)
		n /= 2;
	return (i);
}
