# SSI-P02
# Práctica 2: Cifrado Vigenère
## Cómo compilar y ejecutar el programa
> [!WARNING]
> Es necesario tener instalado **'make'** y **'cmake'**. Además de **'g++'** y **'gcc'**.
```bash
$ make clean
$ make build
$ ./build/bin/Vernam
```
ó
```bash
$ make reload
$ ./build/bin/Vernam
```
## Objetivo
Implementar el cifrado de Vigenère.

## Desarrollo
Implementa el cifrado y descifrado de **Vigenere** según la descripción que se incluye a continuación:
Se usará el alfabeto sin Ñ, con W y sin espacios, luego el módulo para las operaciones será 26.
El cifrado opera sobre bloques de letras, y la clave es una palabra o frase que se repite cuantas veces sea
necesario.

Si la clave tiene longitud m, entonces el texto se divide en bloques de longitud m y la clave se suma a cada
bloque, sumando letra a letra módulo 26, para producir el texto cifrado.
Dicho de otra forma, dada la clave k1 k2 ...km introducida por el usuario, la primera letra del texto original
introducido por el usuario se sustituye por otra que ocupa k1 posiciones más allá en el alfabeto, la segunda
por la que ocupa k2 posiciones más allá, y así sucesivamente.

## Ejemplo
- **Palabra clave:** Misión
- **Texto original:** Este mensaje se autodetruirá en cinco segundos.

<table>
    <tr>
        <td>Texto claro:</td>
        <td>ESTEME</td>
        <td>NSAJES</td>
        <td>EAUTOD</td>
        <td>ESTRUI</td>
        <td>RAENCI</td>
        <td>NCOSEG</td>
        <td>UNDOS</td>
    </tr>
    <tr>
        <td>Clave:</td>
        <td>MISION</td>
        <td>MISION</td>
        <td>MISION</td>
        <td>MISION</td>
        <td>MISION</td>
        <td>MISION</td>
        <td>MISION</td>
    </tr>
    <tr>
        <td>Texto cifrado:</td>
        <td>QALMAR</td>
        <td>ZASRSF</td>
        <td>QIMBCQ</td>
        <td>QALZIV</td>
        <td>DIWVQV</td>
        <td>ZKGAST</td>
        <td>GVVWG</td>
    </tr>   
</table>

**Pista:** Se puede usar el código ASCII y las funciones ord y char, teniendo en cuenta que las letras en mayúsculas se encuentran a partir de la posición 65.