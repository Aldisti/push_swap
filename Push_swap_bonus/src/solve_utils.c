/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:14:59 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/03 10:52:08 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_get_index(int *arrnum, int size, int n)
{
	int	i;

	i = 0;
	while (i < size && arrnum[i] != n)
		i++;
	return (i);
}

int	ft_min_of_max(int *arr, int size, int n)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = -1;
	while (++i < size)
		if (arr[i] > n && (tmp == -1 || arr[i] < tmp))
			tmp = arr[i];
	if (tmp < n)
		ft_min_max(arr, size, &tmp, &i);
	return (tmp);
}

int	ft_mosse(t_stack *stack, int n, int count)
{
	int	i;

	if (count > stack->size_b / 2)
		count = stack->size_b - count;
	i = ft_min_of_max(stack->stack_a, stack->size_a, n);
	i = ft_get_index(stack->stack_a, stack->size_a, i);
	if (i > (stack->size_a / 2 + stack->size_a % 2))
		i = stack->size_a - i;
	return (count + i);
}

void	ft_solve_three(t_stack *stack)
{
	int	index;

	ft_min_max(stack->stack_a, stack->size_a, &stack->min, &stack->max);
	index = ft_get_index(stack->stack_a, stack->size_a, stack->max);
	if (index == 0)
		ra(stack, 1);
	else if (index == 1)
		rra(stack, 1);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack, 1);
}

void	ft_solve_five(t_stack *stack)
{
	while (stack->size_a > 3)
	{
		ft_min_max(stack->stack_a, stack->size_a, &stack->min, &stack->max);
		while (stack->stack_a[0] == 4 || stack->stack_a[0] == 5)
			pb(stack, 1);
		ra(stack, 1);
	}
	ft_solve_three(stack);
	if (!stack->size_b)
		return ;
	pa(stack, 1);
	if (stack->stack_b[0] != stack->size_l)
	{
		pa(stack, 1);
		ra(stack, 1);
		ra(stack, 1);
		return ;
	}
	ra(stack, 1);
	pa(stack, 1);
	ra(stack, 1);
}
