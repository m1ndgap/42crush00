/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:33:09 by tchumbas          #+#    #+#             */
/*   Updated: 2025/08/03 15:12:47 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:26:55 by tchumbas          #+#    #+#             */
/*   Updated: 2025/08/02 16:23:33 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar();

char corner_direction(int x, int ox, int y)
{
	if ((x - ox) == 0 || y > 1) 
	{
		return '/';
	}
	else if ( x == 1 ) 
	{
		return '\\'; 
	}
	else if ((x - ox) == 0)
	{
		return 'X';
	}
	return 'Y';
}

void	edge_line(int x, int y)
{
	int startX = x;

	while (x > 0) {
		if ((x - startX) == 0 || (x == 1))
		{
			char corner = corner_direction(x, startX, y);
			ft_putchar(corner);
			x--;
		} 
		else if (x > 1)
		{
			ft_putchar('*');
			x--;
		}
	}
	ft_putchar('\n');
}

void	gap_line(int x, int y)
{
	int gap = x - 2;

	if (gap < 0) {
		ft_putchar('*');
		ft_putchar('\n');
	} 
	else if (y > 0) 
	{
		ft_putchar('*');
		while(gap > 0) {
			ft_putchar(' ');
			gap--;
		}
		ft_putchar('*');
		ft_putchar('\n');
	}
}


void	rush(int x, int y)
{
	if (y <= 0 || x <= 0)
	{
		char msg[] = "ERROR: negative value provided\n";
    	write(2, msg, sizeof(msg) - 1);
		return;
	}
	edge_line(x, y);
	while ((y - 2) > 0)
	{
		gap_line(x, y);
		y--;
	}
	if (y > 1) {
		edge_line(x, y);
	}
		
	ft_putchar('\n');	
}
