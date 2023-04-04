/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:28:05 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/05 11:08:36 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**ft_buffjoin(char **buff1, char **buff2)
{
	char	**new;
	int		i;
	int		j;

	i = ft_buflen(buff1) + ft_buflen(buff2);
	new = (char **) malloc ((i + 1) * sizeof(char *));
	if (!new)
		return (0);
	i = 0;
	while (buff1[i])
	{
		new[i] = buff1[i];
		free(buff1[i++]);
	}
	free(buff1);
	j = 0;
	while (buff2[j])
	{
		new[i++] = buff2[j];
		free(buff2[j++]);
	}
	free(buff2);
	new[i] = 0;
	return (new);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	ptr = malloc ((ft_strlen(s1) + 1) * sizeof (char));
	if (!ptr)
		return (0);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	ptr[i] = s1[i];
	return (ptr);
}

void	ft_putstr(const char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

int	ft_buflen(char **buff)
{
	int	i;

	i = 0;
	while (buff[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
