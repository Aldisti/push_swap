/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:45:52 by aldisti           #+#    #+#             */
/*   Updated: 2023/04/03 11:05:06 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_lis(t_stack *stack)
{
	int	*lis;
	int	i;
	int	j;

	lis = (int *) malloc (stack->size_l * sizeof(int));
	i = -1;
	while (++i < stack->size_l)
		lis[i] = 0;
	i = -1;
	stack->lis = -1;
	while (++i < stack->size_a)
	{
		j = -1;
		while (++j < i)
			if (i && stack->stack_a[i] > stack->stack_a[j] && lis[i] <= lis[j])
				lis[i]++;
		if (stack->lis == -1 || stack->lis < lis[i])
			stack->lis = lis[i];
	}
	j = stack->lis++;
	stack->num[j] = stack->stack_a[ft_get_index(lis, stack->size_l, j)];
	ft_get_lis(stack, lis, j);
}

void	ft_get_lis(t_stack *stack, int *lis, int j)
{
	int	i;
	int	k;
	int	tmp;

	k = ft_get_index(lis, stack->size_l, j + 1);
	while (--j >= 0)
	{
		i = 0;
		tmp = stack->num[j + 1];
		while (i < k)
		{
			if (lis[i] == j && stack->stack_a[i] < tmp)
			{
				stack->num[j] = stack->stack_a[i];
				k = i;
				break ;
			}
			i++;
		}
	}
	i = stack->lis;
	while (i < stack->size_l)
		stack->num[i++] = 0;
	free(lis);
}

int	ft_check_lis(t_stack *stack, int n)
{
	int	i;

	i = -1;
	while (++i < stack->lis)
		if (stack->num[i] == n)
			return (1);
	return (0);
}
