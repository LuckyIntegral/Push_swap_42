/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stage_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:28:29 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:23:33 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_bottom(t_data *data, int desired)
{
	int	i;

	i = 0;
	while (i < data->chunk_size && i < data->b.size)
	{
		if (data->b.stack[i] == desired)
			return (0);
		i++;
	}
	return (1);
}

static void	do_magic(t_data *data)
{
	int		desired;

	desired = ft_tr(data->a.size, ft_top(data->a), data->size) - 1;
	if (ft_top(data->b) == desired)
		pa(data);
	else if (ft_bottom(data->a) == desired && desired)
		rra(data);
	else if (data->a.size && (ft_bottom(data->a) == data->size - 1
			|| ft_bottom(data->a) < ft_top(data->b)))
		(pa(data), ra(data));
	else if (ft_is_bottom(data, desired))
		rb(data);
	else
		rrb(data);
}

void	ft_shift_back(t_data *data)
{
	while (data->b.size)
		do_magic(data);
	while (ft_bottom(data->a) != data->size - 1)
		rra(data);
}
