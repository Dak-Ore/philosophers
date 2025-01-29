/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:57:17 by rsebasti          #+#    #+#             */
/*   Updated: 2025/01/29 14:00:10 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philos	philos;

	if (argc < 5 || argc > 6)
		return (putstr_fd(2, "Invalid number of argument\n"),
			putstr_fd(2, "Usage: ./philo <number> <time_to_die <time_to_eat>"),
			putstr_fd(2, " <time_to_sleep> [eat_x_time]\n"), 0);
	philos.nb_philo = ft_atoi_secure(argv[1]);
	philos.time_die = ft_atoi_secure(argv[2]);
	philos.time_eat = ft_atoi_secure(argv[3]);
	philos.time_sleep = ft_atoi_secure(argv[4]);
	if (philos.nb_philo == -1 || philos.time_die == -1
		|| philos.time_sleep == -1 || philos.time_sleep == -1)
		return (putstr_fd(2, "Invalid argument\n"), 0);
	if (argc == 6)
	{
		philos.nb_eat = ft_atoi_secure(argv[5]);
		if (philos.nb_eat == -1)
			return (putstr_fd(2, "Invalid argument\n"), 0);
	}
	else
		philos.nb_eat = -1;
	return (1);
}
