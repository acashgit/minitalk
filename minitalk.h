/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:56:54 by acash             #+#    #+#             */
/*   Updated: 2021/11/16 16:57:00 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnbr(int n);
int			ft_atoi(char *str);
void		server_close(int sig);

#endif