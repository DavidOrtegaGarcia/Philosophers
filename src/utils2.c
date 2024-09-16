/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:07:53 by daortega          #+#    #+#             */
/*   Updated: 2024/09/16 18:45:40 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	ft_sleep(t_data *data, int time)
{
	long long	time_sleep;

	time_sleep = get_time() + time;
	while (!get_death(data) && get_time() < time_sleep)
		usleep(100);
}

void	writer(char *msg, t_philo *philo)
{
	long long	time;

	if (!get_death(philo->data))
	{
		time = get_time() - get_t_start(philo->data);
		printf(msg, time, philo->id);
	}
}
