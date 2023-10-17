/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:29:09 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/13 13:44:23 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bottom(t_stack stack)
{
	return (stack.stack[0]);
}

int	ft_top(t_stack stack)
{
	return (stack.stack[stack.size - 1]);
}

int	ft_is_level(int element, int chunk_size, int level)
{
	return (element / chunk_size == level);
}

void	ft_init_data(t_data *data)
{
	data->size = 0;
	data->chunk_size = 0;
	data->chunk_number = 0;
	data->a.size = 0;
	data->a.stack = NULL;
	data->b.size = 0;
	data->b.stack = NULL;
}

int	ft_is_ascending(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size - 1)
	{
		if (stack.stack[i] > stack.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
