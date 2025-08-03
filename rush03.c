/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:33:09 by tchumbas          #+#    #+#             */
/*   Updated: 2025/08/03 17:19:43 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	corner_direction(int x, int ox, int s)
{
	if ((x - ox) == 0 && s == 1)
		return ('/');
	else if (x == 1 && s == 1)
		return ('\\');
	else if (x == 1 && s == 0)
	{
		if (ox == 1)
			return ('\\');
		return ('/');
	}
	else if ((x - ox) == 0 && s == 0)
		return ('\\');
	return ('x');
}

void	first_line(int x, int s)
{
	int		startx;
	char	corner;

	startx = x;
	while (x > 0)
	{
		if ((x - startx) == 0 || (x == 1))
		{
			corner = corner_direction(x, startx, s);
			ft_putchar(corner);
			x--;
		}
		else if (x > 1)
		{
			ft_putchar('B');
			x--;
		}
	}
	ft_putchar('\n');
}

void	last_line(int x, int s)
{
	int		startx;
	char	corner;

	startx = x;
	while (x > 0)
	{
		if ((x - startx) == 0 || (x == 1))
		{
			corner = corner_direction(x, startx, s);
			ft_putchar(corner);
			x--;
		}
		else if (x > 1)
		{
			ft_putchar('B');
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
		ft_putchar('B');
		ft_putchar('\n');
	}
	else if (y > 0)
	{
		ft_putchar('B');
		while (gap > 0)
		{
			ft_putchar(' ');
			gap--;
		}
		ft_putchar('B');
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
	first_line(x, 1);
	while ((y - 2) > 0)
	{
		gap_line(x, y);
		y--;
	}
	if (y > 1)
	{
		last_line(x, 0);
	}
	ft_putchar('\n');
}
