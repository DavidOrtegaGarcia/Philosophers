/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:49:52 by daortega          #+#    #+#             */
/*   Updated: 2024/09/12 16:44:49 by daortega         ###   ########.fr       */
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

int	fill_data(int argc, char *argv[], t_data *data)
{
	if (!ft_test_atoi(argv[1]) || !ft_test_atoi(argv[2])
		|| !ft_test_atoi(argv[3]) || !ft_test_atoi(argv[4]))
		return (printf("Wrong arguments\n"), 0);
	data->n_philo = ft_atoi(argv[1]);
	if (data->n_philo > 100)
		return (printf("Too many philosophers\n"), 0);
	data->t_death = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!ft_test_atoi(argv[5]))
			return (printf("Wrong arguments\n"), 0);
		data->n_eats = ft_atoi(argv[5]);
	}
	else
		data->n_eats = -1;
	data->death = false;
	if (pthread_mutex_init(&data->getter, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->ts_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (0);
	if (check_val_arg(*data) == 0)
		return (printf("The values must be greater than 0\n"), 0);
	return (1);
}
