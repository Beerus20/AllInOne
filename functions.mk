define create_object
	$(CXX) $(CXXFLAGS) -c $(1) -o $(2)
endef

define create_executable
	$(CXX) $(1) -o $(2) `sdl2-config --cflags --libs`
endef

define create_rule
$(1)/output/%.o: $(1)/%.cpp | $(1)/output
	$(call create_object, $$<, $$@)

$(1)/output/%.o: $(1)/src/%.cpp | $(1)/output
	$(call create_object, $$<, $$@)
endef

$(foreach dir, $(DIRECTORIES), $(eval $(call create_rule, $(dir))))
