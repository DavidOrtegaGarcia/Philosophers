/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:00:50 by daortega          #+#    #+#             */
/*   Updated: 2024/09/12 19:09:40 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

/*void	print_forks(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->n_philo)
	{
		printf("philo %d lfork = %p\n", philos[i].id, philos[i].lfork);
		printf("philo %d rfork = %p\n", philos[i].id, philos[i].rfork);
		printf("\n");
		i++;
	}
}*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && result == 0)
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if ((s1[i] != '\0' || s2[i] != '\0') && result == 0)
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (result > 0)
		result = 1;
	else if (result < 0)
		result = -1;
	return (result);
}

void	writer(char *msg, t_philo *philo)
{
	long long time;
	
	if (!get_death(philo->data))
	{
		
		time = get_time() - get_t_start(philo->data);
		printf(msg, time, philo->id);
	}
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	check_val_arg(t_data data)
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
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

bool	ft_test_atoi(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (check_arg(str) == 0)
		return (false);
	while (str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
		if (result > INT_MAX || result < INT_MIN)
			return (false);
	}
	return (true);
}
