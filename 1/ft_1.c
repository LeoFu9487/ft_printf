#include "../includes/ft_printf.h"

static void	ft_1_(t_form form, va_list *arg, int *cnt)
{
	char	*out;

	out = va_arg(*arg, char*);
	out = (out ? out : "null");
	if (form.precision == -1)
		form.precision = (int)ft_strlen(out);
	else if (form.precision > (int)ft_strlen(out))
		form.precision = (int)ft_strlen(out);
	form.width = (form.width > form.precision ? form.width : form.precision);
	(*cnt) += form.width;
	form.width -= form.precision;
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(form.flag[4] ? '0' : ' ', 1);
	while (form.precision-- > 0)
		ft_putchar_fd(*(out++), 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_1_0(t_form form, va_list *arg, int *cnt)
{
	void	*out;
	char	*ptr;

	ptr = "null";
	out = va_arg(*arg, wchar_t*);
	out = (out ? out : ptr);
	if (form.precision == -1)
		form.precision = (int)ft_strlen(out);
	else if (form.precision > (int)ft_strlen(out))
		form.precision = (int)ft_strlen(out);
	form.width = (form.width > form.precision ? form.width : form.precision);
	(*cnt) += form.width;
	form.width -= form.precision;
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(form.flag[4] ? '0' : ' ', 1);
	while (form.precision-- > 0)
		ft_putchar_fd(*((char*)out++), 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

//does this work ? 

void		ft_1(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_1_0(form, arg, cnt);
	else
		ft_1_(form, arg, cnt);
}