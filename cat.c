#include <libc.h>
#include <errno.h>
#define BUF_SIZE 1000

void	ft_putstr(char *str);
void	ft_puter(char *av);

int	ft_display_file(char *av)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		car;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	car = read(fd, buf, BUF_SIZE);
	if (car == -1)
		return (0);
	while (car)
	{
		write(1, buf, car);
		car = read(fd, buf, BUF_SIZE);
	}
	close(fd);
	return (1);
}

int	ft_display_stdin(void)
{
	char	in[BUF_SIZE];
	int		car;

	car = read(STDOUT_FILENO, in, BUF_SIZE);
	if (car == -1)
		return (0);
	while (car)
	{
		write(STDIN_FILENO, in, car);
		car = read(STDOUT_FILENO, in, BUF_SIZE);
	}
	return (1);
}

void	ft_wdisplay(char *av)
{
	if (av[0] == '-' && av[1] == '\0')
	{
		if (!ft_display_stdin())
			ft_putstr(strerror(errno));
	}
	else
	{
		if (!ft_display_file(av))
			ft_puter(av);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		if (!ft_display_stdin())
		{
			ft_puter(strerror(errno));
			return (0);
		}
	}
	else
	{
		while (i < ac)
		{
			ft_wdisplay(av[i]);
			i++;
		}
	}
	return (0);
}
