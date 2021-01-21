#include "../includes/ft_printf.h"

/*
** @desc Write 3 and 4 byte characters
** @param unsigned int c - character in decimal for writing
** @return 3 if 3 byte character was written
** @return 4 if 4 byte character was written
** @return 0 if character is not UTF - 8
*/

static unsigned	ft_cnt(unsigned *arr)
{
	if (arr[0] <= 0x7F)
		return (1U);
	else if (arr[0] >= 0x80 && arr[0] <= 0x7FF)
		return (2U);
	else if (arr[0] >= 0x800 && arr[0] <= 0xFFFF)
		return (3U);
	else if (arr[0] >= 0x10000 && arr[0] <= 0x10FFFF)
		return (4U);
	return (0U);
}

static void		ft_put(unsigned *arr)
{
	if (arr[0] <= 0x7F)
		write(1, arr, 1);
	else if (arr[0] >= 0x80 && arr[0] <= 0x7FF)
	{
		arr[1] = ((arr[0] & 0xFC0) >> 6) | 0xC0;
		arr[2] = (arr[0] & 0x3F) | 0x80;
		write(1, arr + 1, 2);
	}
	else if (arr[0] >= 0x800 && arr[0] <= 0xFFFF)
	{
		arr[1] = ((arr[0] & 0x3F000) >> 12) | 0xE0;
		arr[2] = ((arr[0] & 0xFC0) >> 6) | 0x80;
		arr[3] = (arr[0] & 0x3F) | 0x80;
		write(1, arr + 1, 3);
	}
	else if (arr[0] >= 0x10000 && arr[0] <= 0x10FFFF)
	{
		arr[1] = ((arr[0] & 0x1C0000) >> 18) | 0xF0;
		arr[2] = ((arr[0] & 0x3F000) >> 12) | 0x80;
		arr[3] = ((arr[0] & 0xFC0) >> 6) | 0x80;
		arr[4] = (arr[0] & 0x3F) | 0x80;
		write(1, arr + 1, 4);
	}
}

void        	ft_0_0(t_form form, va_list *arg, int *cnt)
{
	unsigned	arr[6];

	arr[0] = (unsigned)va_arg(*arg, int);
	arr[5] = ft_cnt((unsigned*)arr);
	(*cnt) += ft_max(form.width, (int)arr[5]);
	form.width = ft_max(0, form.width - (int)arr[5]);
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	ft_put((unsigned*)arr);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

/*
** @desc Write 1 and 2 byte characters
** @param t_node *node - structure of a conversion specifier
** @param const wchar_t *s1 - multibyte string
** @param int wlen - count of characters to output
** @return size - size in bytes of printed characters
*/
/*
int			ft_wchar_putnstr(t_node *node, const wchar_t *s1, int wlen)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s1 != NULL && i < wlen)
	{
		size = size + ft_wchar(node, s1[i]);
		i++;
	}
	return (size);
}
*/
/*
** @desc Determine size of whole multibyte string
** @param wchar_t *s1 - multibyte string
** @return size - size in bytes of multibyte string
*/
/*
size_t		ft_wchar_bytes(wchar_t *s)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] > 0x0 && s[i] <= 0x7F)
				size = size + 1;
			else if (s[i] >= 0x80 && s[i] <= 0x7FF)
				size = size + 2;
			else if (s[i] >= 0x800 && s[i] <= 0xFFFF)
				size = size + 3;
			else if (s[i] >= 0x10000 && s[i] <= 0x10FFFF)
				size = size + 4;
			i++;
		}
	}
	return (size);
}
*/
/*
** @desc Return size in bytes of a character
** @param wchar_t c - multibyte character
** @return 1 to 4 based on the size of the character
*/
/*
size_t		ft_wchar_size(wchar_t c)
{
	if (c > 0x0 && c <= 0x7F)
		return (1);
	else if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if (c >= 0x800 && c <= 0xFFFF)
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	return (0);
}
*/