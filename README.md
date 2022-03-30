# **Дослідження структури даних хеш-таблиця**

# **Завдання**
## Завдання 1
### Реалізувати функцію generateRandLong():
- Функція повинна генерувати та повертати випадкове велике число,
що буде використовуватись як унікальний ключ-ідентифікатор даних у
хеш-таблиці. Сигнатура функції: long long generateRandLong()

## Завдання 2
### Реалізувати статичну хеш-таблицю за методом ланцюжків:
- Створити структуру Data для зберігання різнотипних даних
відповідно до варіанту, вона буде використовуватись у якості значень
для хеш-таблиці. Реалізувати генерацію випадкових даних для полів структури у пустому конструкторі Data()

(Структура Джедай має наступні поля: ім'я, кількість падаванів, колір світлового
меча. Створити космічний корабель в якому можна швидко знайти джедая.)

- Створити структуру HashNode для зберігання ключа та значення
- Створити структуру LinkedList з підтримкою додавання елементів,
виділити її в окремі header та cpp файли
- Створити структуру HashTable, яка буде містити масив зв’язних
списків bucketsArray статичного розміру M = 10000, та реалізувати в ній
основні функції:
    - hash(key) – знайти хеш-функцію від ключа
    - insert(key, value) – додати значення під відповідним ключем (заміна
    у випадку існування ключа)
    - find(key) – знайти значення під відповідним ключем, функція
    повертає вказівник на знайдений елемент або nullptr
    - erase(key) – видалити значення під відповідним ключем
    - size() – знайти кількість елементів в хеш-таблиці

## Завдання 3
### Додати динамічне розширення хеш-таблиці:
- На кожному кроці обчислювати loadFactor (поточну завантаженість
таблиці) та змінювати розмір масиву bucketsArray в залежності від
maxLoadFactor (максимально можлива завантаженість таблиці)
- Початковий розмір масиву bucketsArray встановити невеликим, при
перевищенні значення maxLoadFactor динамічно збільшувати розмір
- При перевиділенні пам’яті для всіх елементів хеш-таблиці
необхідно обчислити нові позиції, відповідно до зміни хеш-функції

## Завдання 4
### Провести тестування хеш-таблиці:
- Використати декілька різних значень maxLoadFactor
(наприклад 9, 4 та 0.5), використати декілька різних хеш-функцій
- За допомогою вказаної нижче функції testHashTable() провести
тестування із замірами часу та обрати оптимальні хеш-функцію та
значення maxLoadFactor
- Дослідити використання готового бібліотечного рішення STL
unordered_map, порівняти отримані результати зі своїм рішенням

# **Додаткове завдання**
## Завдання 1
### Реалізувати ще одну хеш-таблицю за методом відкритої адресації:
- Реалізувати всі основні методи хеш-таблиці. Для вирішення колізій
використати один з методів відкритої адресації
- Провести тестування за допомогою функції testHashTable(),
використати різні хеш-функції та значення maxLoadFactor, порівняти
результати з хеш-таблицею за методом ланцюжків

## Завдання 2
### Розв’язати задачу “Пошук зразка в тексті”:
- Реалізувати алгоритм Рабіна-Карпа для знаходження зразка в тексті.
На вхід алгоритм приймає 2 строки: текст та зразок. На виході повертає
всі індекси входження зразка в текст
- Перевірити своє рішення на тестах в системі:
https://acmp.ru/index.asp?main=task&id_task=202