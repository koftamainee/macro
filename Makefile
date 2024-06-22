CC = clang

TARGET = build/macro
SRC = src/macro.c


macro: $(SRC)
	@echo "Compiling..."
	$(CC) -o $(TARGET) $(SRC)
	@echo "Done."


run: macro
	@echo
	@echo "Application starting..."
	./build/macro


clean:
	rm -rf $(TARGET)
	@echo "Done."