/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stage_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:26:00 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:27:00 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_last_by_direction(t_data data, int level, int direction)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (i < data.a.size)
	{
		if (direction > 0)
		{
			if (ft_is_level(data.a.stack[data.a.size - 1 - i],
					data.chunk_size, level))
				result = i + 1;
		}
		else
		{
			if (ft_is_level(data.a.stack[(data.a.size - 1 + i) % data.a.size],
					data.chunk_size, level))
				result = i + 1;
		}
		i++;
	}
	return (result);
}

void	choose_direction(t_data data, int level, t_action *action)
{
	int	rra_res;
	int	ra_res;
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (i < data.a.size)
	{
		if (ft_is_level(data.a.stack[i], data.chunk_size, level))
			size++;
		i++;
	}
	ra_res = find_last_by_direction(data, level, 1);
	rra_res = find_last_by_direction(data, level, -1);
	if (ra_res < rra_res + size)
		action->action = &ra;
	else
		action->action = &rra;
	action->shifts = size;
}

void	do_magic(t_data *data, int level, t_action action)
{
	while (action.shifts && data->a.size - 3)
	{
		while (action.shifts && data->a.size
			&& ft_is_level(ft_top(data->a), data->chunk_size, level)
			&& ft_top(data->a) != data->size - 1
			&& ft_top(data->a) != data->size - 2
			&& ft_top(data->a) != data->size - 3)
		{
			if (ft_top(data->a) % data->chunk_size > data->chunk_size / 2)
				pb(data);
			else
			{
				pb(data);
				if (data->b.size > 2)
					rb(data);
			}
			action.shifts--;
		}
		if (data->a.size > 1 && action.shifts)
			action.action(data);
	}
}

void	ft_shift_chunks(t_data *data)
{
	t_action	action;
	int			level;

	level = 0;
	while (level < data->chunk_number)
	{
		choose_direction(*data, level, &action);
		do_magic(data, level, action);
		level ++;
	}
	ft_hardcode_sort(data, 0);
}
