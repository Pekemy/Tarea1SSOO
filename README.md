# Tarea1SSOO
Sistemas operativos 2024 UBB
# README - Instrucciones para Compilar y Ejecutar

## Descripción
Este proyecto incluye el programa `carrera.cpp` que puedes compilar fácilmente usando un `Makefile`. Simula una carrera entre varios autos, utilizando programación concurrente para manejar múltiples hilos adicional el programa imprimirá el avance de cada auto y mostrará en qué posición termina cada uno.

## Requisitos
- g++ (GCC)
- Sistema operativo: Linux, macOS o Windows (con MinGW o Cygwin)
- Versión de C++: C++11
- Herramienta: make

## ¿Cómo compilar?
1. Abre una terminal y navega al directorio donde están los archivos.
2. Ejecuta:
   ```
   make
   ```
   Esto va a generar un ejecutable llamado `carrera`.

### Si no quieres usar `make`
Puedes compilarlo manualmente con:
```
g++ -std=c++11 -Wall -o carrera carrera.cpp
```

## ¿Cómo ejecutar el programa?
Después de compilar, solo necesitas correr el siguiente comando:
```
./carrera<metros><cantidad de autos>
```

## ¿Cómo limpiar los archivos generados?
Si quieres eliminar el ejecutable, corre:
```
make clean
```

## Notas finales
- Si estás en Debian/Ubuntu y no tienes las herramientas instaladas, puedes hacerlo con:
  ```
  sudo apt update && sudo apt install build-essential
  ```

