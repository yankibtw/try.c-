# Makefile для управления сборкой проекта через CMake

# Параметры по умолчанию
BUILD_DIR 	= build       # Каталог для файлов сборки
BUILD_TYPE 	= Debug       # Тип сборки: Debug или Release
GENERATOR 	= Ninja       # Генератор сборки: Ninja или Unix Makefiles
LIB_TYPE 	= STATIC      # Тип библиотеки по умолчанию (STATIC или SHARED)
POINT_TYPE 	= short       # Тип точности для решения квадратного уравнения


all: configure build_all

# Конфигурация CMake с выбранными параметрами
configure:
	cmake \
		-S . \
		-B $(BUILD_DIR) \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		-DCMAKE_GENERATOR=$(GENERATOR) \
		-DLIB_TYPE=$(LIB_TYPE) \
		-DPOINTTYPE=$(POINT_TYPE)

# Запуск сборки
build_all: $(BUILD_DIR)/
	cmake --build $(BUILD_DIR)

# Очистка файлов сборки
clean:
	rm -rf $(BUILD_DIR)

# Команды для изменения параметров сборки
release:
	make BUILD_TYPE=Release all

debug:
	make BUILD_TYPE=Debug all

static:
	make LIB_TYPE=STATIC all

shared:
	make LIB_TYPE=SHARED all
