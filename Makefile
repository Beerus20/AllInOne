include files.mk

NAME			= allinone
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror

MAKEFLAGS		= --no-print-directory
ARGS			=

ifneq ("$(ARG)", "")
	ARGS := "$(ARG)"
endif

all				: $(NAME)

$(NAME)			: $(OBJS)
					$(call create_executable, $^, $@)

clean			:
					@rm -rf $(OBJS)
					@echo OBJECTS CLEANED

fclean			: clean
					@rm -rf $(NAME)
					@echo FILEs CLEANED

re				: fclean all

.PHONY			: all clean fclean re

include rules.mk
include functions.mk