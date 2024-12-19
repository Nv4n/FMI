# Домашно 2, Иван Петров, 3MI0700035

## Предметна област - Магазини за агро продукти
    Тази онтология в Protege OWL описва предметната област на селскостопанския магазин,
    като се структурира в три основни компонента: класове, релации и индивидуални елементи.

### Основни класове

- **Pest** (Вредители): насекоми, гъби и плевели.

- **Person** (Човек):
    - Хората са разделени на служители в магазин (**Employee** -> **StoreEmployee**, *работят* в някой **Магазин**), които включват конкретни роли като:
        - **Cashier** (Касиер)
        - **Manager** (Мениджър): *менажира* минимум 1 **Служител**
        - **WarehouseWorker** (Складов работник)
    - Различават се също по пол: **Male** (Мъж) и **Female** (Жена).

- **Product** (Продукт):
    Основна категория, обхващаща различни селскостопански продукти:

    - **Equipment** (Оборудване): Включва инструменти като лопати, ножици и системи за напояване.
    - **Fertilizer** (Торове): Течни, компост или с бавно освобождаване.
    - **Pesticide** (Пестициди): *бори се* с някакъв **Вредител**
        - Хербициди (**Herbicide**): *бори се* с някакъв **Плевел**
        - Фунгициди (**Fungicide**): *бори се* с някаква **Гъба**
        - Инсектициди (**Insecticide**): *бори се* с някакво **Насекомо**
    - **Seeds** (Семена): За цветя, плодове, зеленчуци, билки.
    - **Soil** (Почва): Глинеста, песъчлива, и други видове.

-   **ProductType** (Тип на продукта): 
    - Органичен (**Organic**)
    - Неорганичен (**Inorganic**)
    - Био (**Bio**)

- **Store** (Магазин): *продава* мин 1 **Продукта**
    Включва типове магазини:
    - Големи магазини (**BigStore**): *продава* минимум 3 **Продукта**
    - Биомагазини (**OrganicStore**): *продава* само **Био** или **Органичен** **Продукти**
    - Верига магазини (**StoreChain**): *свързано е* с поне 1 **Магазин**

![alt text](image-2.png)

### Релации (Object Properties)

- *combatsPest*: **Pesticide -> Pest** обратна на *eliminatedBy*
- *eliminatedBy*: **Pest -> Pesticide** обратна на *combatsPest*
- *isRelatedTo*: **owl:Thing -> owl:Thing**, Транзитивна и Симетрична релация
- *isSupplierOf*: **Store -> Store**, Транзитивна релация, която може да бъде получена при наличието на *isRelatedTo* релация
- *manages*: **Employee -> Employee**
- *recommendedForCrop*: **Fertilizer, Soil -> Seeds**
- *sells*: **Store -> Product** обратна на *sold_in*
- *sold_in*: **Product -> Store** обратна на *sells*
- *suitableForSoil*: **Seeds -> Soil**
- *worksIn*: **Employee -> Store**
- *worksWith*: **Employee -> Employee**, Симетрична релация

![alt text](image-1.png)

### Индивидуални елементи (Individuals)
    Примери за конкретни обекти:
- Вредители: 
    - Aphids
    - Whiteflies
- Продукти: 
    - BestSprinkle
    - Bio Apple
    - BioCherryTomatoes
    - Compost X
    - Loamy soil
    - NeemOil
    - Stainless_Steel_Shovel
    - 
- Магазини: 
    - HugeStore 
    - SuperBioStore    
    - TheAgroStore1    
    - TheAgroStore2    
    - TheAgroStore3    
- Почви:
    - LoamySoil
- Персонал:
    - GoodManager    
    - Gosho
    - Pena


![alt text](image.png)