/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:42:05 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/15 15:42:05 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

size_t	token_count(const char *s)
{
	size_t	tcount;
	int		found;

	tcount = 0;
	found = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			found = 0;
		else if (found == 0)
		{
			found = 1;
			tcount++;
		}
		s++;
	}
	return (tcount);
}
