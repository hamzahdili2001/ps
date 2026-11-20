/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 11:45:02 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/20 16:17:30 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mode_adaptive(t_ps *ps)
{
	if (ps->disorder < 0.2)
	{
		sort_simple(ps);
	}
	else if (ps->disorder < 0.5)
	{
		if (sort_medium(ps) < 0)
			return (-1);
	}
	else
	{
		if (sort_complex(ps) < 0)
			return (-1);
	}
	return (0);
}
