/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwhat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:32:49 by kdahl             #+#    #+#             */
/*   Updated: 2020/07/12 15:52:02 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

								/*MANUAL*/
		/*Max number of hosts: "-hostmax" "-mask" "255.255.255.255"*/
/*Full info about IP adress:  "-IPv4" "195.70.16.159" "/29" where /29 is your mask*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void	header()
{
	printf("\033[1;32m");
	printf("\t\t|*****************************************|\n");
	printf("\t\t|*|                                     |*|\n");
	printf("\t\t|*|          NETWHAT by kndahl          |*|\n");
	printf("\t\t|*|           _______________           |*|\n");
	printf("\t\t|*|          |IPv4 calculator|          |*|\n");
	printf("\t\t|*|           ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾           |*|\n");
	printf("\t\t|*|                                     |*|\n");
	printf("\t\t|*****************************************|\n");
	printf("\033[0m");

	printf("\033[1;37m");
	printf("\nUsage:\n"); 
		printf("\tMax number of hosts: \"-hostmax\" \"-mask\" \"255.255.255.255\"\n");
		printf("\tFull info about IP adress:  \"-IPv4\" \"195.70.16.159\" \"/29\" where /29 is your mask\n");
		printf("\033[0m");
}

typedef struct	flag
{
	int		hostmax;
	int		mask;
	int		ipv4;
	int		dig_mask;
	char	*dig_ipv4;
}				t_flags;

typedef struct	mask
{
	char	*m0;
	char	*m1;
	char	*m2;
	char	*m3;
	char	*m4;
	char	*m5;
	char	*m6;
	char	*m7;
	char	*m8;
	char	*m9;
	char	*m10;
	char	*m11;
	char	*m12;
	char	*m13;
	char	*m14;
	char	*m15;
	char	*m16;
	char	*m17;
	char	*m18;
	char	*m19;
	char	*m20;
	char	*m21;
	char	*m22;
	char	*m23;
	char	*m24;
	char	*m25;
	char	*m26;
	char	*m27;
	char	*m28;
	char	*m29;
	char	*m30;
	char	*m31;
	char	*m32;
}				t_mask;

t_flags	init_flag(void)
{
	t_flags	flag;

	flag.hostmax = 0;
	flag.mask = 0;
	flag.ipv4 = 0;
	flag.dig_mask = 0;
	flag.dig_ipv4 = 0;
	return (flag);
}

t_mask	init_mask(void)
{
	t_mask	mask;

	mask.m0 = "00000000.00000000.00000000.00000000";
	mask.m1 = "10000000.00000000.00000000.00000000";
	mask.m2 = "11000000.00000000.00000000.00000000";
	mask.m3 = "11100000.00000000.00000000.00000000";
	mask.m4 = "11110000.00000000.00000000.00000000";
	mask.m5 = "11111000.00000000.00000000.00000000";
	mask.m6 = "11111100.00000000.00000000.00000000";
	mask.m7 = "11111110.00000000.00000000.00000000";
	mask.m8 = "11111111.00000000.00000000.00000000";
	mask.m9 = "11111111.10000000.00000000.00000000";
	mask.m10 = "11111111.11000000.00000000.00000000";
	mask.m11 = "11111111.11100000.00000000.00000000";
	mask.m12 = "11111111.11110000.00000000.00000000";
	mask.m13 = "11111111.11111000.00000000.00000000";
	mask.m14 = "11111111.11111100.00000000.00000000";
	mask.m15 = "11111111.11111110.00000000.00000000";
	mask.m16 = "11111111.11111111.00000000.00000000";
	mask.m17 = "11111111.11111111.10000000.00000000";
	mask.m18 = "11111111.11111111.11000000.00000000";
	mask.m19 = "11111111.11111111.11100000.00000000";
	mask.m20 = "11111111.11111111.11110000.00000000";
	mask.m21 = "11111111.11111111.11111000.00000000";
	mask.m22 = "11111111.11111111.11111100.00000000";
	mask.m23 = "11111111.11111111.11111110.00000000";
	mask.m24 = "11111111.11111111.11111111.00000000";
	mask.m25 = "11111111.11111111.11111111.10000000";
	mask.m26 = "11111111.11111111.11111111.11000000";
	mask.m27 = "11111111.11111111.11111111.11100000";
	mask.m28 = "11111111.11111111.11111111.11110000";
	mask.m29 = "11111111.11111111.11111111.11111000";
	mask.m30 = "11111111.11111111.11111111.11111100";
	mask.m31 = "11111111.11111111.11111111.11111110";
	mask.m32 = "11111111.11111111.11111111.11111111";
	return (mask);
}


size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

int	ft_atoi(char *str)
{
	int x;
	int sum;
	int minusorplus;
	int counter;

	sum = 0;
	minusorplus = 1;
	counter = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		minusorplus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		x = *str++ - 48;
		sum = sum * 10 + x;
		counter++;
	}
	if (counter >= 19)
		return (minusorplus == -1 ? 0 : -1);
	return (sum * minusorplus);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		index;

	if (!(dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1))))
		return (NULL);
	index = 0;
	while (s1[index])
	{
		dest[index] = s1[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;
	int				res;

	index = 0;
	res = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (index < num && ((str1[index]) || (str2[index])))
	{
		if (str1[index] > str2[index])
			return (str1[index] - str2[index]);
		if (str1[index] < str2[index])
			return (str1[index] - str2[index]);
		if (str1[index] == str2[index])
			res = 0;
		index++;
	}
	return (res);
}


int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t index;

	index = 0;
	while ((src[index]) && src[index] != '.')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		index1;
	int		index2;

	if (s1 && s2)
	{
		if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		index1 = 0;
		index2 = 0;
		while (s1[index1])
			str[index1++] = s1[index2++];
		index2 = 0;
		while (s2[index2])
			str[index1++] = s2[index2++];
		str[index1] = '\0';
		return (str);
	}
	else
		return (NULL);
}

char	*ft_strchr(const char *s, int ch)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == ch)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == '\0' && (char)ch == '\0')
		return ((char *)&s[index]);
	return (NULL);
}

int		get_size(unsigned int num)
{
	unsigned int	size;

	size = 0;
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	index;
	unsigned int	size;

	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	size = (unsigned int)get_size(num);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[0] = '-'))
		size++;
	index = size - 1;
	while (num >= 10)
	{
		str[index] = (char)(num % 10 + 48);
		num /= 10;
		index--;
	}
	str[index] = (char)(num % 10 + 48);
	str[size] = '\0';
	return (str);
}

char	*ft_wildmask(const char *hex, int index)
{
	char	*rev_hex;
	int		ri;

	ri = 0;
	rev_hex = malloc(35);
	while (index <= 35)
	{
		if (hex[index] == '1')
			rev_hex[ri] = '0';
		if (hex[index] == '.')
			rev_hex[ri] = hex[index];
		if (hex[index] == '0')
			rev_hex[ri] = '1';
		ri++;
		index++;
	}
	rev_hex[ri] = '\0';
	free((char *)hex);
	return (rev_hex);
}


t_flags		check_argv1(char *arg2, t_flags *flag)
{
	char	*str = "-hostmax";
	char	*str1 = "-IPv4";
	int		f;

	f = 0;
	while (*arg2 && *str)
	{
		if (*arg2 == *str)
			f = 1;
		else if (*arg2 == *str1)
			f = 2;
		else
			f = 0;
		arg2++;
		str++;
		str1++;
	}
	if (f == 1)
		flag->hostmax = 1;
	if (f == 2)
		flag->ipv4 = 1;
	return (*flag);
}

void		get_ipv4(char *ipv4, t_flags *flag)
{
	flag->dig_ipv4 = ft_strdup(ipv4);
}

t_flags		check_argv2(char *arg2, t_flags *flag)
{
	char	*str = "-mask";
	int		f;

	f = 0;
	if  (flag->ipv4)
	{
		get_ipv4(arg2, flag);
		return (*flag);
	}
	while (*arg2 && *str)
	{
		if (*arg2 == *str)
			f = 1;
		else
			f = 0;
		arg2++;
		str++;
	}
	if (f == 1)
		flag->mask = 1;
	return (*flag);
}

char	*itob(int x, int flag)
{
	char	*buf;

	buf = malloc(8);
	unsigned char *ptr = (unsigned char *)&x;
	int pos = 0;
	for (int i = sizeof(char) - 1; i >= 0; i--)
		for (int j = CHAR_BIT - 1; j >= 0; j--)
			buf[pos++] = '0' + !!(ptr[i] & 1U << j);
	if (flag == 0)
		buf[pos++] = '.';
	buf[pos] = '\0';
	return (buf);
}

int 	btoi(char *buffer)
{
    int i,sum=0;
    for(i=0;i<8;i++)
    {
        sum=sum*2+((int)buffer[i]-48);
    }
    return (sum);
}

void	get_bits(char *p2_given, int flag)
{
	char	*octet1;
	char	*octet2;
	char	*octet3;
	char	*octet4;
	char	*mask = NULL;
	char	*str;
	char	*o1;
	char	*o2;
	char	*o3;
	char	*o4;
	int		host_mask = 0;
	int		num_hosts = 0;
	
	if (flag == 1)
	{
		while (*p2_given != '0')
		{
			if (*p2_given == '1')
				host_mask += 1;
			p2_given++;
		}
		num_hosts = pow(2, (32 - host_mask)) - 2;
	}
	if (!flag)
	{
			if (ft_strncmp(p2_given, "255.255.255.255", 16) == 0)
		{
			printf("\033[1;31m");
			printf("%s in binary:       ", p2_given);
			printf("\033[0m");
			printf("\033[1;32m");
			printf("|11111111.11111111.11111111.11111111|\n");
			printf("\033[0m");
			printf("\033[1;31m");
			printf("Max number of hosts:             ");
			printf("\033[0m");
			printf("\033[1;33m");
			printf("|0|\n");
			printf("\033[0m");
			return ;
		}
		octet1 = malloc(8);
		octet2 = malloc(8);
		octet3 = malloc(8);
		octet4 = malloc(8);
			o1 = malloc(8);
		o2 = malloc(8);
		o3 = malloc(8);
			o4 = malloc(8);
		mask = malloc(32);
		str = ft_strdup(p2_given);
		octet1 = ft_strcpy(octet1, str);
		str = ft_strchr(str, '.');
		str++;
		octet2 = ft_strcpy(octet2, str);
		str = ft_strchr(str, '.');
		str++;
		octet3 = ft_strcpy(octet3, str);
		str = ft_strchr(str, '.');
		str++;
		octet4 = ft_strcpy(octet4, str);
		printf("\033[1;31m");
		printf("%s in binary:       ", p2_given);
		printf("\033[0m");
		o1 = itob(ft_atoi(octet1), 0);
		o2 = itob(ft_atoi(octet2), 0);
		o3 = itob(ft_atoi(octet3), 0);
		o4 = itob(ft_atoi(octet4), 1);
		printf("\033[1;32m");
		printf("|%s%s%s%s|\n", o1, o2, o3, o4);
		printf("\033[0m");
		mask = ft_strjoin(o1, o2);
		mask = ft_strjoin(mask, o3);
		mask = ft_strjoin(mask, o4);
		while (*mask != '0')
		{
			if (*mask == '1')
				host_mask += 1;
			mask++;
		}
		num_hosts = pow(2, (32 - host_mask)) - 2;
		free(octet1);
		free(octet2);
		free(octet3);
		free(octet4);
		free(o1);
		free(o2);
		free(o3);
		free(o4);
	}
	printf("\033[1;31m");
	printf("Max number of hosts:         ");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("|%d|\n", num_hosts);
	printf("\033[0m");
}

char	*ip_2bin(char *ip)
{
	char	*octet1;
	char	*octet2;
	char	*octet3;
	char	*octet4;
	char	*ip_bin;
	char	*str;
	char	*o1;
	char	*o2;
	char	*o3;
	char	*o4;
	
	octet1 = malloc(8);
	octet2 = malloc(8);
	octet3 = malloc(8);
	octet4 = malloc(8);
	o1 = malloc(8);
	o2 = malloc(8);
	o3 = malloc(8);
	o4 = malloc(8);
	ip_bin = malloc(32);
	str = ft_strdup(ip);
	octet1 = ft_strcpy(octet1, str);
	str = ft_strchr(str, '.');
	str++;
	octet2 = ft_strcpy(octet2, str);
	str = ft_strchr(str, '.');
	str++;
	octet3 = ft_strcpy(octet3, str);
	str = ft_strchr(str, '.');
	str++;
	octet4 = ft_strcpy(octet4, str);
	printf("\033[1;31m");
	printf("IP in binary:                ");
	printf("\033[0m");
	o1 = itob(ft_atoi(octet1), 0);
	o2 = itob(ft_atoi(octet2), 0);
	o3 = itob(ft_atoi(octet3), 0);
	o4 = itob(ft_atoi(octet4), 1);
	printf("\033[1;33m");
	printf("|%s%s%s%s|\n", o1, o2, o3, o4);
	printf("\033[0m");
	ip_bin = ft_strjoin(o1, o2);
	ip_bin = ft_strjoin(ip_bin, o3);
	ip_bin = ft_strjoin(ip_bin, o4);
	return (ip_bin);
}

char	*get_getmask(int flag_to_mask, t_mask *mask)
{
	char	*getmask;

	if (flag_to_mask == 1)
		getmask = ft_strdup(mask->m1);
	if (flag_to_mask == 2)
		getmask = ft_strdup(mask->m2);
	if (flag_to_mask == 3)
		getmask = ft_strdup(mask->m3);
	if (flag_to_mask == 4)
		getmask = ft_strdup(mask->m4);
	if (flag_to_mask == 5)
		getmask = ft_strdup(mask->m5);
	if (flag_to_mask == 6)
		getmask = ft_strdup(mask->m6);
	if (flag_to_mask == 7)
		getmask = ft_strdup(mask->m7);
	if (flag_to_mask == 8)
		getmask = ft_strdup(mask->m8);
	if (flag_to_mask == 9)
		getmask = ft_strdup(mask->m9);
	if (flag_to_mask == 10)
		getmask = ft_strdup(mask->m10);
	if (flag_to_mask == 11)
		getmask = ft_strdup(mask->m11);
	if (flag_to_mask == 12)
		getmask = ft_strdup(mask->m12);
	if (flag_to_mask == 13)
		getmask = ft_strdup(mask->m13);
	if (flag_to_mask == 14)
		getmask = ft_strdup(mask->m14);
	if (flag_to_mask == 15)
		getmask = ft_strdup(mask->m15);
	if (flag_to_mask == 16)
		getmask = ft_strdup(mask->m16);
	if (flag_to_mask == 17)
		getmask = ft_strdup(mask->m17);
	if (flag_to_mask == 18)
		getmask = ft_strdup(mask->m18);
	if (flag_to_mask == 19)
		getmask = ft_strdup(mask->m19);
	if (flag_to_mask == 20)
		getmask = ft_strdup(mask->m20);
	if (flag_to_mask == 21)
		getmask = ft_strdup(mask->m21);
	if (flag_to_mask == 22)
		getmask = ft_strdup(mask->m22);
	if (flag_to_mask == 23)
		getmask = ft_strdup(mask->m23);
	if (flag_to_mask == 24)
		getmask = ft_strdup(mask->m24);
	if (flag_to_mask == 25)
		getmask = ft_strdup(mask->m25);
	if (flag_to_mask == 26)
		getmask = ft_strdup(mask->m26);
	if (flag_to_mask == 27)
		getmask = ft_strdup(mask->m27);
	if (flag_to_mask == 28)
		getmask = ft_strdup(mask->m28);
	if (flag_to_mask == 29)
		getmask = ft_strdup(mask->m29);
	if (flag_to_mask == 30)
		getmask = ft_strdup(mask->m30);
	if (flag_to_mask == 31)
		getmask = ft_strdup(mask->m31);
	if (flag_to_mask == 32)
		getmask = ft_strdup(mask->m32);
	return (getmask);
}

void	get_netip(char *ipbin, int flag)
{
	char	*octet1;
	char	*octet2;
	char	*octet3;
	char	*octet4;
	char	*ip_bin;
	char	*str;
	int		o1;
	int		o2;
	int		o3;
	int		o4;
	
	octet1 = malloc(8);
	octet2 = malloc(8);
	octet3 = malloc(8);
	octet4 = malloc(8);
	ip_bin = malloc(32);
	str = ft_strdup(ipbin);
	octet1 = ft_strcpy(octet1, str);
	str = ft_strchr(str, '.');
	str++;
	octet2 = ft_strcpy(octet2, str);
	str = ft_strchr(str, '.');
	str++;
	octet3 = ft_strcpy(octet3, str);
	str = ft_strchr(str, '.');
	str++;
	octet4 = ft_strcpy(octet4, str);
	o1 = btoi(octet1);
	o2 = btoi(octet2);
	o3 = btoi(octet3);
	o4 = btoi(octet4);
	printf("\033[1;31m");
	if (!flag)
		printf("Network address:             ");
	if (flag == 1)
		printf("Broadcast:                   ");
	if (flag == 2)
		printf("1st host IP:                 ");
	if (flag == 3)
		printf("Last host IP:                ");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("|%d.%d.%d.%d|\n", o1, o2, o3, o4);
	printf("\033[0m");
}

char	*get_netadr(char *ipadr, char *mask_num)
{
	char	*netadr;
	char	*rem;
	int		i = 0;
	int		index1 = 0;
	int		index2 = 0;

	netadr = malloc(35);
	rem = malloc(35);
	while (index1 <= 35)
	{
		if (ipadr[index1] == '1' && mask_num[index2] == '1')
			netadr[i] = '1';
		if (ipadr[index1] == '1' && mask_num[index2] == '0')
			netadr[i] = '0';
		if (ipadr[index1] == '0' && mask_num[index2] == '1')
			netadr[i] = '0';
		if (ipadr[index1] == '0' && mask_num[index2] == '0')
			netadr[i] = '0';
		if (ipadr[index1] == '.' && mask_num[index2] == '.')
			netadr[i] = '.';
		i++;
		index1++;
		index2++;
	}
	netadr[i] = '\0';
	rem = ft_strdup(netadr);
	printf("\033[1;31m");
	printf("Network address in binary:   ");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("|%s|\n", netadr);
	printf("\033[0m"); 
	get_netip(netadr, 0);
	free((char *)netadr);
	return (rem);
}

char	*get_broadcasting(char *net_bin, char *wild_mask)
{
	char	*broadcast = NULL;
	int		index1 = 0;
	int		index2 = 0;
	int		i  = 0;

	broadcast = malloc(36);
	while (index1 <= 35)
	{
		if (net_bin[index1] == '1')
			broadcast[i] = '1';
		if (net_bin[index1] == '0' && wild_mask[index2] != '1')
			broadcast[i] = '0';
		if (net_bin[index1] == '0' && wild_mask[index2] == '1')
			broadcast[i] = '1';
		if (net_bin[index1] == '1' && wild_mask[index2] == '1') //True?
			broadcast[i] = '1';
		index1++;
		index2++;
		i++;
	}
	broadcast[i] = '\0';
	printf("\033[1;31m");
	printf("Broadcast in binary:         ");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("|%s|\n", broadcast);
	printf("\033[0m");
	get_netip(broadcast, 1);
	//free(net_bin);
	//free(wild_mask);
	return (broadcast);
}

void	get_firsthost(char *netbin)
{
	char	*bin_1host = NULL;
	int		i1 = 0;
	int		i2 = 0;

	bin_1host = malloc(35);
	while (netbin[i1])
	{
		bin_1host[i2] = netbin[i1];
		i1++;
		i2++;
	}
	bin_1host[--i2] = '1';
	bin_1host[++i2] = '\0';
	get_netip(bin_1host, 2);
}

void	get_lasthost(char *brdcst)
{
	char	*bin_lhost = NULL;
	int		i1 = 0;
	int		i2 = 0;

	bin_lhost = malloc(35);
	while (brdcst[i1])
	{
		bin_lhost[i2] = brdcst[i1];
		i1++;
		i2++;
	}
	bin_lhost[--i2] = '0';
	bin_lhost[++i2] = '\0';
	get_netip(bin_lhost, 3);
}

void	get_ipv4mask_info(char *ip, char *arg3, t_flags *flag)
{
	t_mask	mask;
	int		flag_to_mask = 0;
	char	*getmask = NULL;
	char	*wildcard_mask;
	char	*rem;
	char	*netinbin = NULL;
	char	*brdcst = NULL;

	mask = init_mask();
	wildcard_mask = malloc(35);
	netinbin = malloc(35);
	rem = malloc(35);
	printf("\033[1;31m");
	printf("IP adress:                   ");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("|%s|\n", flag->dig_ipv4);
	printf("\033[0m");
	while (!ft_isdigit(*arg3))
		arg3++;
	flag->dig_mask = ft_atoi(arg3);
	printf("\033[1;31m");
	printf("Mask:                        ");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("|%d|\n", flag->dig_mask);
	printf("\033[0m");
	flag_to_mask = flag->dig_mask;
	getmask = get_getmask(flag_to_mask, &mask);
	if (flag_to_mask >= 0 && flag_to_mask <= 32)
	{
		printf("\033[1;31m");
		printf("Mask in binary:              ");
		printf("\033[0m");
		printf("\033[1;33m");
		printf("|%s|\n", getmask);
		printf("\033[0m");
	}
	rem = ft_strdup(getmask);
	wildcard_mask = ft_wildmask(rem, 0);
	printf("\033[1;31m");
	printf("Wildcard mask:               ");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("|%s|\n", wildcard_mask);
	printf("\033[0m");
	rem = NULL;
	rem = ip_2bin(ip);
	netinbin = get_netadr(rem, getmask);
	//printf("%s\n", );
	brdcst = ft_strdup(get_broadcasting(netinbin, wildcard_mask));
	get_firsthost(netinbin);
	get_lasthost(brdcst);
	get_bits(getmask, 1);
	rem = NULL;
	wildcard_mask = NULL;
	free(rem);
	free(wildcard_mask);
	free(getmask);
}

int		argv_parser(char **argv, t_flags *flag)
{
	char	*arg2;
	char	*p1_given;
	char	*p2_given;
	int		validity;

	arg2 = ft_strdup(argv[1]);
	p1_given = ft_strdup(argv[2]);
	p2_given = ft_strdup(argv[3]);
	validity = 0;
	check_argv1(arg2, flag);
	check_argv2(p1_given, flag);
	if (flag->hostmax && flag->mask)
	{
		get_bits(p2_given, 0);
		free(arg2);
		free(p1_given);
		free(p2_given);
		return (validity = 1);
	}
	if (flag->ipv4)
	{
		get_ipv4mask_info(p1_given, p2_given, flag);
		validity = 1;
	}
	free(arg2);
	free(p1_given);
	free(p2_given);
	return (validity);
}

void	netwhat(char **argv)
{
	t_flags	flag;
	int		validity;

	flag = init_flag();
	if	(!(validity = argv_parser(argv, &flag)))
	{
		printf("\033[1;31m");
		printf("\nNot valid arguments!\n\n");
		printf("\033[0m");
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		netwhat(argv);
	else
		header();
	return (0);
}