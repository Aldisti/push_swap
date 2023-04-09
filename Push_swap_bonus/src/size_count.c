/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:48:33 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/03 10:51:52 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_check_num(t_stack *stack, char	**numbers)
{
	int	i;

	i = -1;
	while (numbers[++i])
	{
		if (!ft_chknbr(numbers[i])
			|| (ft_atoi(numbers[i]) == 0 && numbers[i][0] != '0'))
			exit(write(2, "Error\nInvalid input\n", 20));
		stack->stack_a[i] = ft_atoi(numbers[i]);
	}
}

void	ft_size_count(int argc, char **argv, t_stack *stack)
{
	char	**numbers;
	char	*temp;
	int		i;

	i = 0;
	temp = (char *) malloc (sizeof(char));
	temp[0] = 0;
	while (++i < argc)
	{
		temp = ft_strjoin(temp, argv[i]);
		temp = ft_strjoin(temp, " ");
	}
	numbers = ft_split(temp, 32);
	free(temp);
	i = 0;
	while (numbers[i])
		i++;
	stack->size_a = i;
	stack->size_l = i;
	stack->stack_a = (int *) malloc (i * sizeof(int));
	ft_check_num(stack, numbers);
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

int	ft_chknbr(char *str)
{
	char	*nbr;
	int		i;

	nbr = "2147483647";
	if (str[0] == 45)
		nbr = "2147483648";
	if (str[0] == 45 || str[0] == 43)
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	else if (ft_strlen(str) < 10)
		return (1);
	i = -1;
	while (str[++i])
	{
		if (str[i] > nbr[i])
			return (0);
		else if (str[i] < nbr[i])
			return (1);
	}
	return (1);
}

int	ft_free(t_stack *stack)
{
	if (stack->num)
		free(stack->num);
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	return (0);
}
