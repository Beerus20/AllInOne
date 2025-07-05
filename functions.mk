define create_rule
$(1)/output/%.o: $(1)/.cpp | $(1)/output
	$(call create_object, $$<, $$@)

$(1)/output/%.o: $(1)/src/.cpp | $(1)/output
	$(call create_object, $$<, $$@)

endef

# $(eval $(call create_rule, Box))
# $(eval $(call create_rule, Color))
# $(eval $(call create_rule, Container))
# $(eval $(call create_rule, Data))
# $(eval $(call create_rule, Draw))
# $(eval $(call create_rule, Error))
# $(eval $(call create_rule, Utils))
# $(eval $(call create_rule, Window))


define create_object
	$(CXX) $(CXXFLAGS) -c $(1) -o $(2)
endef

define create_executable
	$(CXX) $(1) -o $(2) `sdl2-config --cflags --libs`
endef