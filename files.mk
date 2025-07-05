DIRECTORIES			= \
						Box							\
						Color						\
						Container					\
						Data						\
						Draw						\
						Error						\
						Utils						\
						Window

OUTPUT_DIRECTORIES	= $(addsuffix /output,$(DIRECTORIES))

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
						$(addprefix Box/output/,$(DIRECTORY_BOX:%.cpp=%.o))				\
						$(addprefix Color/output/,$(DIRECTORY_COLOR:%.cpp=%.o))			\
						$(addprefix Container/output/,$(DIRECTORY_CONTAINER:%.cpp=%.o))	\
						$(addprefix Data/output/,$(DIRECTORY_DATA:%.cpp=%.o))			\
						$(addprefix Draw/output/,$(DIRECTORY_DRAW:%.cpp=%.o))			\
						$(addprefix Error/output/,$(DIRECTORY_ERROR:%.cpp=%.o))			\
						$(addprefix Utils/output/,$(DIRECTORY_UTILS:%.cpp=%.o))			\
						$(addprefix Window/output/,$(DIRECTORY_WINDOW:%.cpp=%.o))		\
						main.o


INCLUDES			= \
						-I./Window