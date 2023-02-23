#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "./Ma_Libft/libft.h"

typedef struct s_list
{
    char            c;
    struct s_list   *next;
    
}               chaine;