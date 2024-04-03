/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:57:34 by daortega          #+#    #+#             */
/*   Updated: 2024/04/03 17:42:47 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

static int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9' || i >= 9)
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
	t_data data;

	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), 0);
	if (check_args(argc, argv) == 0)
		return (printf("Wrong arguments\n"), 0);
	data = fill_data(argc, argv);
	print_data(data);
	printf("Todo bien\n");
}
