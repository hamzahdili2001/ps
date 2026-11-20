/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 11:45:02 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/20 11:45:02 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *s)
{
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < s->size)
	{
		i = i + 1;
		while (j < s->size)
		{
			total_pairs += 1;
			if (stack_get(s, i) > stack_get(s, i))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
