/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:50:03 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:27:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_chunk_size(int stack_size)
{
	int	i;

	i = 1;
	while (i * i <= stack_size)
		i++;
	return (i * 7 / 3);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (1);
	ft_init_data(&data);
	ft_parse_arguments(&data, argc, argv);
	if (!ft_is_ascending(data.a))
	{
		if (data.a.size <= 5)
			ft_hardcode_sort(&data, 1);
		else
		{
			data.chunk_size = ft_count_chunk_size(data.size);
			data.chunk_number = data.size / data.chunk_size;
			data.chunk_number += ft_tr(data.size % data.chunk_size, 1, 0);
			ft_iterate_stack(&data);
			ft_shift_chunks(&data);
			ft_shift_back(&data);
		}
	}
	ft_free(data.a.stack);
	ft_free(data.b.stack);
	return (0);
}
