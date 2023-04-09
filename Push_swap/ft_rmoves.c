/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:35:20 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/14 13:27:54 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rrr(int *tab_a, int size_a, int *tab_b, int size_b)
{
	ft_rrab(tab_a, size_a, -1);
	ft_rrab(tab_b, size_b, -1);
	ft_putstr("rrr\n");
}

void	ft_rrab(int *tab, int size, int type)
{
	int	tmp;

	tmp = tab[size - 1];
	while (--size > 0)
		tab[size] = tab[size - 1];
	tab[size] = tmp;
	if (type == 0)
		ft_putstr("rra\n");
	else if (type == 1)
		ft_putstr("rrb\n");
}

void	ft_rr(int *tab_a, int size_a, int *tab_b, int size_b)
{
	ft_rab(tab_a, size_a, -1);
	ft_rab(tab_b, size_b, -1);
	ft_putstr("rr\n");
}

void	ft_rab(int *tab, int size, int type)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = tab[0];
	while (++i < size - 1)
		tab[i] = tab[i + 1];
	tab[i] = tmp;
	if (type == 0)
		ft_putstr("ra\n");
	else if (type == 1)
		ft_putstr("rb\n");
}
