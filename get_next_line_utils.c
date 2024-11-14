#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (char)c)
        return ((char *)s);
    return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*new_str;
    size_t	i;
    size_t	j;

    if (!s1 || !s2)
        return (NULL);
    new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new_str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        new_str[i + j] = s2[j];
        j++;
    }
    new_str[i + j] = '\0';
    return (new_str);
}

char	*ft_strdup(const char *s)
{
    char	*dup;
    size_t	len;
    size_t	i;

    len = ft_strlen(s);
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*substr;
    size_t	i;
    size_t	s_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    substr = malloc(len + 1);
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}   