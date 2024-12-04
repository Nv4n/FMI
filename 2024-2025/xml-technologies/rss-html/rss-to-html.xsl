<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" indent="yes"/>
    <xsl:template match="/rss">
        <html>
            <xsl:attribute name="lang">
                <xsl:value-of select="channel/language"/>
            </xsl:attribute>
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
                    <xsl:for-each select="channel/item">
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
                                        <xsl:for-each select="enclosure">
                                            <img class="float-start rounded m-3" alt="Плакат на изложба"
                                            >
                                                <xsl:attribute name="src">
                                                    <xsl:value-of select="@url"/>
                                                </xsl:attribute>
                                            </img>
                                        </xsl:for-each>

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
                    </xsl:for-each>

                </main>
            </body>
        </html>
    </xsl:template>

</xsl:stylesheet>