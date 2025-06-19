FILES				= \
						Utilities.cpp		\
						Window.cpp			\
						main.cpp

OBJS				= \
						$(FILES:%.cpp=output/%.o)

INCLUDES			= \
						-I./Window