##
## Makefile for rt in /home/josso/en_cours/rt
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Fri Jan 29 18:32:59 2016 Arthur Josso
## Last update Sat May 21 16:20:45 2016 Arthur Josso
##

NAME    =	raytracer2

CC	= 	gcc

INC     =       ./include/

CFLAGS 	+=	-I$(INC) \
		-W -Wall -Wextra -Werror -O3

LDFLAGS +=	-I/home/${USER}/.froot/include/ \
                -L/home/${USER}/.froot/lib/ \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
                -lsfml-system -lstdc++ -ldl -lm \
		-lpthread

SRCS	=	./src/

INIT	=	./src/init/

IN_MESH	=	./src/init/mesh/

MATH	=	./src/math/

LIGHT	=	./src/light/

DISPLAY	=	./src/display/

CORE	=	./src/core/

MY	=	./src/my/

EXIT	=	./src/exit/

PERLIN	=	./src/perlin/

SOLVER	=	./src/solver/

JIF	=	./src/jif/

CAM	=	./src/cam/

KEYS	=	./src/keys/

SRC	= 	$(SRCS)main.c \
		$(DISPLAY)thread.c \
		$(DISPLAY)display.c \
		$(INIT)init.c \
		$(INIT)get.c \
		$(INIT)get2.c \
		$(INIT)load.c \
		$(INIT)add_cam.c \
		$(INIT)add_cylinder.c \
		$(INIT)add_light.c \
		$(INIT)add_sphere.c \
		$(INIT)add_cone.c \
		$(INIT)add_torus.c \
		$(INIT)add_plan.c \
		$(INIT)add_mobius.c \
		$(IN_MESH)add_mesh.c \
		$(IN_MESH)parsing.c \
		$(IN_MESH)add_basic.c \
		$(IN_MESH)add_face.c \
		$(MATH)find_k.c \
		$(MATH)math.c \
		$(MATH)sphere.c \
		$(MATH)cylinder.c \
		$(MATH)cone.c \
		$(MATH)torus.c \
		$(MATH)plan.c \
		$(MATH)mobius.c \
		$(MATH)mesh.c \
		$(MATH)screen.c \
		$(MATH)rotation.c \
		$(SOLVER)op.c \
		$(SOLVER)math.c \
		$(SOLVER)utils.c \
		$(SOLVER)deg_2.c \
		$(SOLVER)deg_3.c \
		$(SOLVER)deg_4.c \
		$(LIGHT)light.c \
		$(LIGHT)phong.c \
		$(LIGHT)normal_vec.c \
		$(LIGHT)normal_vec_2.c \
		$(LIGHT)reflect.c \
		$(LIGHT)refract.c \
		$(LIGHT)antialiasing.c \
		$(PERLIN)gen_tab.c \
		$(PERLIN)perlin.c \
		$(PERLIN)core_perlin.c \
		$(CORE)tekpixel.c \
		$(CORE)color.c \
		$(CORE)vector.c \
		$(CORE)vector2.c \
		$(CORE)texture.c \
		$(CORE)get_perlin.c \
		$(CORE)reflec_vector.c \
		$(CORE)bump_vec.c \
		$(EXIT)exit.c \
		$(EXIT)free_obj.c \
		$(KEYS)callback.c \
		$(KEYS)move.c \
		$(KEYS)height.c \
		$(KEYS)esc.c \
		$(KEYS)rotate.c \
		$(KEYS)effect.c \
		$(KEYS)cam.c \
		$(JIF)new.c \
                $(JIF)open.c \
                $(JIF)add.c \
                $(JIF)close.c \
                $(JIF)next.c \
		$(CAM)path_open.c \
		$(CAM)path_close.c \
		$(CAM)path_read.c \
		$(CAM)path_write.c \
		$(CAM)gen.c \
		$(CAM)record.c \
		$(MY)my_getnbr.c \
		$(MY)my_getdouble.c \
		$(MY)my_strcmp.c \
		$(MY)my_getpixel.c \
		$(MY)my_memset.c \
		$(MY)my_memcmp.c \
		$(MY)my_epurstr.c \
		$(MY)my_getnextline.c \
		$(MY)my_str_to_tab.c \
		$(MY)my_is_float.c \
		$(MY)my_isnbr.c

OBJ	= 	$(SRC:.c=.o)

RM	= 	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re $(NAME)
