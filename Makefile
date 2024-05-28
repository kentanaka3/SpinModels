all:

compile:
	@echo "Compiling..."
	cmake -B build -S . && cmake --build build

run: compile
	@echo "Running..."
	./build/main.x

clean:
	@echo "Cleaning..."
	rm -rf build
