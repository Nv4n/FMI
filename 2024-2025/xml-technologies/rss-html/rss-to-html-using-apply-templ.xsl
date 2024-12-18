<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" indent="yes"/>
    <xsl:template match="/rss">
        <html>
            <xsl:if test="channel/language">
                <xsl:attribute name="lang">
                    <xsl:value-of select="channel/language"/>
                </xsl:attribute>
            </xsl:if>
            <head>
                <meta charset="UTF-8"/>
                <meta name="description">
                    <xsl:attribute name="content">
                        <xsl:value-of select="channel/description"/>
                    </xsl:attribute>
                </meta>
                <title>
                    <xsl:value-of select="channel/title"/>
                </title>

                <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"/>
                <style>
                    h1 {
                    text-align:center;
                    color: blue;
                    }
                </style>
            </head>
            <body>
                <header class="m-5">
                    <h1>
                        <a>
                            <xsl:attribute name="href">
                                <xsl:value-of select="channel/link"/>
                            </xsl:attribute>
                            <xsl:value-of select="channel/title"/>
                        </a>
                    </h1>
                </header>

                <main class="container">
                    <xsl:apply-templates select="channel/item"/>
                </main>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="item">
        <div class="row justify-content-center">
            <div class="col col-lg-6">
                <article class="card mb-3">
                    <div class="card-body">
                        <h2 class="card-title">
                            <xsl:value-of select="title"/>
                        </h2>

                        <span class="badge text-bg-secondary">
                            <xsl:value-of select="pubDate"/>
                        </span>
                        <xsl:apply-templates select="enclosure"/>
                        <p class="card-text">
                            <xsl:value-of select="description" disable-output-escaping="yes"/>
                        </p>
                    </div>
                    <div class="card-footer">
                        <a class="card-link" target="_blank">
                            <xsl:attribute name="href">
                                <xsl:value-of select="link"/>
                            </xsl:attribute>
                            Прочетете повече
                        </a>
                    </div>
                </article>
            </div>
        </div>
    </xsl:template>

    <xsl:template match="enclosure">
        <xsl:choose>
            <xsl:when test="starts-with(@type,'video/')">
                <video width="250"  class="float-start rounded m-3 block" alt="ENCLOSURE VIDEO" controls="true" loop="true"
                >
                    <source>
                        <xsl:attribute name="src">
                            <xsl:value-of select="@url"/>
                        </xsl:attribute>
                        <xsl:attribute name="type">
                            <xsl:value-of select="@type"/>
                        </xsl:attribute>
                    </source>

                </video>

            </xsl:when>
            <xsl:when test="starts-with(@type,'image/')">
                <img class="float-start rounded m-3" alt="ENCLOSURE IMAGE"
                >
                    <xsl:attribute name="src">
                        <xsl:value-of select="@url"/>
                    </xsl:attribute>
                </img>
            </xsl:when>
        </xsl:choose>
    </xsl:template>
</xsl:stylesheet>