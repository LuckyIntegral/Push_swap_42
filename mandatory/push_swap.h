/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:14:58 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:14:16 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes <unistd.h> for: read, write
// includes <stdlib.h> for: malloc, free, exit
// includes "ft_pirntf.h" for: ft_printf
# include "../libft/ft_printf.h"

// for stack a and b
typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

// instead of thousands variables:)
typedef struct s_data
{
	int		size;
	int		chunk_size;
	int		chunk_number;
	t_stack	a;
	t_stack	b;
}	t_data;

// print output
# define PRINT 1

// error status
# define MALLOC_FAIL "malloc fail"
# define INVALID_ARGS "invalid argument passed"

// number parser
void	ft_parse_arguments(t_data *data, int argc, char **argv);

// error handler
void	ft_error(t_data *data, char *status);

// utils
int		ft_is_level(int element, int chunk_size, int level);
int		ft_is_ascending(t_stack stack);
void	ft_init_data(t_data *data);
int		ft_bottom(t_stack stack);
int		ft_top(t_stack stack);

// algorythm:
// stage 1 - iterate stack, change numbers for indexies --- done
// stage 2 - shift all numbers to stack b --- test
// stage 3 - shift all numbers back to stack a
void	ft_iterate_stack(t_data *data);
void	ft_shift_chunks(t_data *data);
void	ft_shift_back(t_data *data);

// hardcode algorythm
void	ft_hardcode_sort(t_data *data, int mode);

// actions
typedef struct s_action
{
	int		shifts;
	void	(*action)(t_data *);
}	t_action;

void	pa(t_data *data);
void	pb(t_data *data);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif
