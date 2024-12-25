<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/warehouses">
        Собственик:
        <xsl:value-of select="owner/name"/>
        <xsl:text>&#10;Контакт:</xsl:text>
        <xsl:apply-templates select="owner/contact"/>
        <xsl:text>&#10;====================&#10;</xsl:text>

        <xsl:for-each select="warehouse">
            <xsl:text>Склад&#10;</xsl:text>
            <xsl:apply-templates select="contact"/>
            <xsl:text>&#10;Продукти в склада:&#10;</xsl:text>
            <xsl:apply-templates select="products/product"/>
            <xsl:text>Доставки:&#10;</xsl:text>
            <xsl:apply-templates select="deliveries/delivery"/>
            <xsl:text>====================&#10;</xsl:text>
        </xsl:for-each>
    </xsl:template>

    <xsl:template match="contact">
        <xsl:text>Местоположение: </xsl:text>
        <xsl:value-of select="location/country"/>
        <xsl:text>, </xsl:text>
        <xsl:value-of select="location/city"/>
        <xsl:text>, </xsl:text>
        <xsl:value-of select="location/address"/>
        <xsl:text>&#10;Имейл: </xsl:text>
        <xsl:value-of select="email"/>
        <xsl:text>&#10;Телефон: </xsl:text>
        <xsl:value-of select="phone"/>
    </xsl:template>

    <xsl:template match="product">
        <xsl:text>- Продукт: </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text> (Марка: </xsl:text>
        <xsl:value-of select="@brand"/>
        <xsl:text>)&#10;</xsl:text>
        <xsl:text>  Цена: </xsl:text>
        <xsl:value-of select="info/price"/>
        <xsl:text> </xsl:text>
        <xsl:value-of select="info/price/@currency"/>
        <xsl:text>, Количество: </xsl:text>
        <xsl:value-of select="info/quantity"/>
        <xsl:text>, Тип: </xsl:text>
        <xsl:value-of select="info/type"/>
        <xsl:text>&#10;</xsl:text>
    </xsl:template>

    <xsl:template match="delivery">
        <xsl:text>- Доставка (Статус: </xsl:text>
        <xsl:value-of select="@status"/>
        <xsl:text>, Цена: </xsl:text>
        <xsl:value-of select="@cost"/>
        <xsl:text>):&#10;</xsl:text>
        <xsl:text>  Продукти:&#10;</xsl:text>
        <xsl:apply-templates select="products/product"/>
        <xsl:text>  Доставчик: </xsl:text>
        <xsl:value-of select="vendor/name"/>
        <xsl:text>&#10;</xsl:text>
    </xsl:template>
</xsl:stylesheet>
