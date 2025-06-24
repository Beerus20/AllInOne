output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.cpp | output
				$(call create_object, $<, $@)

output/%.o	: */%.cpp | output
				$(call create_object, $<, $@)

run			: $(NAME)
				./$(NAME)

rerun		: re run

revrun		: re vrun

revsrun		: re vsrun

vrun		: $(NAME)
				valgrind ./$(NAME)

vsrun		: $(NAME)
				valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --log-file=valgrind.log ./$(NAME)
