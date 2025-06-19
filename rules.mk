output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.cpp | output
				$(call create_object, $<, $@)

run			: $(NAME)
				./$(NAME)

rerun		: re run

vrun		: $(NAME)
				valgrind ./$(NAME)