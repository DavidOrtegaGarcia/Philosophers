/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:57:34 by daortega          #+#    #+#             */
/*   Updated: 2024/08/22 15:47:09 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	//t_philo	*philos;
	//pthread_mutex_t *forks;

	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), 0);
	/*if (check_args(argc, argv) == 0)
		return (printf("Wrong arguments\n"), 0);*/
	if (fill_data(argc, argv, &data) == 0)
		return (0);
	/*forks = malloc((data.n_philo) * sizeof(pthread_mutex_t));
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
		return (printf("Error creating threads\n"), 0);*/
	print_data(data);
	printf("Todo bien\n");
}
