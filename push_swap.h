/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:48:58 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 10:04:39 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// DEBUGGING
# include <stdio.h>
// ENDDEBUGGNIG
typedef enum e_flags
{
	MODE_NONE,
	MODE_SIMPLE,
	MODE_ADAPTIVE,
	MODE_MEDIUM,
	MODE_COMPLEX,
}			t_flags;

typedef struct s_stack
{
	int		*data;
	int		head;
	size_t	size;
	size_t	cap;
}			t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		mode;
	int		bench;
}			t_ps;
// init
void		ps_init(t_ps *ps);
// output
void		ft_putchar_fd(int c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);

// utils
int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(int c);
int			ft_issign(int c);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
char		*ft_substr(char *str, unsigned int start, size_t len);
int			*ft_split(char *str, size_t *count_out);
// utils extra
size_t		token_count(const char *s);
// parsing
int			parse_flags(int ac, char **av, t_ps *ps);
int			parse_string(int ac, char **av, t_ps *ps);
int			ft_atoi(const char *s, int *out);
int			parse_args(int ac, char **av, t_ps *ps);
// stack
void		stack_push(t_stack *s, int v);
int			stack_get(t_stack *s, int index);
int			stack_allocate(t_stack *s, size_t cap);
#endif
