/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:20:12 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:20:37 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	int	last;
	int	i;

	if (PRINT)
		ft_printf("ra\n");
	if (data->a.size <= 1)
		return ;
	last = data->a.stack[data->a.size - 1];
	i = data->a.size - 1;
	while (i)
	{
		data->a.stack[i] = data->a.stack[i - 1];
		i--;
	}
	data->a.stack[i] = last;
}

void	rb(t_data *data)
{
	int	last;
	int	i;

	if (PRINT)
		ft_printf("rb\n");
	if (data->b.size <= 1)
		return ;
	last = data->b.stack[data->b.size - 1];
	i = data->b.size - 1;
	while (i)
	{
		data->b.stack[i] = data->b.stack[i - 1];
		i--;
	}
	data->b.stack[i] = last;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
