# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AllInOne Team                              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13                             #+#    #+#              #
#    Updated: 2026/01/13                            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                                   COLORS                                     #
# ============================================================================ #

RESET		= \033[0m
BOLD		= \033[1m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
MAGENTA		= \033[35m
CYAN		= \033[36m

# ============================================================================ #
#                                   PROJECT                                    #
# ============================================================================ #

NAME		= allinone
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17
INCLUDES	= -I./include

# Détection automatique des bibliothèques disponibles
LIBS		= -lpthread -ldl

# Vérification SDL2
ifneq ($(shell pkg-config --exists sdl2 && echo yes),)
    LIBS += -lSDL2
    ifneq ($(shell pkg-config --exists SDL2_image && echo yes),)
        LIBS += -lSDL2_image
    endif
    ifneq ($(shell pkg-config --exists SDL2_ttf && echo yes),)
        LIBS += -lSDL2_ttf
    endif
endif

# Vérification OpenGL
ifneq ($(shell pkg-config --exists gl && echo yes),)
    LIBS += -lGL
endif

# Debug flags
DEBUG		= -g3 -fsanitize=address
RELEASE		= -O3 -DNDEBUG

# ============================================================================ #
#                                   SOURCES                                    #
# ============================================================================ #

SRC_DIR		= src
OBJ_DIR		= obj

# Core sources
CORE_SRC	= $(SRC_DIR)/core/Application.cpp \
			  $(SRC_DIR)/core/Config.cpp

# Data sources
DATA_SRC	= $(SRC_DIR)/data/Data.cpp \
			  $(SRC_DIR)/data/Data.method.cpp

# Event sources
EVENT_SRC	= $(SRC_DIR)/events/EventManager.cpp

# Plugin sources
PLUGIN_SRC	= $(SRC_DIR)/plugins/PluginManager.cpp

# Resource sources
RES_SRC		= $(SRC_DIR)/resources/ResourceManager.cpp \
			  $(SRC_DIR)/resources/Texture.cpp \
			  $(SRC_DIR)/resources/Font.cpp

# Utils sources
UTILS_SRC	= $(SRC_DIR)/utils/Logger.cpp

# UI sources
UI_SRC		= $(SRC_DIR)/ui/Button.cpp \
			  $(SRC_DIR)/ui/UISystem.cpp \
			  $(SRC_DIR)/ui/Window.cpp

# Backend sources
BACKEND_SRC	= $(SRC_DIR)/backends/SDLRenderer.cpp \
			  $(SRC_DIR)/backends/OpenGLRenderer.cpp \
			  $(SRC_DIR)/backends/MinilibXRenderer.cpp \
			  $(SRC_DIR)/backends/VulkanRenderer.cpp

# Main source
MAIN_SRC	= $(SRC_DIR)/main.cpp

# All sources
SRCS		= $(CORE_SRC) $(EVENT_SRC) $(PLUGIN_SRC) $(RES_SRC) $(UTILS_SRC) $(DATA_SRC) \
			  $(UI_SRC) $(BACKEND_SRC) $(MAIN_SRC)

# Objects
OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

# ============================================================================ #
#                                   PLUGINS                                    #
# ============================================================================ #

PLUGIN_DIR		= plugins
PLUGIN_TARGETS	= $(PLUGIN_DIR)/image-viewer/ImageViewerPlugin.so \
				  $(PLUGIN_DIR)/terminal/TerminalPlugin.so \
				  $(PLUGIN_DIR)/video-player/VideoPlayerPlugin.so

# ============================================================================ #
#                                   RULES                                      #
# ============================================================================ #

.PHONY: all clean fclean re debug release plugins help

all: $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Build complete!$(RESET)"

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)Linking executable...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling: $(YELLOW)$<$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Include dependencies
-include $(DEPS)

# ============================================================================ #
#                                   PLUGINS                                    #
# ============================================================================ #

plugins: $(PLUGIN_TARGETS)
	@echo "$(GREEN)$(BOLD)✓ All plugins built!$(RESET)"

$(PLUGIN_DIR)/image-viewer/ImageViewerPlugin.so: $(PLUGIN_DIR)/image-viewer/ImageViewerPlugin.cpp
	@echo "$(MAGENTA)Building plugin: $(YELLOW)ImageViewer$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -shared -fPIC $< -o $@

$(PLUGIN_DIR)/terminal/TerminalPlugin.so: $(PLUGIN_DIR)/terminal/TerminalPlugin.cpp
	@echo "$(MAGENTA)Building plugin: $(YELLOW)Terminal$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -shared -fPIC $< -o $@

$(PLUGIN_DIR)/video-player/VideoPlayerPlugin.so: $(PLUGIN_DIR)/video-player/VideoPlayerPlugin.cpp
	@echo "$(MAGENTA)Building plugin: $(YELLOW)VideoPlayer$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -shared -fPIC $< -o $@

# ============================================================================ #
#                                   CLEANING                                   #
# ============================================================================ #

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(PLUGIN_TARGETS)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Everything cleaned$(RESET)"

re: fclean all

# ============================================================================ #
#                                   BUILD MODES                                #
# ============================================================================ #

debug: CXXFLAGS += $(DEBUG)
debug: fclean $(NAME)
	@echo "$(YELLOW)$(BOLD)⚠ Debug build complete with sanitizers$(RESET)"

release: CXXFLAGS += $(RELEASE)
release: fclean $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Release build complete (optimized)$(RESET)"

# ============================================================================ #
#                                   UTILITY                                    #
# ============================================================================ #

help:
	@echo "$(CYAN)$(BOLD)AllInOne Makefile Help$(RESET)"
	@echo ""
	@echo "$(YELLOW)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)      - Build the main executable (default)"
	@echo "  $(GREEN)plugins$(RESET)  - Build all plugins (.so files)"
	@echo "  $(GREEN)clean$(RESET)    - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)   - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)       - Rebuild everything from scratch"
	@echo "  $(GREEN)debug$(RESET)    - Build with debug flags and sanitizers"
	@echo "  $(GREEN)release$(RESET)  - Build optimized release version"
	@echo "  $(GREEN)help$(RESET)     - Show this help message"
	@echo ""
	@echo "$(YELLOW)Examples:$(RESET)"
	@echo "  make              # Build the project"
	@echo "  make plugins      # Build all plugins"
	@echo "  make debug        # Build with debug symbols"
	@echo "  make release      # Build optimized version"

run: $(NAME)
	@echo "$(CYAN)$(BOLD)Running $(NAME)...$(RESET)"
	@./$(NAME)

vrun: $(NAME)
	@echo "$(CYAN)$(BOLD)Running $(NAME) with Valgrind...$(RESET)"
	@valgrind --leak-check=full --track-origins=yes --suppressions=valgrind-suppress.txt ./$(NAME)

.PHONY: run