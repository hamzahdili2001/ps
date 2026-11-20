/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 11:45:02 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/20 15:14:37 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	compute_disorder(t_ps *ps)
{
	double	mistakes;
	double	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	if (ps->a.size < 2)
		return (0.0);
	while (i < ps->a.size)
	{
		j = i + 1;
		while (j < ps->a.size)
		{
			total_pairs += 1;
			if (stack_get(&ps->a, i) > stack_get(&ps->a, j))
				mistakes += 1;
			j++;
		}
		i++;
	}
	ps->inversion = total_pairs;
	return (mistakes / total_pairs);
}

void			print_bench(t_ps *ps);
int	mode_adaptive(t_ps *ps)
{
	ps->disorder = compute_disorder(ps);
	if (ps->disorder < 0.2)
	{
		sort_simple(ps);
		print_bench(ps);
	}
	else if (ps->disorder < 0.5)
	{
		if (sort_medium(ps) < 0)
			return (-1);
		print_bench(ps);
	}
	else
	{
		if (sort_complex(ps) < 0)
			return (-1);
		print_bench(ps);
	}
	return (0);
}
