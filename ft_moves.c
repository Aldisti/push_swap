/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:31:29 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/14 13:27:27 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_pb(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	i;

	if ((!(*size_a) && !(*size_b)) || !(*size_a))
		return ;
	if (*size_b)
	{
		i = *size_b + 1;
		while (--i > 0)
			tab_b[i] = tab_b[i - 1];
	}
	tab_b[0] = tab_a[0];
	i = -1;
	while (++i < *size_a)
		tab_a[i] = tab_a[i + 1];
	ft_putstr("pb\n");
	(*size_a)--;
	(*size_b)++;
}

void	ft_pa(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	i;

	if ((!(*size_a) && !(*size_b)) || !(*size_b))
		return ;
	if (*size_a)
	{
		i = *size_a + 1;
		while (--i > 0)
			tab_a[i] = tab_a[i - 1];
	}
	tab_a[0] = tab_b[0];
	i = -1;
	while (++i <= *size_b)
		tab_b[i] = tab_b[i + 1];
	ft_putstr("pa\n");
	(*size_a)++;
	(*size_b)--;
}

void	ft_ss(int *tab_a, int *tab_b)
{
	ft_sab(tab_a, -1);
	ft_sab(tab_b, -1);
	ft_putstr("ss\n");
}

void	ft_sab(int *tab, int type)
{
	int	tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	if (type == 0)
		ft_putstr("sa\n");
	else if (type == 1)
		ft_putstr("sb\n");
}
