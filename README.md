# Department of Metaphysical Sciences (DMS) - Secure Terminal

## Project Overview
DMS Terminal is custom software developed in C using the Raylib library. Functionally, it is a secure environment for storing, editing, and cryptographically processing classified information. The program operates on its own file formats and features an independent text processing engine.

## Technical Mechanics & Features

### 1. Custom Text Engine
The program bypasses standard UI libraries. All text input and rendering are built from scratch:
* **UTF-8 Support:** Accurate processing of multi-byte characters (Cyrillic) and single-byte characters (Latin) during typing, deletion, and encryption.
* **Dynamic Word Wrap:** Automatic line breaking based on real-time calculation of individual character widths.
* **Cursor Mathematics:** Precise coordinate (X, Y) calculation for the text caret, accounting for line heights, spacing, and multi-line structures.
* **Text Navigation:** Navigating through the text is done ONLY using the keyboard arrow keys.
* **Limitations:** There is no text selection mechanic; therefore, when copying text, the entire text buffer is copied at once.

### 2. Secure File System
* **On-the-fly Obfuscation:** Upon saving to disk, files automatically undergo basic byte-level XOR encryption, rendering them unreadable to standard text editors (e.g., Notepad). Decryption occurs exclusively in RAM when loaded into the terminal.

### 3. Cryptographic Suite
Integrated multiple encryption algorithms that manipulate the text buffer directly:
* **DMS Enigma:** A complex 3-rotor mechanical cipher. It features a unique architecture that automatically detects the character's language and routes it through the appropriate rotor set (26-letter for English or 33-letter for Ukrainian), preserving original formatting (spaces, commas). Configured via a 3-digit PIN.
* **XOR Cipher:** Symmetric bitwise text encryption using a user-defined key.
* **Trithemius/Caesar Ciphers:** Progressive and static shift ciphers (supporting both addition and subtraction of the shift step).

### 4. Memory Management & Undo Stack
* **Ctrl+Z System:** Implemented a multi-level backup pipeline (Stack) using dynamic memory allocation (`cal













# Department of Metaphysical Sciences (DMS) - Secure Terminal

## Опис проєкту
DMS Terminal — це кастомне програмне забезпечення, розроблене на мові C з використанням бібліотеки Raylib. Програмно — це захищене середовище для зберігання, редагування та криптографічної обробки класифікованої інформації. Програма працює з власними форматами файлів та має незалежний рушій обробки тексту.

## Технічні механіки та особливості

### 1. Кастомний текстовий рушій (Custom Text Engine)
Програма не використовує стандартні UI-бібліотеки. Весь ввід тексту написаний з нуля:
* **Підтримка UTF-8:** Коректна обробка двобайтових символів (кирилиця) та однобайтових (латиниця) під час друку, видалення та шифрування.
* **Динамічне форматування:** Автоматичне перенесення рядків (Word Wrap) на основі прорахунку ширини кожного символу в реальному часі.
* **Математика курсора:** Точний розрахунок координат (X, Y) каретки з урахуванням висоти рядків, відступів та багаторядковості.
* **Переміщення текстом** Переміщення текстом відбувається ЛиШЕ за допомогою стрілочок на клавіатурі.
* **Недоліки** Немає можливості виділяти текст, тому при копіюванні тексту, текст копіюється весь. 

### 2. Захищена файлова система
* **On-the-fly Обфускація:** При збереженні на диск файли автоматично проходять базове XOR-шифрування на рівні байтів, що робить їх нечитабельними для стандартних текстових редакторів (Notepad тощо). Розшифрування відбувається виключно в оперативній пам'яті під час завантаження в термінал.

### 3. Криптографічний модуль (Cryptographic Suite)
Інтегровано декілька алгоритмів шифрування, що працюють безпосередньо з текстовим буфером:
* **DMS Enigma:** Складний механічний шифр із 3 роторами. Має унікальну архітектуру: автоматично визначає мову символу та пропускає його через відповідний набір роторів (26-літерний для англійської або 33-літерний для української), зберігаючи оригінальне форматування (пробіли, коми). Налаштовується через 3-значний PIN.
* **XOR Cipher:** Симетричне бітове шифрування тексту за допомогою користувацького ключа.
* **Trithemius/Caesar Ciphers:** Прогресивні та статичні шифри зсуву (з підтримкою як додавання, так і віднімання кроку).

### 4. Робота з пам'яттю та Стек скасування (Undo Stack)
* **Система Ctrl+Z:** Реалізовано багаторівневий конвеєр бекапів (Stack) за допомогою динамічного виділення пам'яті (`calloc`/`free`). Зберігає стани тексту перед криптографічними змінами або вставками.
* **Буфер обміну:** Пряма взаємодія з буфером обміну ОС (Ctrl+C / Ctrl+V) з безпечним розсуненням масивів пам'яті (`memmove`/`memcpy`) для уникнення переповнення буфера.

### 5. Адаптивний рендеринг інтерфейсу
* Використання `RenderTexture2D` (Віртуальне полотно) для малювання всього інтерфейсу.
* Автоматичне масштабування (Letterboxing) під будь-який розмір монітора або вікна без втрати пропорцій чи зміщення зон колізії для миші (`virtualMouse` math).
* Підтримка Fullscreen режиму.









Password for open  :   oJ9z1sMa41


Password for edit  :   0Yq3Bt7ge8
