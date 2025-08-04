include files.mk

NAME			= allinone
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror


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