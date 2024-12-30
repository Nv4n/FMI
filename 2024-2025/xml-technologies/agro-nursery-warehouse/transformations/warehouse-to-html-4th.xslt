<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/">
        <html lang="bg">
            <head>
                <meta charset="UTF-8"/>
                <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
                <title>Система за Складове</title>
                <script src="https://cdn.tailwindcss.com"/>
            </head>
            <body class="bg-gradient-to-r from-gray-100 to-gray-200 font-serif text-gray-900">
                <header class="bg-indigo-700 text-white py-4 shadow-md">
                    <div class="container mx-auto text-center">
                        <h1 class="text-4xl font-bold">Информация за Складове</h1>
                    </div>
                </header>
                <main class="container mx-auto py-8">
                    <xsl:apply-templates/>
                </main>
                <footer class="bg-gray-800 text-white py-4">
                    <div class="container mx-auto text-center">
                        <p class="text-sm">Информация за Складове</p>
                    </div>
                </footer>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="warehouses">
        <section class="grid grid-cols-1 gap-6 md:grid-cols-2 lg:grid-cols-3">
            <xsl:apply-templates select="owner"/>
            <xsl:for-each select="warehouse">
                <article class="bg-white shadow-md rounded-lg p-6 border border-gray-300">
                    <xsl:apply-templates select="*"/>
                </article>
            </xsl:for-each>
        </section>
    </xsl:template>

    <xsl:template match="owner">
        <div class="bg-yellow-100 rounded-lg p-4 mb-6">
            <h2 class="text-lg font-semibold text-yellow-800">Собственик на складове</h2>
            <p>
                <span class="font-semibold">Име:</span>
                <xsl:value-of select="name"/>
            </p>
            <xsl:apply-templates select="contact"/>
        </div>
    </xsl:template>

    <xsl:template match="warehouse">
        <div class="space-y-4">
            <xsl:apply-templates select="products"/>
            <xsl:apply-templates select="contact"/>
            <xsl:apply-templates select="deliveries"/>
        </div>
    </xsl:template>

    <xsl:template match="products">
        <section class="bg-green-50 p-4 rounded-lg">
            <h3 class="font-semibold text-green-700">Продукти</h3>
            <ul class="divide-y divide-green-300">
                <xsl:for-each select="product">
                    <li class="py-2">
                        <div class="font-medium">Име:
                            <xsl:value-of select="@name"/>
                        </div>
                        <div class="text-sm text-gray-600">Марка:
                            <xsl:value-of select="@brand"/>
                        </div>
                        <xsl:apply-templates select="info"/>
                    </li>
                </xsl:for-each>
            </ul>
        </section>
    </xsl:template>

    <xsl:template match="info">
        <div class="text-gray-700 mt-2">
            <p>
                <span class="font-semibold">Цена:</span>
                <xsl:value-of select="price"/>
                <xsl:value-of select="price/@currency"/>
            </p>
            <p>
                <span class="font-semibold">Количество:</span>
                <xsl:value-of select="quantity"/>
            </p>
            <p>
                <span class="font-semibold">Тегло:</span>
                <xsl:value-of select="weight"/>
                <xsl:value-of select="weight/@unit"/>
            </p>
            <p>
                <span class="font-semibold">Тип:</span>
                <xsl:value-of select="type"/>
            </p>
        </div>
    </xsl:template>

    <xsl:template match="contact">
        <section class="bg-indigo-50 p-4 rounded-lg">
            <h3 class="font-semibold text-indigo-700">Контактна информация</h3>
            <p>
                <span class="font-semibold">Локация:</span>
                <xsl:value-of select="location/country"/>, <xsl:value-of select="location/city"/>,
                <xsl:value-of select="location/address"/>
            </p>
            <p>
                <span class="font-semibold">Email:</span>
                <xsl:value-of select="email"/>
            </p>
            <p>
                <span class="font-semibold">Телефон:</span>
                <xsl:value-of select="phone"/>
            </p>
        </section>
    </xsl:template>

    <xsl:template match="deliveries">
        <section class="bg-blue-50 p-4 rounded-lg">
            <h3 class="font-semibold text-blue-700">Доставки</h3>
            <ul class="space-y-3">
                <xsl:for-each select="delivery">
                    <li class="p-3 bg-white shadow rounded-lg border border-gray-300">
                        <p>
                            <span class="font-semibold">Статус:</span>
                            <xsl:value-of select="@status"/>
                        </p>
                        <p>
                            <span class="font-semibold">Цена:</span>
                            <xsl:value-of select="@cost"/>
                        </p>
                        <xsl:apply-templates select="products"/>
                        <xsl:apply-templates select="vendor"/>
                    </li>
                </xsl:for-each>
            </ul>
        </section>
    </xsl:template>

    <xsl:template match="vendor">
        <div class="bg-purple-50 p-4 rounded-lg">
            <h4 class="font-semibold text-purple-700">Доставчик</h4>
            <p>
                <span class="font-semibold">Име:</span>
                <xsl:value-of select="name"/>
            </p>
            <xsl:apply-templates select="contact"/>
        </div>
    </xsl:template>
</xsl:stylesheet>
