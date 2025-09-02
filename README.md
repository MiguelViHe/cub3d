

# Cub3D

**Cub3D** es un juego 3D simple estilo *Wolfenstein 3D*, desarrollado en C usando la librería gráfica MiniLibX de Codam (MLX42). Renderiza un mundo 3D en tiempo real a partir de un mapa 2D utilizando técnicas de raycasting.

Esta versión nace de la versión que mi compañero Daniel Palacios y yo mismo entregamos como parte del Common core del campus de programación de 42 Madrid y esta en desarrollo, En ella iré añadiendo nuevas funcionalidades que no añadimos en la versión entregada. 

## 📦 Requisitos

Antes de compilar el proyecto, asegúrate de tener las siguientes dependencias instaladas en tu sistema:

```bash
sudo apt update && sudo apt install -y \
  build-essential \
  cmake \
  libxext-dev \
  libx11-dev \
  libbsd-dev \
  libxrandr-dev \
  libxi-dev \
  libgl1-mesa-dev \
  libglfw3 \
  libglfw3-dev

```

> 💡 *Nota*: Estas dependencias son necesarias para compilar y ejecutar la librería MiniLibX (MLX) en Linux.

---

## 🚀 Instalación

Clona este repositorio **recursivamente** para incluir los submódulos necesarios (como MLX):

```bash
git clone --recurse-submodules git@github.com:MiguelViHe/42-Cub3d.git
cd 42-Cub3d
make or make bonus
or
make dmap or make bmap -> para compilar y ejecutar el primer mapa; dmap -> default; bmap -> bonus
```

> Si ya habías clonado el repositorio sin `--recurse-submodules`, puedes correr esto para arreglarlo:
>
> ```bash
> git submodule update --init --recursive
> ```

---

## 🕹️ Cómo jugar

Una vez compilado, ejecuta el juego así:

```bash
./cub3d ./default/assets/maps/scene_1.cub
or
./cub3d_bonus ./bonus/assets/maps/scene_1.cub
```

* Usa las teclas A, S, D y W para desplazarte por el mapa renderizado en 3D.
* Usa las las flechas izquiera y derecha para rotar sobre el mapa, también puedes usar el ratón.
* Usa la tecla E para abrir y cerrar puertas.
* Usa la tecla M para ocultar y mostrar el minimapa.
* Manten pulsada la tecla shift para correr.
---

## 🛠️ Tecnologías

* **C** (lenguaje principal)
* **MiniLibX Codam (MLX42)** (para renderizado gráfico)
* **Raycasting** (para generar el efecto 3D)
* **Makefile** (para automatizar la compilación)
---

