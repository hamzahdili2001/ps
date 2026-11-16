/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 10:10:04 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/15 10:32:35 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init(t_ps *ps)
{
	ps->a.data = NULL;
	ps->a.head = 0;
	ps->a.cap = 0;
	ps->a.size = 0;
	ps->b.data = NULL;
	ps->b.head = 0;
	ps->b.cap = 0;
	ps->b.size = 0;
	ps->bench = 0;
	ps->mode = MODE_NONE;
}
