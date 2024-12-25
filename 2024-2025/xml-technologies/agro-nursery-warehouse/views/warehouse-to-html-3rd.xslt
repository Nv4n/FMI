<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/">
        <html lang="bg">
            <head>
                <meta charset="UTF-8"/>
                <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
                <title>Складове</title>
                <script src="https://cdn.tailwindcss.com"/>
            </head>
            <body class="bg-gray-50 text-gray-700 font-sans">
                <header class="bg-blue-600 text-white p-4">
                    <h1 class="text-3xl font-bold">Складове и продукти</h1>
                </header>
                <main class="container mx-auto py-6">
                    <xsl:apply-templates/>
                </main>
                <footer class="bg-gray-800 text-white p-4 text-center">
                    <p>Система за управление на складове</p>
                </footer>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="warehouses">
        <section class="space-y-8">
            <div class="bg-gray-100 shadow-lg rounded-lg p-6">
                <h2 class="text-xl font-semibold mb-4">Данни за собственика</h2>
                <xsl:apply-templates select="owner"/>
            </div>
            <xsl:for-each select="warehouse">
                <article class="border-l-4 border-blue-500 bg-white shadow p-6">
                    <h3 class="text-lg font-bold text-blue-600 mb-2">Склад</h3>
                    <xsl:apply-templates select="*"/>
                </article>
            </xsl:for-each>
        </section>
    </xsl:template>

    <xsl:template match="owner">
        <p>
            <span class="font-semibold">Име:</span>
            <xsl:value-of select="name"/>
        </p>
        <xsl:apply-templates select="contact"/>
    </xsl:template>

    <xsl:template match="warehouse">
        <div class="grid grid-cols-1 md:grid-cols-2 gap-4">
            <xsl:apply-templates select="products"/>
            <xsl:apply-templates select="contact"/>
            <xsl:apply-templates select="deliveries"/>
        </div>
    </xsl:template>

    <xsl:template match="products">
        <section class="bg-gray-50 p-4 rounded-lg">
            <h4 class="font-semibold text-gray-800">Продукти</h4>
            <ul class="divide-y divide-gray-300">
                <xsl:for-each select="product">
                    <li class="py-2">
                        <span class="font-medium">Име:</span>
                        <xsl:value-of select="@name"/>
                        <br/>
                        <span class="font-medium">Марка:</span>
                        <xsl:value-of select="@brand"/>
                        <xsl:apply-templates select="info"/>
                    </li>
                </xsl:for-each>
            </ul>
        </section>
    </xsl:template>

    <xsl:template match="info">
        <div class="text-sm text-gray-600 mt-2">
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
        <section class="bg-blue-50 p-4 rounded-lg">
            <h4 class="font-semibold text-blue-700">Контакт</h4>
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
        <section class="bg-gray-100 p-4 rounded-lg">
            <h4 class="font-semibold text-gray-800">Доставки</h4>
            <div class="space-y-2">
                <xsl:for-each select="delivery">
                    <div class="border rounded p-3">
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
                    </div>
                </xsl:for-each>
            </div>
        </section>
    </xsl:template>

    <xsl:template match="vendor">
        <section class="bg-white p-4 rounded-lg">
            <h5 class="font-medium text-gray-700">Доставчик</h5>
            <p>
                <span class="font-semibold">Име:</span>
                <xsl:value-of select="name"/>
            </p>
            <xsl:apply-templates select="contact"/>
        </section>
    </xsl:template>
</xsl:stylesheet>
