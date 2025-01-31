/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:33:37 by rsebasti          #+#    #+#             */
/*   Updated: 2025/01/31 12:32:51 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				nb;
	long			last_eat;
	int				nb_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	eat_status;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				is_end;
	pthread_t		end_check;
	t_philo			**philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	end;
	pthread_mutex_t	print;
}	t_table;

void	*endgame(void *arg);
void	putstr_fd(int fd, char *str);
int		ft_atoi_secure(const char *nptr);
long	ft_get_time(void);
void	*routine(void *arg);
int		ft_printph(t_philo *philo, char *msg);

#endif