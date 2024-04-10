/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:55:49 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/01 10:10:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	send_sig(char **argv, int bit, int i);
void	send_char(char **argv);
void	sig_confirm(int sig);
void	bin_to_char(char *bin, siginfo_t *info);
void	print_banner(void);
void	sigaction_handler(int signum, siginfo_t *info, void *context);

#endif
