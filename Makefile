	
NAME 		= server&client
SERVER		= server
CLIENT		= client

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror

SUBDIRS 	= 
DIR_OBJ 	= ./obj

INCS 		= $(wildcard *.h $(foreach fd, $(SUBDIRS), $(fd)/*.h))
SRCS 		= $(wildcard *.c $(foreach fd, $(SUBDIRS), $(fd)/*.c))
OBJS 		= $(addprefix $(DIR_OBJ)/, $(SRCS:c=o))
INC_DIRS 	= -I./ $(addprefix -I, $(SUBDIRS))

UOBJS		= ./obj/utils_00.o
SOBJS		= ./obj/server.o
COBJS		= ./obj/client.o $(UOBJS)

LIBFT		= libft/libft.a
LIBS 		= $(LIBFT)

$(NAME):
	make $(SERVER) 
	make $(CLIENT)

$(SERVER): $(LIBS) $(SOBJS) $(INCS)
	$(CC) $(FLAGS) $(SOBJS) $(LIBS) -o $(SERVER)

$(CLIENT): $(LIBS) $(COBJS) $(INCS)
	$(CC) $(FLAGS) $(COBJS) $(LIBS) -o $(CLIENT)

$(DIR_OBJ)/%.o: %.c $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ $(FLAGS) -c $< $(INC_DIRS)

$(LIBFT):
	make -C libft

libft: $(LIBFT)

libs: libft

all: libft $(NAME)

clean: allclean

aclean: allaclean

fclean: allclean allaclean

allclean:
	make clean -C libft
	rm -rf obj

allaclean:
	make aclean -C libft
	rm -rf $(SERVER) $(CLIENT)

allfclean: allclean allaclean

bonus: all

re: fclean all

reall: allfclean all

.PHONY: all clean fclean re
