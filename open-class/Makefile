# Makefile для управления сборкой проекта через CMake

# Параметры по умолчанию
BUILD_DIR 	= build       # Каталог для файлов сборки
BUILD_TYPE 	= Debug       # Тип сборки: Debug или Release
LIB_TYPE 	= STATIC      # Тип библиотеки по умолчанию (STATIC или SHARED)

all: configure run

# Конфигурация CMake с выбранными параметрами
configure:
	cmake \
		-S . \
		-B $(BUILD_DIR) \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		-DLIB_TYPE=$(LIB_TYPE) \

# Запуск сборки
build_all: $(BUILD_DIR)/
	cmake --build $(BUILD_DIR)


# Запуск приложения
# 2 3 -> 134.7820152625846
# 0.25 0.35 -> 2.225281541949772
run: build_all
	clear
	echo "2 3" | ./build/main


# Очистка файлов сборки
clean:
	rm -rf $(BUILD_DIR)


# Создать график функции
plot:
	pip install matplotlib numpy
	python3 plot.py
