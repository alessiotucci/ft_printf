/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:31:36 by atucci            #+#    #+#             */
/*   Updated: 2023/03/14 16:51:24 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"
#include "../libft/libft.h"


int check_flags(const char *str, int i)
{
	char placeholder[] = "cspdiuxX%";
	int j = 0;
	while (str[i] == placeholder [j] && j < 10)
	{
		if (str[i] == placeholder[j])
			return (i);
		j++;
	}
	// Check if first char after % is 0
    if (str[i] == '0')
    {
        g_bonus.is_zero = 1;
        i++;
    	return (i);
	}

    // Check for padding flag
    if (str[i] >= '1' && str[i] <= '9')
    {
        g_bonus.width = ft_atoi(str + i);
		return (i);
		while (str[i] >= '0' && str[i] <= '9')
            i++;
    }

    // Check for precision flag
    if (str[i] == '.')
    {
        g_bonus.is_dot = 1;
        i++;
        if (str[i] >= '0' && str[i] <= '9')
        {
            g_bonus.precision = ft_atoi(str + i);
            while (str[i] >= '0' && str[i] <= '9')
                i++;
        }
        else
            g_bonus.precision = 0;
	}

    // Check for + or - flags
    if (str[i] == '+')
    {
        g_bonus.is_minus = 0;
        i++;
	}
    else if (str[i] == '-')
    {
        g_bonus.is_minus = 1;
        i++;
	}

    // Check for space flag
    if (str[i] == ' ')
    {
        if (!g_bonus.is_minus)
            g_bonus.is_minus = 2;
        i++;
	}
return (i);
}

