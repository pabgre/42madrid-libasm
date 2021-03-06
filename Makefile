# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 12:10:54 by pablo             #+#    #+#              #
#    Updated: 2021/03/02 17:02:41 by psan-gre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)

NA			=	nasm
NA_FLAGS	=	-fmacho64
NAME		=	libasm.a
TEST		=	test.out

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME) ./$(TEST) ./test2.out

re:				fclean $(NAME)

test:			$(NAME)
				clang -o $(TEST) main.c test.c -L. -lasm -lftprintf
				./$(TEST)

test2: 			$(NAME)
				clang -o test2.out tester2/*.c -L. -lasm -lftprintf
				./test2.out

.PHONY:			clean fclean re test
