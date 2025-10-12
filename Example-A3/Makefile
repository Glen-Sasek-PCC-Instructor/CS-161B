# Simple Makefile using g++

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Wfatal-errors -std=c++17

# Target and sources
TARGET = main
SRC = *.cpp

# Test files
TEST_INPUTS = $(wildcard test-*.txt)
TEST_OUTPUTS = $(patsubst test-%.txt,output-%.txt,$(TEST_INPUTS))
EXPECTED_OUTPUTS = $(patsubst test-%.txt,expected-%.txt,$(TEST_INPUTS))

# Default target
all: $(TARGET)

# Build program
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run tests
test: $(TARGET)
	@echo "=============================="
	@echo "Running all tests..."
	@echo "=============================="
	@if [ -z "$(TEST_INPUTS)" ]; then \
		echo "No test input files found (expected test-1.txt, test-2.txt, ...)"; \
	else \
		for t in $(TEST_INPUTS); do \
			n=$${t#test-}; \
			n=$${n%.txt}; \
			echo "→ Test $$n"; \
			./$(TARGET) < $$t > output-$$n.txt; \
			if [ -f expected-$$n.txt ]; then \
				if diff -q output-$$n.txt expected-$$n.txt > /dev/null; then \
					echo "✅  Passed"; \
				else \
					echo "❌  Failed"; \
					diff -u expected-$$n.txt output-$$n.txt || true; \
				fi; \
			else \
				echo "⚠️  No expected-$$n.txt found."; \
				cat output-$$n.txt;\
			fi; \
			echo; \
		done; \
	fi
	@echo "=============================="
	@echo "Testing complete."
	@echo "=============================="

# Clean up build and test outputs
clean:
	rm -f $(TARGET) output-*.txt
	@echo "�� Clean complete."

.PHONY: all test clean
