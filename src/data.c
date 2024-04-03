/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:49:52 by daortega          #+#    #+#             */
/*   Updated: 2024/04/03 17:41:52 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	print_data(t_data data)
{
	printf("n_philo: %d\n", data.n_philo);
	printf("t_death: %d\n", data.t_death);
	printf("t_eat: %d\n", data.t_eat);
	printf("t_sleep: %d\n", data.t_sleep);
	printf("n_eat: %d\n", data.n_eats);
}

t_data fill_data(int argc, char *argv[])
{
	t_data data;

	data.n_philo = atoi(argv[1]);
	data.t_death = atoi(argv[2]);
	data.t_eat = atoi(argv[3]);
	data.t_sleep = atoi(argv[4]);
	if (argc == 6)
		data.n_eats = atoi(argv[5]);
	else
		data.n_eats = -1;	
	return (data);
}
