#Makefile fait par sm222 et brian et moi le plus beau
LIBFT	= 	libft.a
LDIR	=	libft/
NCLIENT	=	client
NSERVER	=	server

SERVER	=	server.c

CLIENT	=	client.c

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SERVEROBJS	=	$(SERVER:.c=.o)
CLIENTOBJS	=	$(CLIENT:.c=.o)

all: libft $(NSERVER) $(NCLIENT) 

$(NSERVER): $(SERVEROBJS)
	$(CC) $(CFLAGS) $(SERVEROBJS) $(LDIR)$(LIBFT) -o server

$(NCLIENT): $(CLIENTOBJS)
	$(CC) $(CFLAGS) $(CLIENTOBJS) $(LDIR)$(LIBFT) -o client

libft:
	@$(MAKE) -C $(LDIR)

clean:
	$(RM) $(SERVEROBJS)
	$(RM) $(CLIENTOBJS)
	$(RM) $(LDIR)*.o

fclean: clean
	$(RM) $(NSERVER)
	$(RM) $(NCLIENT)
	$(RM) $(LDIR)$(LIBFT)

re: fclean all

.PHONY: all libft