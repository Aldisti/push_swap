/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:23:40 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/14 13:30:22 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pile
{
	int	*pile_a;
	int	size_a;
	int	*pile_b;
	int	size_b;
}	t_pile;

/* ft_push_swap */
void	ft_push_swap(int argc, char **argv, int size);
int		ft_tfree(t_pile piles, int type);
/* ft_check */
int		ft_check(int argc, char **argv);
int		ft_chkdup(int *tab, int size);
int		ft_chkord(int *tab, int size);
int		ft_free(char **ptr);
/* ft_solve */
int		ft_solve(t_pile piles);
void	ft_small_solve(int *tab_a, int *size_a);
void	ft_medium_solve(int *tab_a, int *size_a, int *tab_b, int *size_b);
void	ft_big_solve(int *tab_a, int *tab_b, int *size_a, int *size_b);
int		ft_binlen(int n);
/* ft_tab_utils */
int		ft_max(int *tab, int size);
int		ft_min(int *tab, int size);
/* ft_getpile */
void	ft_getpile(int argc, char **argv, int *pile, int size);
int		*ft_tabdup(int *tab, int size);
void	ft_map(int *tab, int size);
void	ft_tabord(int *tab, int size);
/* ft_check */
int		ft_chkin(int argc, char **argv);
int		ft_chkdup(int *arr, int len);
int		ft_chkstr(char *str);
int		ft_chknbr(char *str);
int		ft_chkord(int *pile, int len);
/* ft_utils */
char	**ft_buffjoin(char **buff1, char **buff2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	ft_putstr(const char *str);
int		ft_buflen(char **buff);
/* ft_atoi */
int		ft_atoi(const char *str);
/* ft_split */
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strnbr(char const *str, char chr);
char	**ft_split(char const *s, char c);
char	**ft_fill(char const *s, char c);
void	*ft_calloc(size_t num, size_t dim);
/* ft_moves */
void	ft_pa(int *tab_a, int *size_a, int *tab_b, int *size_b);
void	ft_pb(int *tab_a, int *size_a, int *tab_b, int *size_b);
void	ft_sab(int *tab, int type);
void	ft_ss(int *tab_a, int *tab_b);
/* ft_rmoves */
void	ft_rab(int *tab, int size, int type);
void	ft_rr(int *tab_a, int size_a, int *tab_b, int size_b);
void	ft_rrab(int *tab, int size, int type);
void	ft_rrr(int *tab_a, int size_a, int *tab_b, int size_b);

#endif
