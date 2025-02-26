## ENUM

- Същност
- Дефиниране
- Инициализация
- Пример

```cpp
enum Color{
    BLUE,
    RED,
    ORANGE
}
```

```cpp
enum Color{
    BLUE=5,
    RED,
    ORANGE
}
```

## Структури

- Идея и предназначение
- Синтаксис на дефиниране
- Използване
    - Деклариране и достъп
    - Структури и функции
    - Особености при работа с указатели

```cpp
struct Array{
    int* data,
    char name,
    unsigned length
    unsigned capacity,
}
```

- Масив - Непрекъсната последователност в паметта от един тип, с фиксиран размер

4 byte data, 1 byte name, 3 byte padding, 4byte unsigned,4byte unsigned
padding = till memory dividable of type size