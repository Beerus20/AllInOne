FILES				= \
						Draw.cpp			\
						Box.accessors.cpp	\
						Box.cpp				\
						Utilities.cpp		\
						Window.cpp			\
						main.cpp

OBJS				= \
						$(FILES:%.cpp=output/%.o)

INCLUDES			= \
						-I./Window