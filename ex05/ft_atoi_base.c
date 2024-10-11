/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:07:43 by jegoh             #+#    #+#             */
/*   Updated: 2023/08/14 22:24:23 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	find_index(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	value;

	if (!is_valid_base(base))
		return (0);
	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	value = find_index(*str, base);
	while (*str)
	{
		result = result * ft_strlen(base) + value;
		str++;
		value = find_index(*str, base);
	}
	return (result * sign);
}
//
#include <unistd.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d", ft_atoi_base(argv[1], argv[2]));
	}
	else
		write (1, "git gud", 7);
	return (0);
}
//
