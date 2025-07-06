test		:
				echo $(OBJS)

output		:
				@if [ ! -d $@ ]; then mkdir $@; fi

%/output		:
				@if [ ! -d $@ ]; then mkdir $@; fi

output/%.o	: %.cpp | output
				echo "tests 1"
				$(call create_object, $<, $@)

run			: $(NAME)
				./$(NAME)

rerun		: re run

revrun		: re vrun

revsrun		: re vsrun

vrun		: $(NAME)
				valgrind \
					--leak-check=full \
					--suppressions=sdl.supp \
					--show-leak-kinds=definite \
					--errors-for-leak-kinds=none \
					--child-silent-after-fork=yes \
				./$(NAME)

vsrun		: $(NAME)
				valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --log-file=valgrind.log ./$(NAME)
