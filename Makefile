include files.mk

NAME			= allinone
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

test	:
			echo $(pkg-config --cflags --libs SDL2 SDL2_image)

all				: $(NAME)

$(NAME)			: $(OBJS)
					$(call create_executable, $^, $@)

clean			:
					rm -rf $(OBJS)

fclean			: clean
					rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re

include rules.mk
include functions.mk