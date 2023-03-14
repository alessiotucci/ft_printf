/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:44:55 by atucci            #+#    #+#             */
/*   Updated: 2023/03/14 13:35:49 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "incl/ft_printf.h"

// global variable (?)
flags g_bonus;

void init_tdata(flags *data)
{
	data->ret = 0;
	data->width = 0;
	// debuggin
	//printf("init  width: %d\n", data->width);

	data->precision = -1;
	//The precision field is initialized to -1 because it's used to indicate that no precision was specified
	data->is_zero = 0;
	data->is_minus = 0;
	data->is_dot = 0;
}
static int placeholder(va_list *arg, char q, int count)
{
// inside this function I should do all the check for the place holder 
// %c
// %s 
// %p and so on
 
	//printf("this is the width B4 conversion:%d\n", g_bonus.width);	
    
	//Perform the appropriate conversion 	
			if (q == 'c')
				count += pt_putchar(va_arg(*arg, int));
			else if (q == 's')
				count += pt_putstr(va_arg(*arg, char*));
			else if (q == 'd' || q == 'i')
				count += ft_putnbr(va_arg(*arg, int));
			else if (q == 'p')
				count += ft_pointer(va_arg(*arg, unsigned long));
			else if (q == '%')
				count += pt_putchar('%');
			// add more conversion here
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args; //check the syntax


    init_tdata(&g_bonus);
// check the values
//	printf("g_bonus.ret = %d\n", g_bonus.ret);
//  printf("g_bonus.width = %d\n", g_bonus.width);
//    printf("g_bonus.precision = %d\n", g_bonus.precision);
//    printf("g_bonus.is_zero = %d\n", g_bonus.is_zero);
//    printf("g_bonus.is_minus = %d\n", g_bonus.is_minus);
//    printf("g_bonus.is_dot = %d\n", g_bonus.is_dot);
//


	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i]) //checking the format string for placeholders
	{
		if (format[i] == '%') // once I find the placeholder
		{
		// I found the placeholder!!
		// printf("I found the placeholder at the index [%d]\n", i);	
		
		// check for the flag
		// i should be updated since its the index (?)
		// i = width_flag(format, i + 1, &g_bonus);
		check_flags(format, i + 1);	
		
		// check if the values has been updated
//	printf("g_bonus.ret	UPDATED= %d\n", g_bonus.ret);
//    printf("g_bonus.width UPDATED= %d\n", g_bonus.width);
//    printf("g_bonus.precision UPDATED= %d\n", g_bonus.precision);
//    printf("g_bonus.is_zero UPDATED= %d\n", g_bonus.is_zero);
//    printf("g_bonus.is_minus UPDATED= %d\n", g_bonus.is_minus);
//    printf("g_bonus.is_dot UPDATED= %d\n", g_bonus.is_dot);
		
		
		
		
		// converting 
		count = placeholder(&args,((char *) format) [i + 1], count); // typecasting!

			i++;
		}
		else 
		{
		// There is no placeholder so I just print what I have :(
			pt_putchar(format[i]);
			count++;
		}
	i++;
	}
	va_end(args); //check the syntax
	return (count);
}
