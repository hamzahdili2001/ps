/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:40:43 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/20 16:09:50 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_dispatch(t_ps *ps)
{
	ps->disorder = compute_disorder(ps);
	if (ps->mode == MODE_ADAPTIVE)
	{
		if (mode_adaptive(ps) < 0)
			return (-1);
	}
	if (ps->mode == MODE_SIMPLE)
		sort_simple(ps);
	if (ps->mode == MODE_MEDIUM)
	{
		if (sort_medium(ps) < 0)
			return (-1);
	}
	if (ps->mode == MODE_COMPLEX)
	{
		if (sort_complex(ps) < 0)
			return (-1);
	}
	if (ps->bench == 1)
		print_bench(ps);
	return (0);
}

int	main(int ac, char **av)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (-1);
	ps_init(ps);
	if (parse_args(ac, av, ps) < 0)
	{
		free_ps(ps);
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	if (is_sorted(ps) == 0)
		return (free_ps(ps), 0);
	if (sort_dispatch(ps) < 0)
		return (free_ps(ps), 0);
	return (free_ps(ps), 0);
}
