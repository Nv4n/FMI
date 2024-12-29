<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/">
        <warehouses xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
                    xsi:noNamespaceSchemaLocation="../public/warehouses.xsd">
            <xsl:apply-templates select="warehouses"/>
        </warehouses>
    </xsl:template>

    <xsl:template match="warehouses">
        <xsl:element name="owner">
            <xsl:apply-templates select="owner"/>
        </xsl:element>
        <xsl:for-each select="warehouse[1]">
            <xsl:element name="warehouse">
                <products>
                    <xsl:apply-templates select="products/product[1]"/>
                </products>
                <contact>
                    <xsl:apply-templates select="contact"/>
                </contact>
                <xsl:if test="deliveries">
                    <deliveries>
                        <xsl:apply-templates select="deliveries/delivery[1]"/>
                    </deliveries>
                </xsl:if>
            </xsl:element>
        </xsl:for-each>
    </xsl:template>

    <xsl:template match="owner|vendor">
        <xsl:element name="name">
            <xsl:value-of select="name"/>
        </xsl:element>
        <xsl:element name="contact">
            <xsl:apply-templates select="contact"/>
        </xsl:element>
    </xsl:template>

    <xsl:template match="product">
        <product>
            <xsl:attribute name="name">
                <xsl:value-of select="@name"/>
            </xsl:attribute>
            <xsl:attribute name="brand">
                <xsl:value-of select="@brand"/>
            </xsl:attribute>
            <info>
                <xsl:apply-templates select="info"/>
            </info>
        </product>
    </xsl:template>

    <xsl:template match="info">
        <price>
            <xsl:attribute name="currency">
                <xsl:value-of select="price/@currency"/>
            </xsl:attribute>
            <xsl:value-of select="price"/>
        </price>
        <quantity>
            <xsl:value-of select="quantity"/>
        </quantity>
        <weight>
            <xsl:attribute name="unit">
                <xsl:value-of select="weight/@unit"/>
            </xsl:attribute>
            <xsl:value-of select="weight"/>
        </weight>
        <expiry_date>
            <xsl:value-of select="expiry_date"/>
        </expiry_date>
        <type>
            <xsl:value-of select="type"/>
        </type>
    </xsl:template>

    <xsl:template match="delivery">
        <delivery>
            <xsl:attribute name="status">
                <xsl:value-of select="@status"/>
            </xsl:attribute>
            <xsl:attribute name="cost">
                <xsl:value-of select="@cost"/>
            </xsl:attribute>
            <products>
                <xsl:apply-templates select="products/product[1]"/>
            </products>
            <vendor>
                <xsl:apply-templates select="vendor"/>
            </vendor>
        </delivery>
    </xsl:template>

    <xsl:template match="contact">
        <location>
            <country>
                <xsl:value-of select="location/country"/>
            </country>
            <city>
                <xsl:value-of select="location/city"/>
            </city>
            <address>
                <xsl:value-of select="location/address"/>
            </address>
        </location>
        <xsl:choose>
            <xsl:when test="email">
                <email>
                    <xsl:value-of select="email"/>
                </email>
            </xsl:when>
            <xsl:otherwise>
                <phone>
                    <xsl:value-of select="phone"/>
                </phone>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
</xsl:stylesheet>
