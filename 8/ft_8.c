#include "../includes/ft_printf.h"

void	ft_8(t_form form, int *cnt)
{
	//%% 
	//try precision zero
	form.width = (form.width < 1 ? 1 : form.width);
	(*cnt) += form.width;
	if (!form.flag[0])
	{
		while (form.width-- > 1)
		{
			if (form.flag[4])
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
	}
	ft_putchar_fd('%', 1);
	if (form.flag[0])
	{
		while (form.width-- > 1)
			ft_putchar_fd(' ', 1);
	}
}
