/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:42:16 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/14 13:02:01 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_tfree(t_pile piles, int type)
{
	if (piles.pile_b)
		free(piles.pile_b);
	if (piles.pile_a)
		free(piles.pile_a);
	if (!type)
		ft_putstr("Error\n");
	exit(0);
}

void	ft_push_swap(int argc, char **argv, int size)
{
	t_pile	piles;

	piles.pile_a = (int *) malloc (size * sizeof(int));
	if (!(piles.pile_a))
		ft_tfree(piles, 0);
	ft_getpile(argc, argv, piles.pile_a, size);
	piles.pile_b = (int *) malloc (size * sizeof(int));
	if (!(piles.pile_b))
		ft_tfree(piles, 0);
	piles.size_a = size;
	piles.size_b = 0;
	if (!ft_chkdup(piles.pile_a, piles.size_a))
		ft_tfree(piles, 0);
	if (ft_chkord(piles.pile_a, piles.size_a))
		ft_tfree(piles, 1);
	ft_solve(piles);
	ft_tfree(piles, 1);
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc <= 1)
		exit(write(1, "\n", 1));
	len = ft_check(argc, argv);
	if (len <= 1)
	{
		if (!len)
			ft_putstr("Error\n");
		exit(1);
	}
	ft_push_swap(argc, argv, len);
	return (0);
}
