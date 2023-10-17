/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcode_cases.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:50:29 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:22:41 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_data *data)
{
	if (data->a.stack[2] < data->a.stack[0]
		&& data->a.stack[0] < data->a.stack[1])
		(sa(data), ra(data));
	else if (data->a.stack[1] < data->a.stack[2]
		&& data->a.stack[2] < data->a.stack[0])
		sa(data);
	else if (data->a.stack[0] < data->a.stack[2]
		&& data->a.stack[2] < data->a.stack[1])
		rra(data);
	else if (data->a.stack[1] < data->a.stack[0]
		&& data->a.stack[0] < data->a.stack[2])
		ra(data);
	else if (data->a.stack[0] < data->a.stack[1]
		&& data->a.stack[1] < data->a.stack[2])
		(sa(data), rra(data));
}

static void	reverse(t_data *data)
{
	int	temp;
	int	i;

	if (data->size == 1)
		return ;
	else if (data->size == 2)
		sa(data);
	i = 0;
	while (i < data->a.size / 2)
	{
		temp = data->a.stack[i];
		data->a.stack[i] = data->a.stack[data->a.size - 1 - i];
		data->a.stack[data->a.size - 1 - i] = temp;
		i++;
	}
}

static void	ft_sort_four(t_data *data)
{
	int	min;
	int	i;

	min = ~(1 << 31);
	i = 0;
	while (i < data->a.size)
	{
		if (min > data->a.stack[i])
			min = data->a.stack[i];
		i++;
	}
	if (ft_top(data->a) == min)
		(pb(data), ft_sort_three(data), pa(data));
	else if (ft_bottom(data->a) == min)
		(rra(data), pb(data), ft_sort_three(data), pa(data));
	else if (data->a.stack[1] == min)
		(ra(data), ra(data), pb(data), ft_sort_three(data), pa(data));
	else
		(ra(data), pb(data), ft_sort_three(data), pa(data));
}

static void	ft_sort_five(t_data *data)
{
	static int	min = ~(1 << 31);
	static int	min2 = ~(1 << 31);
	static int	i = -1;

	while (++i < data->a.size)
		if (min > data->a.stack[i])
			min = data->a.stack[i];
	i = -1;
	while (++i < data->a.size)
		if (min2 > data->a.stack[i] && data->a.stack[i] != min)
			min2 = data->a.stack[i];
	if (ft_top(data->a) == min || ft_top(data->a) == min2)
		(pb(data), ft_sort_four(data), pa(data));
	else if (ft_bottom(data->a) == min || ft_bottom(data->a) == min2)
		(rra(data), pb(data), ft_sort_four(data), pa(data));
	else if (data->a.stack[3] == min || data->a.stack[3] == min2)
		(ra(data), pb(data), ft_sort_four(data), pa(data));
	else if (data->a.stack[1] == min || data->a.stack[1] == min2)
		(ra(data), ra(data), pb(data), ft_sort_four(data), pa(data));
	else if (data->a.stack[2] == min || data->a.stack[2] == min2)
		(rra(data), rra(data), pb(data), ft_sort_four(data), pa(data));
	if (ft_top(data->a) != min)
		sa(data);
}

void	ft_hardcode_sort(t_data *data, int mode)
{
	if (mode)
		reverse(data);
	if (data->a.size == 3)
		ft_sort_three(data);
	else if (data->a.size == 4)
		ft_sort_four(data);
	else if (data->a.size == 5)
		ft_sort_five(data);
}
