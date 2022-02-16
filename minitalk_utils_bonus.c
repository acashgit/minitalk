/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:12:52 by acash             #+#    #+#             */
/*   Updated: 2021/11/16 17:12:54 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		arr[i] = c;
		i++;
	}
	return (b);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putchar('0' + n % 10);
	}
	else
		ft_putchar('0' + n);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	long	digit;

	i = 0;
	sign = 1;
	digit = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = (digit * 10) + (str[i] - '0');
		if (digit > 2147483648 && sign == -1)
			return (0);
		if (digit > 2147483647 && sign == 1)
			return (-1);
		i++;
	}
	return (digit * sign);
}
