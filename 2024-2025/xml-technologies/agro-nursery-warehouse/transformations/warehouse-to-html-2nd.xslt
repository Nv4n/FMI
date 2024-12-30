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
            <body class="bg-gray-100 text-gray-800">
                <div class="container mx-auto p-4">
                    <h1 class="text-2xl font-bold mb-4">Списък на складовете</h1>
                    <xsl:apply-templates/>
                </div>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="warehouses">
        <div class="space-y-6">
            <div class="bg-white shadow rounded-lg p-6">
                <h2 class="text-xl font-semibold mb-2">Собственик</h2>
                <xsl:apply-templates select="owner"/>
            </div>
            <xsl:for-each select="warehouse">
                <div class="bg-white shadow rounded-lg p-6">
                    <h2 class="text-xl font-semibold mb-2">Склад</h2>
                    <xsl:apply-templates select="*"/>
                </div>
            </xsl:for-each>
        </div>
    </xsl:template>

    <xsl:template match="owner">
        <p class="text-gray-600">
            <strong>Име:</strong>
            <xsl:value-of select="name"/>
        </p>
        <xsl:apply-templates select="contact"/>
    </xsl:template>

    <xsl:template match="warehouse">
        <div class="space-y-4">
            <xsl:apply-templates select="products"/>
            <xsl:apply-templates select="contact"/>
            <xsl:apply-templates select="deliveries"/>
        </div>
    </xsl:template>

    <xsl:template match="products">
        <h3 class="text-lg font-semibold">Продукти</h3>
        <ul class="flex gap-1 list-disc list-inside m-2">
            <xsl:for-each select="product">
                <li class="border p-2">
                    <strong>Име:</strong>
                    <xsl:value-of select="@name"/>
                    <br/>
                    <strong>Марка:</strong>
                    <xsl:value-of select="@brand"/>
                    <br/>
                    <xsl:apply-templates select="info"/>
                </li>
            </xsl:for-each>
        </ul>
    </xsl:template>

    <xsl:template match="info">
        <p>
            <strong>Цена:</strong>
            <xsl:value-of select="price"/>
            <xsl:value-of select="price/@currency"/>
        </p>
        <p>
            <strong>Количество:</strong>
            <xsl:value-of select="quantity"/>
        </p>
        <p>
            <strong>Тегло:</strong>
            <xsl:value-of select="weight"/>
            <xsl:value-of select="weight/@unit"/>
        </p>
        <p>
            <strong>Тип:</strong>
            <xsl:value-of select="type"/>
        </p>
    </xsl:template>

    <xsl:template match="contact">
        <h3 class="text-lg font-semibold">Контакт</h3>
        <p>
            <strong>Локация:</strong>
            <xsl:value-of select="location/country"/>, <xsl:value-of select="location/city"/>,
            <xsl:value-of select="location/address"/>
        </p>
        <p>
            <strong>Email:</strong>
            <xsl:value-of select="email"/>
        </p>
        <p>
            <strong>Телефон:</strong>
            <xsl:value-of select="phone"/>
        </p>
    </xsl:template>

    <xsl:template match="deliveries">
        <h3 class="text-lg font-semibold">Доставки</h3>
        <ul class="list-disc list-inside">
            <xsl:for-each select="delivery">
                <li>
                    <strong>Статус:</strong>
                    <xsl:value-of select="@status"/>
                    <br/>
                    <strong>Цена:</strong>
                    <xsl:value-of select="@cost"/>
                    <br/>
                    <xsl:apply-templates select="products"/>
                    <xsl:apply-templates select="vendor"/>
                </li>
            </xsl:for-each>
        </ul>
    </xsl:template>

    <xsl:template match="vendor">
        <h4 class="text-md font-medium">Доставчик</h4>
        <p>
            <strong>Име:</strong>
            <xsl:value-of select="name"/>
        </p>
        <xsl:apply-templates select="contact"/>
    </xsl:template>
</xsl:stylesheet>
