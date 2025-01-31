/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:57:17 by rsebasti          #+#    #+#             */
/*   Updated: 2025/01/31 12:41:25 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_table *table, int nb)
{
	t_philo	*philo;
	int		s_table;

	philo = malloc(sizeof(t_philo));
	philo->nb = nb + 1;
	philo->nb_eat = 0;
	philo->last_eat = ft_get_time();
	philo->table = table;
	s_table = philo->table->nb_philo;
	philo->left_fork = &philo->table->fork[nb];
	if (s_table == 1)
		philo->right_fork = NULL;
	else
		philo->right_fork = &philo->table->fork[(nb + 1) % s_table];
	pthread_mutex_init(&philo->eat_status, NULL);
	pthread_create(&philo->thread, NULL, routine, philo);
	return (philo);
}

void	init_table(t_table *table)
{
	int	i;

	table->philos = malloc(table->nb_philo * sizeof(t_philo));
	table->fork = malloc(table->nb_philo * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < table->nb_philo)
		pthread_mutex_init(&table->fork[i], NULL);
	i = -1;
	while (++i < table->nb_philo)
		table->philos[i] = init_philo(table, i);
	pthread_create(&table->end_check, NULL, endgame, table);
}

int	init_var(t_table *table, int argc, char **argv)
{
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->end, NULL);
	table->nb_philo = ft_atoi_secure(argv[1]);
	table->time_die = ft_atoi_secure(argv[2]);
	table->time_eat = ft_atoi_secure(argv[3]);
	table->time_sleep = ft_atoi_secure(argv[4]);
	table->is_end = 0;
	if (argc == 6)
		table->nb_eat = ft_atoi_secure(argv[5]);
	else
		table->nb_eat = -2;
	if (table->nb_philo <= 0 || table->time_die == -1
		|| table->time_sleep == -1 || table->time_sleep == -1
		|| table->nb_philo >= 250 || table->nb_eat == -1)
		return (putstr_fd(2, "Invalid argument\n"), 0);
	init_table(table);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (putstr_fd(2, "Invalid number of argument\n"),
			putstr_fd(2, "Usage: ./philo <number> <time_to_die <time_to_eat>"),
			putstr_fd(2, " <time_to_sleep> [eat_x_time]\n"), 0);
	init_var(&table, argc, argv);
	while (1)
		;
	return (1);
}
