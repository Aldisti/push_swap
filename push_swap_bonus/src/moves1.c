/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:14 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/02 19:10:39 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	sa(t_stack *stack, int print)
{
	int	tmp;

	if (!stack->size_a)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int print)
{
	int	tmp;

	if (!stack->size_b)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int print)
{
	sa(stack, 0);
	sb(stack, 0);
	if (print)
		write(1, "ss\n", 3);
}
