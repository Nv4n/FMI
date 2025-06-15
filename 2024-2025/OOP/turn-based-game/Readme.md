# Примерна документация

```
src/
├── Unit.h / Unit.inl               # Базов абстрактен клас за всички единици
├── Armor.h / Armor.inl             # Клас за броня
├── Attack.h / Attack.inl           # Клас за атака
├── Faction.h / Faction.inl         # Клас за фракция (жива/немъртва)
├── Commander.h / Commander.inl     # Базов клас за главнокомандващи
├── UnitFactory.h / UnitFactory.inl # Фабрика за създаване на единици
├── Duel.h / Duel.inl               # Управление на дуелите
├── GameState.h / GameState.inl     # Игрово състояние (злато, победи и т.н.)
├── FileManager.h / FileManager.inl # Четене/запис на състояние от файл
└── main.cpp                        # Основно меню и стартиране
```

CONFIG
```
{
    "initial_gold": {
        "living": 5000,
        "undead": 5000
    },
    "unit_limit": {
        "living": 10,
        "undead": 10
    }
}
```