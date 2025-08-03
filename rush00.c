/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:26:55 by tchumbas          #+#    #+#             */
/*   Updated: 2025/08/03 17:13:52 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	edge_line(int x)
{
	int	startx;

	startx = x;
	while (x > 0)
	{
		if ((x - startx) == 0 || (x == 1))
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
	int	gap;

	gap = x - 2;
	if (gap < 0)
	{
		ft_putchar('|');
		ft_putchar('\n');
	}
	else if (y > 0)
	{
		ft_putchar('|');
		while (gap > 0)
		{
			ft_putchar(' ');
			gap--;
		}
		ft_putchar('|');
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	char	*msg;

	msg = "ERROR: negative value provided\n";
	if (y <= 0 || x <= 0)
	{
		write(2, msg, 32);
		return ;
	}
	edge_line(x);
	while ((y - 2) > 0)
	{
		gap_line(x, y);
		y--;
	}
	if (y > 1)
		edge_line(x);
	ft_putchar('\n');
}
