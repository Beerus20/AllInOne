define create_object
	$(CXX) $(CXXFLAGS) -c $(1) -o $(2) $(shell pkg-config --cflags --libs SDL2 SDL2_image)
endef

define create_executable
	$(CXX) $(1) -o $(2)
endef