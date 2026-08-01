# C Piscine 42 — Madrid

![Norminette](https://img.shields.io/badge/norminette-OK-brightgreen)
![Score](https://img.shields.io/badge/score-100%2F100-brightgreen)
![Language](https://img.shields.io/badge/language-C-blue)
![Shell](https://img.shields.io/badge/shell-bash-lightgrey)

Todos los ejercicios de la piscina de C de 42, módulo a módulo, más los tres rushes de fin de semana.

Todo el código cumple **la Norma v4** (comprobado con `norminette`) y compila con `cc -Wall -Wextra -Werror` sin ningún warning.

---

## Notas

| Módulo | Tema | Nota |
|---|---|---|
| **Shell00** | Primeros comandos, permisos, `tar`, ficheros y directorios | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **Shell01** | Scripts en bash, variables de entorno, `find`, `grep`, `sed` | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C00** | `write`, bucles, combinaciones, primeros programas | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C01** | Punteros, paso por referencia, tablas de enteros | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C02** | Cadenas de caracteres: copia, comprobación, transformación | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C03** | Reimplementación de `strcmp`, `strcat`, `strstr`, `strlcat` | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C04** | `atoi`, `putnbr` y conversión entre bases numéricas | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C05** | Recursividad: factorial, potencia, Fibonacci, primos, 10 reinas | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C06** | `argc` / `argv`: argumentos de la línea de comandos | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C07** | Memoria dinámica: `malloc`, `strdup`, `split`, `convert_base` | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C08** | Headers, macros, `struct` y `typedef` | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C09** | Bibliotecas estáticas y `Makefile` | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C10** | La mayor locura de 42 | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C11** | Punteros a funciones y tablas de punteros a funciones | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C12** | Listas enlazadas | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **Rush00** | Dibujar rectángulos con distintos patrones de caracteres | ![116/100](https://img.shields.io/badge/116-100-blueviolet) |
| **Rush01** | Resolución de un puzzle por backtracking | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **Rush02** | Convertir números a letras a partir de un diccionario | ![106/100](https://img.shields.io/badge/106-100-blueviolet) |

<!-- Cuando subas C10 y C12, añade estas dos filas en su sitio:
| **C10** | Ficheros y file descriptors: `open`, `read`, `write`, `close` | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
| **C12** | Listas enlazadas | ![100/100](https://img.shields.io/badge/100-100-brightgreen) |
-->

Los rushes se hacen en grupos de tres en un fin de semana. Las notas por encima de 100 son de los bonus.

---

## Estructura

```
C_Piscine42/
├── Shell00/ex00 … ex09      scripts y ficheros sueltos
├── Shell01/ex01 … ex08      scripts .sh
├── C00/ … C11/              un directorio exXX por ejercicio
│   └── exXX/nombre_funcion.c
├── Rush00/ex00              ft_putchar.c, rush00.c … rush04.c, main.c
├── Rush01/ex00              main.c, solve.c, print.c
└── Rush02/ex00              Makefile, rush02.h, *.c, *.dict
```

Cada ejercicio contiene solo los archivos que pide su enunciado. Los `main()` de prueba de las funciones van comentados, tal y como exige la piscina.

---

## Cómo compilar y probar

Una función suelta (descomenta antes su `main` de prueba):

```bash
cd C03/ex00
cc -Wall -Wextra -Werror ft_strcmp.c
./a.out
```

Los ejercicios que son programas completos:

```bash
cd C11/ex05 && make && ./do-op 42 "+" 21
cd Rush02/ex00 && make && ./rush-02 42
cd Rush00/ex00 && cc -Wall -Wextra -Werror *.c && ./a.out 5 3
```

Comprobar la Norma:

```bash
norminette -R CheckForbiddenSourceHeader $(find . -name "*.c" -o -name "*.h")
```

---

## La Norma, en corto

Las reglas que condicionan todo el código de este repositorio:

- Máximo 25 líneas por función, 5 funciones por archivo
- Máximo 5 variables por función y 4 parámetros
- Prohibidos `for`, `do…while`, `switch`, `goto`, los operadores ternarios y los VLA: solo `while`
- Declaración e inicialización en líneas separadas
- Tabulaciones reales, 80 columnas por línea, una instrucción por línea
- `return` siempre entre paréntesis
- Cabecera 42 en todos los `.c` y `.h`

---

## Aviso

Este repositorio es un registro de mi paso por la piscina. Si estás haciendo la tuya, **el valor está en pelearte tú con los ejercicios**, no en leer la solución: la defensa la haces tú delante de otra persona y ahí se nota. Úsalo como referencia cuando ya lo hayas intentado, para comparar enfoques.

---

**RelentlessYunn** · 42 Madrid
