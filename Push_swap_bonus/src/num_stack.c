/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 08:56:17 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/02 16:49:36 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_arr_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	j = -1;
	while (++j < stack->size_a - 1)
	{
		i = -1;
		while (++i < stack->size_a - 1)
		{
			if (stack->num[i] > stack->num[i + 1])
			{
				tmp = stack->num[i];
				stack->num[i] = stack->num[i + 1];
				stack->num[i + 1] = tmp;
			}
		}
	}
}

void	ft_empty_stack_a(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	stack->num = (int *) malloc(stack->size_a * sizeof(int));
	while (++i < stack->size_a)
		stack->num[i] = stack->stack_a[i];
	ft_arr_sort(stack);
	j = 0;
	while (j < stack->size_a)
	{
		i = 0;
		while (i < stack->size_a && stack->stack_a[j] != stack->num[i])
			i++;
		stack->stack_a[j++] = i + 1;
	}
}
