# 🎓 Universidad Rafael Urdaneta
## 📘 Asignatura: Programación II
### 👨‍🏫 Profesor: Ing. Victor Kneider

---

<div align="center">

# 🚀 **GIT HACKS - PRIMERA SEMANA**
### *Domina Git y GitHub como un Pro* ⚡

![Git Logo](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)

</div>

---

## 🎯 **OBJETIVO PRINCIPAL**

Aprender los comandos fundamentales de Git y las funcionalidades básicas de GitHub a través de ejercicios prácticos y divertidos. ¡No se trata de programar formalmente, sino de dominar las herramientas que usarás durante toda tu carrera!

---

## 🔽 **ANTES DE EMPEZAR: DESCARGA GIT**

### 📥 **Enlaces de descarga oficiales:**
- **Windows**: [https://git-scm.com/download/win](https://git-scm.com/download/win)
- **macOS**: [https://git-scm.com/download/mac](https://git-scm.com/download/mac)
- **Linux**: `sudo apt-get install git`

### ✅ **Verifica tu instalación:**
```bash
git --version
```

---

## 🏁 **HACK #1: Primera Configuración**
> **Objetivo**: Configura Git y crea tu primer repositorio

### 🔥 **PASO A PASO:**

#### **1. Configura tu identidad**
```bash
git config --global user.name "Tu Nombre Completo"
git config --global user.email "tu-email@ejemplo.com"
```

#### **2. Verifica la configuración**
```bash
git config --list
```

#### **3. Crea y entra a tu carpeta de proyecto**
```bash
mkdir git-practice-tu-apellido
cd git-practice-tu-apellido
```

#### **4. Inicializa tu repositorio**
```bash
git init
```

#### **5. Crea tu primer archivo C++**
```cpp
// hola_mundo.cpp
#include <iostream>
using namespace std;

int main() {
    cout << "¡Hola Mundo desde Git!" << endl;
    cout << "Mi nombre es: [Tu Nombre]" << endl;
    return 0;
}
```

### ✅ **Entregable**: Screenshot de la configuración de Git

---

## 🏁 **HACK #2: Mis Primeros Commits**
> **Objetivo**: Aprende el ciclo básico de Git

### 🔥 **PASO A PASO:**

#### **1. Verifica el estado**
```bash
git status
```

#### **2. Agrega tu archivo**
```bash
git add hola_mundo.cpp
```

#### **3. Haz tu primer commit**
```bash
git commit -m "feat: crear programa hola mundo inicial"
```

#### **4. Modifica el archivo agregando más líneas**
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "¡Hola Mundo desde Git!" << endl;
    cout << "Mi nombre es: [Tu Nombre]" << endl;
    cout << "Estoy aprendiendo Git en Programación II" << endl;
    cout << "Este es mi segundo commit!" << endl;
    return 0;
}
```

#### **5. Agrega y commitea los cambios**
```bash
git add hola_mundo.cpp
git commit -m "feat: agregar más mensajes al programa"
```

#### **6. Crea archivos adicionales y commitea cada uno**
```bash
# Crear archivo de comandos
echo "git init, git add, git commit, git status" > comandos-git.txt
git add comandos-git.txt
git commit -m "docs: agregar lista de comandos"

# Crear notas
echo "Git guarda el historial de cambios en commits" > notas.md
git add notas.md
git commit -m "docs: agregar notas de clase"
```

#### **7. Revisa tu historial**
```bash
git log --oneline
```

### ✅ **Entregable**: Screenshot del historial de commits

---

## 🏁 **HACK #3: ¡Ups! Necesito Revertir**
> **Objetivo**: Aprende a deshacer cambios

### 🔥 **PASO A PASO:**

#### **1. Simula un error (modifica mal el archivo sin commitear)**
Borra contenido de `hola_mundo.cpp`

#### **2. Restaura el archivo**
```bash
git switch -- hola_mundo.cpp
```

#### **3. Verifica que se restauró**
```bash
git status
```

#### **4. Ahora haz un commit "malo" a propósito**
Agrega líneas con errores al código y haz commit:
```bash
git add hola_mundo.cpp
git commit -m "commit malo que queremos deshacer"
```

#### **5. Deshaz el último commit**
```bash
git reset --soft HEAD~1  # Mantiene cambios
```
o
```bash
git reset --hard HEAD~1  # Elimina cambios
```

#### **6. Verifica que el commit desapareció**
```bash
git log --oneline
```

### ✅ **Entregable**: Screenshot mostrando antes y después de revertir

---

## 🏁 **HACK #4: Mi Primer Repo en GitHub**
> **Objetivo**: Conecta tu trabajo local con GitHub

### 🔥 **PASO A PASO:**

#### **1. Crea un repositorio en GitHub**
- Ve a github.com → New repository
- Nombre: `git-practice-tu-apellido`
- Público, sin README inicial

#### **2. Conecta tu repo local**
```bash
git remote add origin https://github.com/tu-usuario/git-practice-tu-apellido.git
```

#### **3. Sube tu código**
```bash
git push -u origin main
```

#### **4. Edita un archivo desde GitHub**
- Edita `hola_mundo.cpp` en la web
- Agrega un comentario
- Commit desde GitHub

#### **5. Descarga los cambios**
```bash
git pull origin main
```

#### **6. Practica el ciclo completo**
```bash
# Hacer cambios locales
git add .
git commit -m "actualizar archivos"
git push origin main
```

### ✅ **Entregable**: URL de tu repositorio en GitHub

---

## 🏁 **HACK #5: Trabajando con Branches**
> **Objetivo**: Aprende a crear y manejar ramas

### 🔥 **PASO A PASO:**

#### **1. Verifica tu rama actual**
```bash
git branch
```

#### **2. Crea y cambia a nueva rama**
```bash
git switch -c nueva-funcionalidad
```

#### **3. Crea un archivo en esta rama**
```cpp
// calculadora.cpp
#include <iostream>
using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int main() {
    cout << "5 + 3 = " << sumar(5, 3) << endl;
    return 0;
}
```

#### **4. Commitea en la nueva rama**
```bash
git add calculadora.cpp
git commit -m "feat: agregar calculadora básica"
```

#### **5. Cambia de vuelta a main**
```bash
git switch main
```
Observa que `calculadora.cpp` no está aquí.

#### **6. Haz merge de tu rama**
```bash
git merge nueva-funcionalidad
```

#### **7. Verifica que el merge funcionó**
```bash
ls
git log --oneline
```

### ✅ **Entregable**: Screenshot del historial con branches

---

## 🏁 **HACK #6: Limpieza de Ramas**
> **Objetivo**: Aprende a eliminar ramas y mantener tu repositorio limpio

### 🔥 **PASO A PASO:**

#### **1. Verifica todas tus ramas**
```bash
git branch -a
```

#### **2. Elimina la rama que ya fue mergeada**
```bash
git branch -d nueva-funcionalidad
```

#### **3. Crea una rama de experimento**
```bash
git switch -c experimento
echo "// Código experimental" > test.cpp
git add test.cpp
git commit -m "test: código experimental"
```

#### **4. Regresa a main**
```bash
git switch main
```

#### **5. Elimina la rama experimental (sin merge)**
```bash
git branch -D experimento
```
(Nota: `-D` fuerza la eliminación sin merge)

#### **6. Crea y limpia múltiples ramas**
Practica creando varias ramas:
```bash
# Crear varias ramas
git switch -c feature-1
git switch -c feature-2  
git switch -c temp-branch

# Regresar a main
git switch main

# Eliminar todas las ramas vacías
git branch -d feature-1 feature-2 temp-branch
```

#### **7. Verifica que solo queda main**
```bash
git branch
```

#### **8. Sube todo a GitHub**
```bash
git push origin main
```

### ✅ **Entregable**: Screenshot mostrando solo la rama main después de limpiar

---

## 🏁 **HACK #7: Clonar y Explorar**
> **Objetivo**: Aprende a trabajar con repositorios existentes

### 🔥 **PASO A PASO:**

#### **1. Clona un repositorio interesante**
```bash
cd ..
git clone https://github.com/nlohmann/json.git
cd json
```

#### **2. Explora el proyecto**
```bash
ls -la
git log --oneline -10
git remote -v
```

#### **3. Examina commits específicos**
```bash
git show [hash-de-commit]
```

#### **4. Regresa a tu proyecto**
```bash
cd ../git-practice-tu-apellido
```

#### **5. Documenta lo que aprendiste**
```bash
echo "# Repositorio Explorado
- Nombre: JSON for Modern C++
- URL: https://github.com/nlohmann/json
- Qué hace: Librería JSON para C++
- Commits interesantes: [lista algunos]" > repositorio-explorado.md

git add repositorio-explorado.md
git commit -m "docs: agregar análisis de repositorio explorado"
git push origin main
```

### ✅ **Entregable**: Screenshot del análisis del repositorio explorado

---

## 🏆 **HACK FINAL: Tu Repositorio de la Materia**
> **Objetivo**: Crea tu repositorio personal para Programación II con un README completamente creativo y estilizado

### 🔥 **PASO A PASO:**

#### **1. Crea tu repositorio de la materia**
```bash
# Crea una nueva carpeta para tu repositorio de la materia
mkdir programacion-2-tu-apellido
cd programacion-2-tu-apellido

# Inicializa el repositorio
git init
```

#### **2. Organiza tu repositorio como prefieras**
Crea la estructura que consideres más útil para organizar tu trabajo:
```bash
# Ejemplos de organización (¡elige la que prefieras!)
mkdir Clase1 Clase2 Clase3 Clase4 Clase5 Proyectos Documentacion
# O tal vez:
mkdir ejercicios proyectos apuntes recursos
# O cualquier otra estructura que te guste
```

#### **3. ¡CREA TU README DESDE CERO!**
**🎨 AQUÍ ES DONDE DEBES SER COMPLETAMENTE CREATIVO:**

- **NO uses plantillas prediseñadas**
- **Diseña tu propio estilo único**
- **Incluye lo que consideres importante para tu repositorio**
- **Usa tu creatividad al máximo**

#### **💡 Ideas para inspirarte (pero NO las copies):**
- Agrega tu información personal y académica
- Incluye badges, emojis, y elementos visuales
- Documenta tu progreso en la materia
- Muestra tus proyectos y ejercicios
- Agrega estadísticas de GitHub si quieres
- Incluye recursos que uses para estudiar
- ¡Lo que se te ocurra!

#### **4. Sube tu trabajo a GitHub**
```bash
# Conecta con GitHub
git remote add origin https://github.com/tu-usuario/programacion-2-tu-apellido.git

# Sube todo tu trabajo
git add .
git commit -m "feat: crear mi repositorio personal de Programación II"
git push -u origin main
```

#### **5. Haz tu repositorio público y atractivo**
- Ve a la configuración de tu repositorio en GitHub
- Hazlo público para que otros puedan verlo
- Configura topics/tags relevantes: `c++`, `programming`, `university`, `education`
- Agrega una descripción atractiva

### ✅ **Entregables**:
1. **URL de tu repositorio público en GitHub**
2. **Screenshot del README mostrando tu creatividad única**
3. **Evidencia de commits organizados**
4. **Explicación de por qué elegiste ese diseño para tu README**

---

## 🎯 **VERIFICACIÓN FINAL**

### 📋 **Tu repositorio de la materia debe contener:**
- ✅ **README.md completamente creativo y único** (sin plantillas)
- ✅ **Estructura organizada** que tenga sentido para ti
- ✅ **Información personal y académica** relevante
- ✅ **Elementos visuales atractivos** (badges, emojis, etc.)
- ✅ **Contenido útil** para tu aprendizaje en Programación II
- ✅ **Historial de commits** organizados y descriptivos
- ✅ **Repositorio público** en GitHub con descripción atractiva
- ✅ **Evidencia de creatividad** y personalización única

---

## 📚 **RECURSOS DE APOYO**

- [Git Cheat Sheet](https://education.github.com/git-cheat-sheet-education.pdf)
- [GitHub Docs](https://docs.github.com/)
- [Markdown Guide](https://www.markdownguide.org/)

### 🆘 **¿Necesitas ayuda?**
1. Relee los pasos cuidadosamente
2. Verifica cada comando antes del siguiente
3. Pregunta a un compañero
4. Consulta al profesor

---

<div align="center">

## 🎉 **¡A HACKEAR SE HA DICHO!** 
### *"El mejor momento para aprender Git fue hace un año. El segundo mejor momento es ahora."*

![Git Meme](https://img.shields.io/badge/Made%20with-❤️%20and%20Git-red?style=for-the-badge)

</div>

