

INC=%%%%

INCLIB=$(INC)/../lib

CC=clang

CFLAGS= -I$(INC) -O3 -I../minilibx-linux

SRC = find_wall_dist_horiz.c find_wall_dist_vert.c raycasting.c math_ft.c \
	  ft_mapping.c mlx_ft.c ray_orient.c
OBJ = $(SRC:.c=.o)

TESTFUN_NAME= maintest
TESTFUN_MAIN= maintest.c
OBJ_TESTFUN=  $(TESTFUN_MAIN:.c=.o)

NAME1= test1
MAIN1= test1.c
OBJ_MAIN1 = $(MAIN1:.c=.o)

all	:$(NAME1)

$(NAME1)	:$(OBJ_MAIN1) $(OBJ)
	$(CC) -o $(NAME1) $(OBJ_MAIN1) $(OBJ) -lm -lmlx -lX11 -lXext

$(TESTFUN_NAME)	:$(OBJ) $(OBJ_TESTFUN)
	$(CC) -o $(TESTFUN_NAME) $(OBJ_TESTFUN) $(OBJ) -L../minilibx-linux/ -L. -lmlx -lXext -lX11 -lm

clean		:
	rm -f $(NAME1) $(TESTFUN_NAME) *.o *~ 


re	: clean all
