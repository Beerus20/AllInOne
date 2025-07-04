DIRECTORIES			= \
						Box							\
						Color						\
						Data						\
						Draw						\
						Error						\
						Utils						\
						Window

OUTPUT_DIRECTORIES	= $(addsuffix /output,$(DIRECTORIES))

DIRECTORY_BOX		= \
						src/accessors.cpp			\
						Box.cpp

DIRECTORY_COLOR		= \
						src/accessors.cpp			\
						Color.cpp

DIRECTORY_DATA		= \
						Data.cpp

DIRECTORY_DRAW		= \
						src/form.cpp				\
						Draw.cpp

DIRECTORY_ERROR		= \
						Error.cpp

DIRECTORY_UTILS		= \
						Utils.cpp

DIRECTORY_WINDOW	= \
						src/utils.cpp			\
						src/accessors.cpp			\
						Window.cpp

FILES				= \
						$(addprefix Box/,$(DIRECTORY_BOX))			\
						$(addprefix Color/,$(DIRECTORY_COLOR))			\
						$(addprefix Data/,$(DIRECTORY_DATA))			\
						$(addprefix Error/,$(DIRECTORY_ERROR))			\
						$(addprefix Utils/,$(DIRECTORY_UTILS))			\
						$(addprefix Window/,$(DIRECTORY_WINDOW))			\
						main.cpp

OBJS				= \
						$(FILES:%.cpp=output/%.o)

INCLUDES			= \
						-I./Window