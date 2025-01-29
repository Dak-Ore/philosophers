/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:57:17 by rsebasti          #+#    #+#             */
/*   Updated: 2025/01/29 20:55:08 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *table, int argc, char **argv)
{
	int	i;

	table->philos = malloc(table->nb_philo * sizeof(t_philo));
	table->fork = malloc(table->nb_philo * sizeof(pthread_mutex_t));
	if (!table->philos || !table->fork)
		return (0);
	table->nb_philo = ft_atoi_secure(argv[1]);
	table->time_die = ft_atoi_secure(argv[2]);
	table->time_eat = ft_atoi_secure(argv[3]);
	table->time_sleep = ft_atoi_secure(argv[4]);
	if (argc == 6)
		table->nb_eat = ft_atoi_secure(argv[5]);
	else
		table->nb_eat = -2;
	if (table->nb_philo <= 0 || table->time_die == -1
		|| table->time_sleep == -1 || table->time_sleep == -1
		|| table->nb_philo >= 250 || table->nb_eat == -1)
		return (putstr_fd(2, "Invalid argument\n"), 0);
	i = -1;
	while (++i < table->nb_philo)
		pthread_mutex_init(&table->fork[i], NULL);
	i = -1;
	while (++i < table->nb_philo)
		init_philo(table, &table->philos[i], i);
	return (1);
}

void	init_philo(t_table *table, t_philo *philo, int nb)
{
	philo->nb = nb + 1;
	philo->nb_eat = 0;
	philo->last_eat = ft_get_time();
	philo->left_fork = &table->fork[nb];
	if (table->nb_philo == 1)
		philo->right_fork = NULL;
	else if (nb != table->nb_philo - 1)
		philo->right_fork = &table->fork[nb + 1];
	else
		philo->right_fork = &table->fork[0];
	pthread_create(&(philo->thread), NULL, &routine, philo);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (putstr_fd(2, "Invalid number of argument\n"),
			putstr_fd(2, "Usage: ./philo <number> <time_to_die <time_to_eat>"),
			putstr_fd(2, " <time_to_sleep> [eat_x_time]\n"), 0);
	if (!init_table(&table, argc, argv))
		return (0);
	return (1);
}
