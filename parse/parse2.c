#include "../includes/ft_printf.h"

void	ft_get_convention(char **str, t_form *form)
{
	char	check[13];
	int		ct;

	check[0] = 'c';
	check[1] = 's';
	check[2] = 'p';
	check[3] = 'd';
	check[4] = 'i';
	check[5] = 'u';
	check[6] = 'x';
	check[7] = 'X';
	check[8] = '%';
	check[9] = 'n';
	check[10] = 'f';
	check[11] = 'g';
	check[12] = 'e';
	ct = -1;
	while (++ct < 13)
		if (**str == check[ct])
		{
			form->convention = ct;
			(*str)++;
			return ;
		}
}

void	ft_get_form_length(char **str, t_form *form)
{
	if (**str == 'l')
	{
		(*str)++;
		if (**str == 'l')
		{
			form->length = 1;
			(*str)++;
		}
		else
			form->length = 0;
	}
	else if (**str == 'h')
	{
		(*str)++;
		if (**str == 'h')
		{
			form->length = 3;
			(*str)++;
		}
		else
			form->length = 2;
	}
}
