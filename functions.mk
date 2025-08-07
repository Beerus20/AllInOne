define create_object
	$(CXX) $(CXXFLAGS) -c $(1) -o $(2)
endef

define create_executable
	$(CXX) $(1) -o $(2) `sdl2-config --cflags --libs`
endef

define create_rule
output/%.o: $(1)/%.cpp | output
	$(call create_object, $$<, $$@)

output/%.o: $(1)/src/%.cpp | output
	$(call create_object, $$<, $$@)
endef

define create_class
	@mkdir $(1)$(2)
	@mkdir $(1)$(2)/includes $(1)$(2)/src
	@touch $(1)$(2)/includes/$(2).hpp
	@touch $(1)$(2)/$(2).cpp
endef

$(foreach dir, $(DIRECTORIES), $(eval $(call create_rule, $(dir))))
$(foreach dir, $(COMPONENTS), $(eval $(call create_rule, ./Components/$(dir))))
