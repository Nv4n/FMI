Изтеглете архива и отворете директорията в IntelliJ Idea.

1. Инсталирайте библиотеките и файловете, необходими за работа на приложението:

        npm install

2. Стартирайте приложението:

        npm start

3. Отворете http://localhost:5173/ в уеб браузър
4. Отворете `scripts/kml.js`. Променете `createKmlDocument`, така
    че да връща KML документ генериран от обектите поставени на картата.
    Генерираният документ трябва да изглежда така:

        <?xml version="1.0" encoding="UTF-8"?>
        <!--Генериран на 2024-09-27T13:52:27.101Z-->
        <kml
            xmlns="http://www.opengis.net/kml/2.2"
            xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://www.opengis.net/kml/2.2 http://schemas.opengis.net/kml/2.2.0/ogckml22.xsd">
            <Folder>
                <Placemark id="placemark0">
                    <name>Метростанция Опълченска</name>
                    <Point>
                        <coordinates>23.312382, 42.699698</coordinates>
                    </Point>
                </Placemark>
                <Placemark id="placemark1">
                    <name>Метростанция Вардар</name>
                    <Point>
                        <coordinates>23.283892, 42.705958</coordinates>
                    </Point>
                </Placemark>
            </Folder>
        </kml>

5. За текущото време в ISO формат може да използвате `new Date().toISOString()`.
6. Ако има само един обект да не се добавя `Folder`, а `Placemark` да е
    директен наследник на `kml`
7. Изпълнете тестовете:

        npm test
