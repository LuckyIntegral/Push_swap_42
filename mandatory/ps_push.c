/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:14:30 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:27:49 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	if (PRINT)
		ft_printf("pa\n");
	if (data->b.size == 0)
		return ;
	data->a.stack[data->a.size] = data->b.stack[data->b.size - 1];
	data->b.stack[data->b.size - 1] = 0;
	data->a.size++;
	data->b.size--;
}

void	pb(t_data *data)
{
	if (PRINT)
		ft_printf("pb\n");
	if (data->a.size == 0)
		return ;
	data->b.stack[data->b.size] = data->a.stack[data->a.size - 1];
	data->a.stack[data->a.size - 1] = 0;
	data->b.size++;
	data->a.size--;
}
