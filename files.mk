DIRECTORIES			= \
						Box							\
						Color						\
						Container					\
						Data						\
						Draw						\
						Error						\
						Utils						\
						Window


DIRECTORY_BOX		= \
						accessors.cpp			\
						Box.cpp

DIRECTORY_COLOR		= \
						accessors.cpp			\
						Color.cpp

DIRECTORY_CONTAINER	= \
						accessors.cpp			\
						Container.cpp

DIRECTORY_DATA		= \
						Data.cpp

DIRECTORY_DRAW		= \
						form.cpp				\
						Draw.cpp

DIRECTORY_ERROR		= \
						Error.cpp

DIRECTORY_UTILS		= \
						Utils.cpp

DIRECTORY_WINDOW	= \
						utils.cpp			\
						accessors.cpp			\
						Window.cpp

OBJS				= \
						$(foreach dir, $(DIRECTORIES), \
							$(addprefix $(dir)/output/, $(DIRECTORY_$(shell echo $(dir) | tr a-z A-Z):%.cpp=%.o) )\
						) \
						main.o

INCLUDES			= \
						-I./Window