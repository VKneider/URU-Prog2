# Ejercicio Práctico - Registro Simple de Notas

## Objetivo
Crear un programa que permita guardar y leer notas de estudiantes en un archivo, aplicando los conceptos básicos de manejo de archivos en C++.

## Descripción
Desarrollar un programa que permita:
1. Guardar notas de estudiantes en un archivo de texto
2. Leer y mostrar las notas guardadas
3. Calcular el promedio de las notas

## Requerimientos

### Funcionalidades Básicas
1. Crear un menú con 3 opciones:
   - Agregar nota de estudiante
   - Ver todas las notas
   - Calcular promedio

### Datos a Guardar
Por cada estudiante almacenar:
- Nombre (máximo 30 caracteres)
- Nota (número del 1 al 20)

### Formato del Archivo
- Usar archivo de texto (.txt)
- Cada línea debe contener: nombre,nota
- Ejemplo: 
  ```
  Juan,15
  Maria,18
  Pedro,12
  ```

## Consideraciones
- Validar que la nota esté entre 1 y 20
- Mostrar mensajes claros al usuario
- Manejar errores básicos de archivo (no existe, no se puede abrir)

## Ejemplo de Uso
```
=== Registro de Notas ===
1. Agregar nota
2. Ver notas
3. Calcular promedio
4. Salir
Elija una opción: _
```

## Tiempo Estimado
- 30 minutos

## Conceptos a Aplicar
- Manejo básico de archivos de texto
- Lectura y escritura de archivos
- Estructuras de control
- Validación simple de datos 