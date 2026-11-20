/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:58:57 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/20 16:47:33 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isflag(char *s)
{
	return (s[0] == '-' && s[1] == '-');
}

static int	apply_flag(char *s, t_ps *ps)
{
	if (ft_strcmp(s, "--bench") == 0)
		return (ps->bench = 1, 0);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (ps->adaptive = 1, 0);
	if (ft_strcmp(s, "--simple") == 0)
		ps->mode = MODE_SIMPLE;
	else if (ft_strcmp(s, "--medium") == 0)
		ps->mode = MODE_MEDIUM;
	else if (ft_strcmp(s, "--complex") == 0)
		ps->mode = MODE_COMPLEX;
	else
		return (-1);
	return (0);
}

int	parse_flags(int ac, char **av, t_ps *ps)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_isflag(av[i]))
		{
			if (apply_flag(av[i], ps) < 0)
				return (-1);
		}
		i++;
	}
	if (ps->mode == MODE_NONE)
		ps->mode = MODE_ADAPTIVE;
	return (i);
}

static int	ft_isstring(char *s)
{
	int	check;

	check = -1;
	while (*s)
	{
		if (ft_isspace(*s))
			check = 1;
		s++;
	}
	return (check);
}

int	parse_string(int ac, char **av, t_ps *ps)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_isstring(av[i]))
			return (i);
		i++;
	}
	return (-1);
}
