/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:49:13 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/03 11:00:55 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*num;
	int	size_l;
	int	size_a;
	int	size_b;
	int	lis;
	int	min;
	int	max;
}	t_stack;

//	swap
void	ft_do_this(t_stack *stack, void (*f)(t_stack *, int), int *n, int size);
void	ft_push_to_a1(t_stack *stack, int bi, int ai);
void	ft_push_to_a2(t_stack *stack, int ai, int bi);
void	ft_final_sort(t_stack *stack);
void	ft_sort_swap(t_stack *stack);
//	lis
void	ft_get_lis(t_stack *stack, int *lis, int j);
int		ft_check_lis(t_stack *stack, int n);
void	ft_lis(t_stack *stack);
//	solve_utils
int		ft_min_of_max(int *arr, int size, int n);
int		ft_get_index(int *arrnum, int size, int n);
int		ft_mosse(t_stack *stack, int n, int count);
void	ft_solve_three(t_stack *stack);
void	ft_solve_five(t_stack *stack);
//	num_stack
void	ft_empty_stack_a(t_stack *stack);
void	ft_arr_sort(t_stack *stack);
//	size_count
void	ft_size_count(int argc, char **argv, t_stack *stack);
void	ft_check_num(t_stack *stack, char	**numbers);
int		ft_free(t_stack *stack);
int		ft_chknbr(char *str);
//	moves1
void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ss(t_stack *stack, int print);
//	moves2
void	pa(t_stack *stack, int print);
void	pb(t_stack *stack, int print);
//	moves3
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rr(t_stack *stack, int print);
//	moves4
void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	rrr(t_stack *stack, int print);
//	utils1
void	ft_min_max(int *stack, int size, int *min, int *max);
void	ft_check_double(t_stack *stack);
int		ft_check_sort(t_stack *stack);
void	ft_empty_b(t_stack *stack);
void	ft_put_all(t_stack *stack);
//	utils2
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
//	split
void	ft_while(char **final, const char *s, char c);
char	**ft_split(char const *s, char c);
int		ft_word(const char *s, char c);
//	get_next_line
char	*get_next_line(int fd);
char	*ft_get_first_str(char *buff);
char	*ft_realloc(char *str, char *buff);
void	ft_memmove(char *dst, char *src);
int		ft_getnl(char *str);
int		ft_nlinstr(char *str);

#endif
