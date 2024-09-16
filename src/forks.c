/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:58:02 by daortega          #+#    #+#             */
/*   Updated: 2024/09/16 18:50:38 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	free_forks(pthread_mutex_t *forks, t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

void	get_forks(t_philo *phil, int i)
{
	if (i == 0)
	{
		phil->lfork = &phil->data->forks[phil->data->n_philo - 1];
		phil->rfork = &phil->data->forks[0];
	}
	else
	{
		phil->lfork = &phil->data->forks[i - 1];
		phil->rfork = &phil->data->forks[i];
	}
}

pthread_mutex_t	*fill_forks(pthread_mutex_t *forks, int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}
