<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/">
        <warehouses>
            <xsl:apply-templates select="warehouses"/>
        </warehouses>
    </xsl:template>

    <xsl:template match="warehouses">
        <xsl:element name="owner">
            <xsl:apply-templates select="owner"/>
        </xsl:element>
        <xsl:for-each select="warehouse">
            <xsl:element name="warehouse">
                <contact>
                    <xsl:apply-templates select="contact"/>
                </contact>
                <xsl:if test="deliveries">
                    <deliveries>
                        <xsl:apply-templates select="deliveries/delivery"/>
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

    <xsl:template match="delivery">
        <delivery>
            <xsl:attribute name="status">
                <xsl:value-of select="@status"/>
            </xsl:attribute>
            <xsl:attribute name="cost">
                <xsl:value-of select="@cost"/>
            </xsl:attribute>
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
        <xsl:if test="email">
            <email>
                <xsl:value-of select="email"/>
            </email>
        </xsl:if>

        <xsl:if test="phone">
            <phone>
                <xsl:value-of select="phone"/>
            </phone>
        </xsl:if>
    </xsl:template>
</xsl:stylesheet>
