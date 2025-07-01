FILES				= \
						Color.accessors.cpp			\
						Color.cpp					\
						Event.cpp					\
						Image.cpp					\
						Load.cpp					\
						Data.accessors.cpp			\
						Data.cpp					\
						Container.event.cpp		\
						Container.accessors.cpp		\
						Container.cpp				\
						Error.cpp					\
						Draw.basics.cpp				\
						Draw.cpp					\
						Box.accessors.cpp			\
						Box.cpp						\
						Utilities.cpp				\
						Window.accessors.cpp		\
						Window.event.cpp			\
						Window.utils.cpp			\
						Window.cpp					\
						main.cpp

OBJS				= \
						$(FILES:%.cpp=output/%.o)

INCLUDES			= \
						-I./Window