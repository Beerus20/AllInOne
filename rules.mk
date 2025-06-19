output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.cpp | output
				$(call create_object, $<, $@)

output/%.o	: */%.cpp | output
				$(call create_object, $<, $@)

run			: $(NAME)
				./$(NAME)

rerun		: re run

vrun		: $(NAME)
				valgrind ./$(NAME)

vrun_strict	: $(NAME)
				valgrind --leak-check=full -s ./$(NAME)