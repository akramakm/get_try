/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-akma <ael-akma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:35:33 by ael-akma          #+#    #+#             */
/*   Updated: 2023/02/03 10:34:39 by ael-akma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int	ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char) c)
			return ((char *)(s) + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char * akram(int fd)
{
	char *buffer;
	buffer = malloc(BUFFER_SIZE + 1);
	static char *r ;
	r = malloc(1);
	// r[0] = 0;
	while(!ft_strchr(r,'\n'))
	{
		read(fd,buffer,BUFFER_SIZE);
		r = ft_strjoin(r,buffer);
	}
	return(r);
}

char *read_bla_save(char *r)
{
	int i = 0;
	int j = 0;
	while(r[i] != '\n')
		i++;
	char *s;	
	s = malloc( i + 1);
	if(!s)
		return NULL;
	while(j < i)
	{
		s[j] = r[j];
		j++;
	}
	return (s);
}
char *rsave(char *r)
{
	int i = 0;
	int j;
	while(r[i] != '\n')
		i++;
	char *s;	
	s = malloc(ft_strlen(r) - i);
	if(!s)
		return NULL;
	i++;
	j = i;
	int x = 0;
	while(j < ft_strlen(r) + 1)
	{
		s[x] = r[j];
		j++;
		x++;
	}
	s[x] = '\0';
	// printf("%d")
	return (s);
}
char *get_next_line(int fd)
{
	static char *r;
	// r = malloc (1);
	r  = akram(fd);
	char *line ;
	line = read_bla_save(r);
	r = rsave(r);
	return(line);
}
int main()
{
	int fd = open ("akram.txt" , O_CREAT | O_RDWR);
	// fd = open ("akram.txt" , O_CREAT | O_RDWR);
	char *str ;
	str = get_next_line(fd);
	int i = 0;
	while(i < 5)
	{
		printf("%s\n",str);
		i++;
	}
	
}