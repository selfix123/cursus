NAME	=	libftprintf.a
LIBFT	= 	libft.a
LDIR	=	libft/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	ft_printf.c\
			ft_printc.c\
			ft_print_pourc.c\
			ft_prints.c\
			ft_printi.c\
			ft_printp.c\
			ft_printu.c\
			ft_printx.c

OBJS	=	$(SRCS:.c=.o)

all: $(LDIR)$(LIBFT) $(NAME)

$(NAME): $(OBJS) 
	cp $(LDIR)$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LDIR)$(LIBFT):
	$(MAKE) -C $(LDIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)

re: fclean all