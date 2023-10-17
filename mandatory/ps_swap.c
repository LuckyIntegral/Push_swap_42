/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:24:43 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:20:46 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	temp;

	if (PRINT)
		ft_printf("sa\n");
	if (data->a.size <= 1)
		return ;
	temp = data->a.stack[data->a.size - 1];
	data->a.stack[data->a.size - 1] = data->a.stack[data->a.size - 2];
	data->a.stack[data->a.size - 2] = temp;
}

void	sb(t_data *data)
{
	int	temp;

	if (PRINT)
		ft_printf("sb\n");
	if (data->b.size <= 1)
		return ;
	temp = data->b.stack[data->b.size - 1];
	data->b.stack[data->b.size - 1] = data->b.stack[data->b.size - 2];
	data->b.stack[data->b.size - 2] = temp;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
