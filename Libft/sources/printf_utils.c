static int	fd_putchex(int fd, unsigned int hex)
{
}

static int	fd_putmem(int fd, unsigned long mem)
{
	if (mem >= 16)
	{
		if (fd_putmem(fd, mem / 16) == -1)
			return (-1);
		return (fd_putmem(fd, mem % 16));
	}
	else if (mem > 9)
		return (fd_putchar(fd, mem % 10 + 'a'));
	return (fd_putchar(fd, mem + '0'));
}

static int	fd_printmem(int fd, unsigned long mem)
{
	if (write(fd, "0x", 2) == -1)
		return (-1);
	if (fd_putmem(fd, mem) == -1)
		return (-1);
	return (ft_lunglen(hex));
}
