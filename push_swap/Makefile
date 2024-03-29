NAME	=	push_swap
LIBFT	= 	libft.a
LDIR	=	libft/

# Color
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
WHITE	=	\033[0m

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	utils.c\
			push_swap.c\
			rr.c\
			ss.c\
			pp.c\
			rrr.c\
			small_sort.c\
			list.c\
			radix_sort.c\
			parsing.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling . . .$(WHITE)\n"
	@ $(MAKE) -C $(LDIR)
	@ $(CC) $(CFLAGS) $(SRCS) $(LDIR)$(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "$(BLUE)Create objects$(WHITE)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(LDIR)*.o
	@echo "$(RED)Removes objects$(WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LDIR)$(LIBFT)
	@echo "$(RED)Removes executables$(WHITE)"

visudown:
	git clone https://github.com/o-reo/push_swap_visualizer.git && cd push_swap_visualizer && mkdir build && cd build && cmake .. && make

visu:
	./push_swap_visualizer/build/bin/visualizer

re: fclean all