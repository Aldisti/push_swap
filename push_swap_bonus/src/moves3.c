/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:33 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/02 16:47:26 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ra(t_stack *stack, int print)
{
	int	i;
	int	temp;

	if (!stack->size_a)
		return ;
	i = -1;
	temp = stack->stack_a[0];
	while (++i < stack->size_a - 1)
		stack->stack_a[i] = stack->stack_a[i + 1];
	stack->stack_a[i] = temp;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int print)
{
	int	i;
	int	temp;

	if (!stack->size_b)
		return ;
	i = -1;
	temp = stack->stack_b[0];
	while (++i < stack->size_b - 1)
		stack->stack_b[i] = stack->stack_b[i + 1];
	stack->stack_b[i] = temp;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int print)
{
	ra(stack, 0);
	rb(stack, 0);
	if (print)
		write(1, "rr\n", 3);
}
