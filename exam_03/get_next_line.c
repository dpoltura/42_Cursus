# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)	
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(const char *src)
{
	size_t	len = ft_strlen(src) + 1;
	char	*dst = malloc(len);
	
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len = ft_strlen(s1);
	size_t	s2_len = ft_strlen(s2);
	char	*join = malloc((s1_len + s2_len + 1));

	if (!s1 || !s2)
		return (NULL);
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + s1_len), s2);
	free(s1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf); // Alloue de la mémoire pour la ligne et la initialise avec le contenu du buffer statique

	while (!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))
	{
		buf[countread] = '\0'; // Met fin au buffer lu par la fonction read()
		line = ft_strjoin(line, buf); // Concatène le buffer lu avec la ligne existante
	}

	if (ft_strlen(line) == 0)
		return (free(line), NULL); // Si la ligne est vide, libère la mémoire et retourne NULL

	if (newline != NULL)
	{
		to_copy = newline - line + 1; // Calcule le nombre de caractères à copier jusqu'au prochain '\n'
		ft_strcpy(buf, newline + 1); // Copie le reste du buffer après le '\n' dans le buffer statique
	}
	else
	{
		to_copy = ft_strlen(line); // Si '\n' n'est pas trouvé, copie toute la ligne
		buf[0] = '\0'; // Réinitialise le buffer statique car il n'y a plus rien à lire
	}

	line[to_copy] = '\0'; // Ajoute le caractère de fin de chaîne à la ligne
	return (line); // Retourne la ligne lue
}
