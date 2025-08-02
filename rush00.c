/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:26:55 by tchumbas          #+#    #+#             */
/*   Updated: 2025/08/02 16:14:13 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar();

void	edge_line(int x)
{
	int startX = x;

	while (x > 0) {
		if ((x - startX) == 0 || (x == 1))
		{
			ft_putchar('o');
			x--;
		} 
		else if (x > 1)
		{
			ft_putchar('-');
			x--;
		}
	}
	ft_putchar('\n');
}

void	gap_line(int x, int y)
{
	int gap = x - 2;

	if (gap <= 0) {
		ft_putchar('|');
		ft_putchar('\n');
	} 
	else if (y > 0) 
	{
		ft_putchar('|');
		while(gap > 0) {
			ft_putchar(' ');
			gap--;
		}
		ft_putchar('|');
		ft_putchar('\n');
	}
}


void	rush(int x, int y)
{
	if (y <= 0 || x <= 0)
	{
		return;
	}
	edge_line(x);
	while ((y - 2) > 0)
	{
		gap_line(x, y);
		y--;
	}
	if (y > 1) {
		edge_line(x);
	}
	
	
	ft_putchar('\n');	
}

/* 

void	gap_line(int x, int y)
{
	
} */