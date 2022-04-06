/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:04:19 by namina            #+#    #+#             */
/*   Updated: 2021/12/16 18:55:41 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	getlen(int num)
{
	int			len;
	long int	n;

	n = (long int) num;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		len = 1;
	else
	{
		while (n > 0)
		{
			len++;
			n /= 10;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	num;

	num = (long int ) n;
	len = getlen(n);
	str = malloc(len + 1);
	if (!str)
		return (0);
	if (num < 0)
	{
		*str = '-';
		num = -num;
	}
	str[len--] = '\0';
	if (num == 0)
		*str = '0';
	while (num > 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
