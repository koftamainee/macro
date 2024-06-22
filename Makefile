# Определение переменной для компилятора
CC := gcc

# Определение операционной системы
ifeq ($(OS), Windows_NT)
    # Windows
    TARGET = build\macro.exe
    CLANG := $(shell where clang 2>NUL)
    RM = del /Q
else
    # Linux
    TARGET = build/macro
    CLANG := $(shell which clang > /dev/null 2>&1 && echo 1 || echo 0)
    RM = rm -rf
endif

# Если Clang установлен, использовать его
ifneq ($(CLANG),)
    CC := clang
endif

SRC = src/macro.c

all: macro

macro: $(SRC)
	@echo "Compiling with $(CC)..."
	$(CC) -o $(TARGET) $(SRC)
	@echo "Done."

run: macro
	@echo
	@echo "Application starting..."
	$(TARGET)

clean:
	$(RM) $(TARGET)
	@echo "Done."
