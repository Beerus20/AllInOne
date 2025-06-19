define create_object
	$(CXX) $(CXXFLAGS) -c $(1) -o $(2) $(sdl2-config --cflags --libs)
endef

define create_executable
	$(CXX) `sdl2-config --cflags --libs` $(1) -o $(2) $(sdl2-config --cflags --libs)
endef