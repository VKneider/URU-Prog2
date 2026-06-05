# 1. Instalar MSYS2 (MinGW) de forma silenciosa
echo "Instalando MSYS2..."
winget install MSYS2.MSYS2 --silent --accept-source-agreements --accept-package-agreements

# 2. Instalar Visual Studio Code de forma silenciosa
echo "Instalando Visual Studio Code..."
winget install Microsoft.VisualStudioCode --silent --accept-source-agreements --accept-package-agreements

# 3. Instalar SOLO el compilador GCC/G++ de MinGW (sin actualizar MSYS2 para ahorrar tiempo)
echo "Instalando compiladores MinGW (GCC/G++)..."
& "C:\msys64\usr\bin\bash.exe" -lc "pacman -S --needed --noconfirm mingw-w64-x86_64-toolchain"

# 4. Agregar MinGW al PATH del sistema
echo "Configurando variables de entorno..."
$targetPath = "C:\msys64\mingw64\bin"
$oldPath = [Environment]::GetEnvironmentVariable("Path", [EnvironmentVariableTarget]::Machine)

if ($oldPath -notlike "*$targetPath*") {
    [Environment]::SetEnvironmentVariable("Path", "$oldPath;$targetPath", [EnvironmentVariableTarget]::Machine)
    $env:Path += ";$targetPath"
    echo "PATH actualizado con éxito."
} else {
    echo "MinGW ya estaba en el PATH."
}

echo "¡Listo! Instalación rápida completada. Reinicia la terminal para usar 'gcc' o 'g++'."