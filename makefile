# compilador
CXX = g++

CXXFLAGS = -std=c++11 -Wall

# Ejecutable
TARGET = carrera

# Archivo fuente
SRCS = carrera.cpp

all: $(TARGET)

# Compilar el ejectuable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Limpiar archivos generados
clean:
	rm -f $(TARGET)
