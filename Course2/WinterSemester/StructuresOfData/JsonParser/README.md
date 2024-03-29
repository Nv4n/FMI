![diagram](JsonParser ClassDiagram.png)

# Json Parser

## Четене

- JsonParser::readCmdLine() чете командата

### Валидация

- CommandLineValidator::validate() валидира:
    - Подава ни се непразен ред
    - Командата да започва с json-parser
    - Файла е от тип .json
    - Имаме валидна команда
    - Подадения път/Ключ (и в случай на команда *-change* дали данните за промяна и типа на *-change* са верни)
    - Достигаме края на командния ред

- При невалидна стойност връщаме грешка и какво е довело до грешката
- Всички валидни стойности се записват в CommandInterpreter

### Констроиране на JsonTree

- Деструктуриране на предишното JsonTree
- Конструиране на Node-ове
    - Четене на ред във файла
    - Интерпретиране на реда до *ключ* и *стойност*
    - Намиране типа на Node-а ( Array, Object, Value)
    - Array и Object се конструират рекурсивно викайки JsonParser::buildNodes
    - Задаване на *ключ* и *стойност* на Node-а
    - Връщане на грешка при невалидни данни
    - Проверка дали следващия ни ред е последен (се състои само от този символ **'}'**)
    - Ако не, продължаваме със създаването на следващия Node

---

## Търсене по ключ

- Вземаме от интерпретатора ключа за търсене
- Обхождане и запазване на всички Node-ове с този *ключ* във vector<JsonNode*>
- Ако няма такива Node-ове връщаме грешка
- В противен случай даваме 3 опции
    - Принтиране на всички Node-ове
    - Принтиране на определен индекс
    - И запазване на резултата в **find.txt**

---

## Промяна на Node по път

- Интерпретиране на *path* и запазването на *ключове и индекси* във vector
- Обхождане на дървото по подаден път (възможни опции са ключове или индекс, ако сме в масив)
- При намерен такъв **Node** зачистваме всички данни във него
- Интерпретация на новата стойност по Json формата
- Конструиране на Node-а с новата стойност

---

## Създаване на нов Node по път

- Интерпретиране на *path* и запазването на *ключове и индекси* във vector
- Обхождане на дървото по подаден път (възможни опции са ключове или индекс, ако сме в масив)
- Проверка дали е празен дадения път
- интерпретация на стойността за новия Node
- Добавяне на последния ключ от пътя към интерпретация
- Създаване на новия Node

---

### Бъгове, оправени в по-нова версия

- Лимитиране за промяна само на **VALUE** Node-ове
- Грешна интерпретация на **VALUE** тип данни за нова стойност на Node-а

---

## Запазване нa променения JsonTree

- Минаване по всички Node-ове
- Викане на интерпретатора на Node-ове JsonParser::nodeToString
- Запазване на всички интерпретации във формата на .json