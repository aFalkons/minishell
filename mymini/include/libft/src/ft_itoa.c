/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:40:10 by matteo            #+#    #+#             */
/*   Updated: 2023/12/01 22:25:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_number_len(long int n, int base)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static long int	ft_get_absolute_number(long int n)
{
	if (n == 0)
		return (n);
	if (n < 0)
		n = n * -1;
	return (n);
}

static void	ft_convert_to_char(char *s, long int absolute_n, int len, int base)
{
	while (absolute_n > 0)
	{
		s[len - 1] = 48 + (absolute_n % base);
		len--;
		absolute_n = absolute_n / base;
	}
}

char	*ft_itoa(int n)
{
	long long int	len;
	long long int	absolute_n;
	long long int	n_temp;
	int				base;
	char			*charized_n;

	base = 10;
	n_temp = n;
	absolute_n = ft_get_absolute_number(n_temp);
	len = ft_number_len(n_temp, base);
	charized_n = (char *) malloc((len + 1) * sizeof(char));
	if (!charized_n)
		return (NULL);
	if (n_temp == 0)
		charized_n[0] = '0';
	if (n_temp < 0)
		charized_n[0] = '-';
	ft_convert_to_char(charized_n, absolute_n, len, base);
	charized_n[len] = '\0';
	return (charized_n);
}
