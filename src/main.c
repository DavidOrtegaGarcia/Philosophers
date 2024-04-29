/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:57:34 by daortega          #+#    #+#             */
/*   Updated: 2024/04/29 15:03:04 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

static int	check_val_arg(t_data data)
{
	if (data.n_philo <= 0 || data.t_death <= 0 || data.t_eat <= 0
		|| data.t_sleep <= 0 || data.n_eats == 0)
		return (0);
	return (1);
}

static int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9' || i >= 5)
			return (0);
		i++;
	}
	return (1);
}

static int	check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_arg(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philos;
	pthread_mutex_t *forks;

	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), 0);
	if (check_args(argc, argv) == 0)
		return (printf("Wrong arguments\n"), 0);
	data = fill_data(argc, argv);
	if (check_val_arg(data) == 0)
		return (printf("The values must be greater than 0\n"), 0);
	forks = malloc((data.n_philo) * sizeof(pthread_mutex_t));
	if (forks == NULL)
		return (printf("Error allocating memory\n"), free_forks(forks, data), 0);
	data.forks = forks;
	philos = malloc((data.n_philo) * sizeof(t_philo));
	if (philos == NULL)
		return (printf("Error allocating memory\n"), free_philos(philos), free_forks(forks, data), 0);
	data.philos = philos;
	philos = fill_philos(philos, &data);
	philos = create_philos(philos);
	if (philos == NULL)
		return (printf("Error creating threads\n"), 0);
	print_data(data);
	printf("Todo bien\n");
}
