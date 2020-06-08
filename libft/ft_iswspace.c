int	ft_iswspace(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (c);
	return (0);
}
