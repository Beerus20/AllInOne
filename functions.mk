define create_object
	$(CXX) $(CXXFLAGS) -c $(1) -o $(2)
endef

define create_executable
	$(CXX) $(1) -o $(2)
endef