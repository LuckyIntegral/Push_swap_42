/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:09:07 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:20:27 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	i;
	int	first;

	if (PRINT)
		ft_printf("rra\n");
	if (data->a.size <= 1)
		return ;
	i = 0;
	first = data->a.stack[0];
	while (i < data->a.size - 1)
	{
		data->a.stack[i] = data->a.stack[i + 1];
		i++;
	}
	data->a.stack[i] = first;
}

void	rrb(t_data *data)
{
	int	i;
	int	first;

	if (PRINT)
		ft_printf("rrb\n");
	if (data->b.size <= 1)
		return ;
	i = 0;
	first = data->b.stack[0];
	while (i < data->b.size - 1)
	{
		data->b.stack[i] = data->b.stack[i + 1];
		i++;
	}
	data->b.stack[i] = first;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
