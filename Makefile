CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Directories
DIRS = bst linked-list stack sorting searching array-operations

# Targets
EXAMPLES = \
	bst/bst \
	linked-list/linked_list \
	stack/stack_dynamic \
	stack/stack_static \
	sorting/bubble_sort \
	sorting/selection_sort \
	searching/binary_search \
	searching/linear_search \
	array-operations/insert_beginning \
	array-operations/insert_end

all: $(EXAMPLES)

# Implicit rule for building examples
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXAMPLES)

.PHONY: all clean
