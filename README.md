# test_task

Приложение на Qt Widgets: иконку перетаскивают мышью из каталога в графическую область,
при этом создаются объект на сцене, строка списка и таблица координат.

## Требования

- Qt 5.15.2 (Qt Widgets)
- qmake и компилятор MinGW 8.1 (32-bit)
- Doxygen — только для сборки документации

## Клонирование

```bash
git clone https://github.com/AntonNov/Test_task.git
cd Test_task
```

## Сборка и запуск

### В Qt Creator

1. Открыть `test_task.pro`.
2. Выбрать комплект **Desktop Qt 5.15.2 MinGW 32-bit**.
3. Собрать (Ctrl+B) и запустить (Ctrl+R).

### Из консоли

```bash
mkdir build
cd build
C:\Qt\5.15.2\mingw81_32\bin\qmake.exe ..\test_task.pro -spec win32-g++ CONFIG+=release
C:\Qt\Tools\mingw810_32\bin\mingw32-make.exe -j8
release\test_task.exe
```

Чтобы exe запускался без Qt Creator, разложить библиотеки рядом с ним:

```bash
C:\Qt\5.15.2\mingw81_32\bin\windeployqt.exe --release release\test_task.exe
```

## Документация Doxygen

Установить Doxygen (https://www.doxygen.nl/download.html или Qt Maintenance Tool →
Developer and Designer Tools → Doxygen), затем в корне проекта:

```bash
doxygen Doxyfile
```

Готовая справка — `docs/html/index.html`, открыть в браузере.
