DIRECTORIES					= \
								Types							\
								Utils							\
								Config							\
								Window							\
								Data							\
								FileParser						\
								Engine							\
								Error

COMPONENTS					= \
								Box

DIRECTORY_TYPES				= \
								Types.cpp

DIRECTORY_BOX				= \
								Box.cpp

DIRECTORY_CONFIG			= \
								Config.cpp

DIRECTORY_DATA				= \
								Data.cpp

DIRECTORY_WINDOW			= \
								WindowAccessors.cpp						\
								Window.cpp

DIRECTORY_FILEPARSER		= \
								FileParser.cpp

DIRECTORY_UTILS				= \
								UtilsColors.cpp					\
								UtilsOutputs.cpp				\
								Utils.cpp

DIRECTORY_ERROR				= \
								ErrorStatics.cpp				\
								Error.cpp

DIRECTORY_ENGINE			= \
								Data.cpp						\
								EngineInit.cpp					\
								Event.cpp						\
								Render.cpp						\
								Engine.cpp


OBJS						= \
								$(foreach dir, $(COMPONENTS), \
									$(addprefix ./output/, $(DIRECTORY_$(shell echo $(dir) | tr a-z A-Z):%.cpp=%.o) )\
								) \
								$(foreach dir, $(DIRECTORIES), \
									$(addprefix ./output/, $(DIRECTORY_$(shell echo $(dir) | tr a-z A-Z):%.cpp=%.o) )\
								) \
								main.o
