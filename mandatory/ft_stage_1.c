/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stage_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:27:28 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:20:07 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_duplicate_a_to_b(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		data->b.stack[i] = data->a.stack[i];
		i++;
	}
}

static void	ft_sort_iterators(t_data *data)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < data->size - 1)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->a.stack[i] > data->a.stack[j])
			{
				temp = data->a.stack[i];
				data->a.stack[i] = data->a.stack[j];
				data->a.stack[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	ft_swap_stacks(t_data *data, int *helper)
{
	t_stack	temp;
	int		i;

	temp = data->a;
	data->a = data->b;
	data->b = temp;
	data->a.size = data->size;
	data->b.size = 0;
	i = 0;
	while (i < data->size)
	{
		data->a.stack[data->size - 1 - i] = helper[i];
		i++;
	}
}

static void	ft_replicate_indexies(t_data *data, int *temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			if (data->a.stack[i] == data->b.stack[j])
			{
				temp[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_iterate_stack(t_data *data)
{
	int	*helper;

	helper = ft_calloc(data->size, 4);
	if (!helper)
		ft_error(data, MALLOC_FAIL);
	ft_duplicate_a_to_b(data);
	ft_sort_iterators(data);
	ft_replicate_indexies(data, helper);
	ft_swap_stacks(data, helper);
	ft_bzero(data->b.stack, sizeof (int) * data->size);
	ft_free(helper);
}
