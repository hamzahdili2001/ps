/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:27:40 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/15 15:27:40 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_allocate(t_stack *s, size_t cap)
{
	s->data = malloc(sizeof(int) * cap);
	if (!(s->data))
		return (-1);
	s->cap = cap;
	s->head = 0;
	s->size = 0;
	return (0);
}

int	stack_get(t_stack *s, int index)
{
	return (s->data[(s->head + index) % s->cap]);
}

void	stack_push(t_stack *s, int v)
{
	if (s->size >= s->cap)
		return ;
	s->head = (s->head - 1 + s->cap) % s->cap;
	s->data[s->head] = v;
	s->size++;
}
