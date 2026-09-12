Este proyecto consiste en el modelado y renderizado 2D de la escena un consultorio o laboratorio médico moderno **C++**, **OpenGL** y **FreeGLUT**.

---

## 🖼️ Imagen referencial del proyecto

![Escena Referencial](<imagen referencial/referencia_final.jpeg>)

---

## 📌 Avance General Actual

Hasta el momento se tiene montada la estructura principal del consultorio usando figuras básicas y transformaciones simples:
![Escena Avance](<imagen referencial/referencia_final.jpeg>)

* **Escenario Base:**
  * Fondo azul para la pared y un bloque para el suelo.
  * Dos luces rectangulares en la parte superior.

* **Muebles:**
  * Escritorio blanco con sus dos cajoneras a los lados.
  * Armario alto a la izquierda.
  * Silla azul en el centro (asiento, respaldo y base).

* **Equipos:**
  * Pantalla grande en la pared para el electrocardiograma.
  * Monitor de la computadora sobre el escritorio.
  * Estante pequeño con un par de frascos encima.

## ⚙️ Requisitos e Instalación

Para compilar y ejecutar este proyecto correctamente en tu IDE (**Dev-C++**, **Code::Blocks** o **Visual Studio**), asegúrate de incluir los siguientes parámetros del enlazador (*linker*):

```text
-lfreeglut
-lopengl32
-lglu32