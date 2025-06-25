FILES				= \
						Data.cpp				\
						Container.cpp			\
						Error.cpp				\
						Draw.basics.cpp			\
						Draw.cpp				\
						Box.accessors.cpp		\
						Box.cpp					\
						Utilities.cpp			\
						Window.accessors.cpp	\
						Window.info.cpp			\
						Window.cpp				\
						main.cpp

OBJS				= \
						$(FILES:%.cpp=output/%.o)

INCLUDES			= \
						-I./Window