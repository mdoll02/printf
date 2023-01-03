/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:34:17 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/03 13:42:42 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret;
	char *str = "STRONG to test";
	void *test_void = "zoeiezge";

	printf("--------------\n");
	ft_printf("test with %%s\n");
	ft_printf("%s\n", str);
	printf("--------------\n");

	ft_printf("test with %%c\n");
	ft_printf("%c\n", str[3]);
	printf("--------------\n");

	ft_printf("test with no function call\n");
	ft_printf("No function is called here \t\n\n\t :)\n");
	printf("--------------\n");

	ft_printf("test with all function calls\n");
	ft_printf("%i\n%s\n%c\n%x\n%X\n%u\n%i\n", 92847, "test test", 'c', 32323, -1313, 324234, 234234);
	printf("--------------\n");

	ft_printf("test with %%d\n");
	ft_printf("%d\n", 9823742);
	printf("--------------\n");

	ft_printf("test with %%i\n");
	ft_printf("%i\n", 2489239);
	printf("--------------\n");

	ft_printf("test with %%X\n");
	ft_printf("%X\n", -9218788);
	printf("--------------\n");

	ft_printf("control for %%X\n");
	printf("%X\n", -9284324);
	printf("--------------\n");

	ft_printf("test with %%x\n");
	ft_printf("%x\n", -9218788);
	printf("--------------\n");

	ft_printf("control for%%x\n");
	printf("%x\n", -9284324);
	printf("--------------\n");

	ft_printf("test with %%p\n");
	ret = ft_printf("%p\n", test_void);
	ft_printf("%d\n", ret);
	printf("--------------\n");

	ft_printf("control for %%p\n");
	ret = printf("%p\n", test_void);
	ft_printf("%d\n", ret);
	printf("--------------\n\n\n");

	ft_printf("test with all function calls\n");
	ft_printf("%i\n%s\n%c\n%x\n%X\n%u\n%i\n%p\n", 92847, "test test", 'c', 32323, -1313, 324234, 234234, "37383");
	printf("--------------\n");
	return (0);
}
