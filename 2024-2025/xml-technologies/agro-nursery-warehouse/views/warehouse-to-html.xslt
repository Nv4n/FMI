<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/warehouses">
        <html lang="bg">
            <head>
                <meta charset="UTF-8"/>
                <meta
                        name="viewport"
                        content="width=device-width, initial-scale=1.0"
                />
                <script src="https://cdn.tailwindcss.com"/>
                <title>XML App</title>
            </head>
            <body>
                <xsl:apply-templates select="owner|vendor"/>
                <xsl:apply-templates select="warehouse"/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="warehouse">
        <div class="block w-fit rounded-lg p-4 shadow-sm shadow-indigo-100">
            <div class="mt-2">
                <p class="text-sm text-gray-500">Warehouse</p>
            </div>
            <xsl:apply-templates select="contact"/>
        </div>
        <div class="mt-8 grid gap-4 sm:grid-cols-2 lg:grid-cols-4">
            <xsl:apply-templates select="products/product"/>
        </div>
        <span class="relative flex justify-center">
            <div
                    class="absolute inset-x-0 top-1/2 h-px -translate-y-1/2 bg-transparent bg-gradient-to-r from-transparent via-gray-500 to-transparent opacity-75"
            />
            <span class="relative z-10 bg-white px-6">END OF PRODUCTS</span>
        </span>
        <xsl:apply-templates select="deliveries/delivery"/>
        <span class="relative flex justify-center">
            <div
                    class="absolute inset-x-0 top-1/2 h-px -translate-y-1/2 bg-transparent bg-gradient-to-r from-transparent via-gray-500 to-transparent opacity-75"
            />
            <span class="relative z-10 bg-white px-6">END OF WAREHOUSE</span>
        </span>
    </xsl:template>

    <xsl:template match="products/product">
        <div class="group relative block bg-gray-800">
            <div class="relative p-4 sm:p-6 lg:p-8">
                <p class="text-sm font-medium uppercase tracking-widest text-pink-500">
                    <xsl:value-of select="concat(@name,' x',info/quantity)"/>
                </p>

                <p class="text-xl font-bold text-white sm:text-2xl">
                    <xsl:value-of select="@brand"/>
                </p>

                <div class="mt-32 sm:mt-48 lg:mt-64">
                    <div
                            class="translate-y-8 transform opacity-0 transition-all group-hover:translate-y-0 group-hover:opacity-100"
                    >
                        <p class="text-sm text-white">
                            <xsl:value-of select="notes"/>
                        </p>
                        <xsl:apply-templates select="info"/>
                    </div>
                </div>
            </div>
        </div>
    </xsl:template>

    <xsl:template match="info">
        <div class="mt-6 flex items-center gap-2 text-xs">
            <div
                    class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2"
            >
                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"
                     fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round"
                     stroke-linejoin="round"
                     class="size-6 text-indigo-400">
                    <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                    <path d="M7.5 7.5m-1 0a1 1 0 1 0 2 0a1 1 0 1 0 -2 0"/>
                    <path d="M3 6v5.172a2 2 0 0 0 .586 1.414l7.71 7.71a2.41 2.41 0 0 0 3.408 0l5.592 -5.592a2.41 2.41 0 0 0 0 -3.408l-7.71 -7.71a2 2 0 0 0 -1.414 -.586h-5.172a3 3 0 0 0 -3 3z"/>
                </svg>

                <div class="mt-1.5 sm:mt-0">
                    <p class="text-pink-500">Price</p>

                    <p class="font-medium text-white">
                        <xsl:value-of select="concat(price,' ',price/@currency)"/>
                    </p>
                </div>
            </div>
            <div
                    class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2"
            >
                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"
                     fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round"
                     stroke-linejoin="round"
                     class="size-6 text-indigo-400">
                    <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                    <path d="M12 6m-3 0a3 3 0 1 0 6 0a3 3 0 1 0 -6 0"/>
                    <path d="M6.835 9h10.33a1 1 0 0 1 .984 .821l1.637 9a1 1 0 0 1 -.984 1.179h-13.604a1 1 0 0 1 -.984 -1.179l1.637 -9a1 1 0 0 1 .984 -.821z"/>
                </svg>

                <div class="mt-1.5 sm:mt-0">
                    <p class="text-pink-500">Weight</p>

                    <p class="font-medium text-white">
                        <xsl:value-of select="concat(weight,' ',weight/@unit)"/>
                    </p>
                </div>
            </div>
            <div
                    class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2"
            >
                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"
                     fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round"
                     stroke-linejoin="round"
                     class="size-6 text-indigo-400">
                    <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                    <path d="M10.5 21h-4.5a2 2 0 0 1 -2 -2v-12a2 2 0 0 1 2 -2h12a2 2 0 0 1 2 2v3"/>
                    <path d="M16 3v4"/>
                    <path d="M8 3v4"/>
                    <path d="M4 11h10"/>
                    <path d="M18 18m-4 0a4 4 0 1 0 8 0a4 4 0 1 0 -8 0"/>
                    <path d="M18 16.5v1.5l.5 .5"/>
                </svg>

                <div class="mt-1.5 sm:mt-0">
                    <p class="text-pink-500">Expire</p>

                    <p class="font-medium text-white">
                        <xsl:value-of select="expiry_date"/>
                    </p>
                </div>
            </div>
            <div
                    class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2"
            >
                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none"
                     stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"
                     class="size-6 text-indigo-400">
                    <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                    <path d="M10 16v-8h2.5a2.5 2.5 0 1 1 0 5h-2.5"/>
                    <path d="M12 12m-9 0a9 9 0 1 0 18 0a9 9 0 1 0 -18 0"/>
                </svg>

                <div class="mt-1.5 sm:mt-0">
                    <p class="text-pink-500">Type</p>

                    <p class="font-medium text-white">
                        <xsl:value-of select="type"/>
                    </p>
                </div>
            </div>

            <xsl:if test="fragile[.='true']">

                <div
                        class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2"
                >
                    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"
                         fill="currentColor"
                         class="size-6 text-indigo-400">
                        <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                        <path d="M11.236 2.066l-1.694 5.647l-.029 .123a1 1 0 0 0 .406 .978l2.764 1.974l-1.551 2.716a1 1 0 1 0 1.736 .992l2 -3.5l.052 -.105a1 1 0 0 0 -.339 -1.205l-2.918 -2.085l1.623 -5.41c3.641 1.074 6.714 6.497 6.714 11.892c0 4.59 -3.273 7.71 -8 7.917c-4.75 0 -8 -3.21 -8 -7.917c0 -5.654 3.372 -11.344 7.236 -12.017"/>
                    </svg>
                </div>
            </xsl:if>

        </div>
    </xsl:template>

    <xsl:template match="deliveries/delivery">
        <xsl:apply-templates select="owner|vendor"/>
        <div class="mt-8 grid gap-4 sm:grid-cols-2 lg:grid-cols-4">
            <xsl:apply-templates select="products/product"/>
        </div>
        <div class="flex gap-8 m-2">

            <p class="!text-base font-medium">
                <xsl:value-of select="concat('Total: ',@cost)"/>
            </p>

            <div class="flex justify-end">
                <span
                        class="inline-flex items-center justify-center rounded-full bg-indigo-100 px-2.5 py-0.5 text-indigo-700"
                >
                    <p class="whitespace-nowrap text-xs">
                        <xsl:value-of select="concat('Status: ',@status)"/>
                    </p>
                </span>
            </div>
        </div>
        <span class="relative flex justify-center">
            <div
                    class="absolute inset-x-0 top-1/2 h-px -translate-y-1/2 bg-transparent bg-gradient-to-r from-transparent via-gray-500 to-transparent opacity-75"
            />
            <span class="relative z-10 bg-white px-6">END OF DELIVERY</span>
        </span>
    </xsl:template>

    <xsl:template match="owner|vendor">
        <div class="block w-fit rounded-lg p-4 shadow-sm shadow-indigo-100">
            <div class="mt-2">
                <dl>
                    <xsl:choose>
                        <xsl:when test="self::owner">
                            <p class="text-sm text-gray-500">Owner</p>
                        </xsl:when>
                        <xsl:otherwise>
                            <p class="text-sm text-gray-500">Vendor</p>
                        </xsl:otherwise>
                    </xsl:choose>
                    <div>
                        <dt class="sr-only">Name</dt>
                        <dd class="font-medium">
                            <xsl:value-of select="name"/>
                        </dd>
                    </div>
                </dl>
                <xsl:apply-templates select="contact"/>
            </div>
        </div>
    </xsl:template>
    <xsl:template match="contact">
        <div class="mt-6 flex items-center gap-8 text-xs">
            <xsl:if test="email">
                <div
                        class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2"
                >
                    <svg
                            xmlns="http://www.w3.org/2000/svg"
                            width="24"
                            height="24"
                            viewBox="0 0 24 24"
                            fill="none"
                            stroke="currentColor"
                            stroke-width="2"
                            stroke-linecap="round"
                            stroke-linejoin="round"
                            class="size-6 text-indigo-700"
                    >
                        <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                        <path
                                d="M3 7a2 2 0 0 1 2 -2h14a2 2 0 0 1 2 2v10a2 2 0 0 1 -2 2h-14a2 2 0 0 1 -2 -2v-10z"
                        />
                        <path d="M3 7l9 6l9 -6"/>
                    </svg>

                    <div class="mt-1.5 sm:mt-0">
                        <p class="text-gray-500">Email</p>

                        <p class="font-medium">
                            <xsl:value-of select="email"/>
                        </p>
                    </div>
                </div>
            </xsl:if>
            <xsl:if test="phone">
                <div
                        class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2"
                >
                    <svg
                            xmlns="http://www.w3.org/2000/svg"
                            width="24"
                            height="24"
                            viewBox="0 0 24 24"
                            fill="none"
                            stroke="currentColor"
                            stroke-width="2"
                            stroke-linecap="round"
                            stroke-linejoin="round"
                            class="size-6 text-indigo-700"
                    >
                        <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                        <path
                                d="M5 4h4l2 5l-2.5 1.5a11 11 0 0 0 5 5l1.5 -2.5l5 2v4a2 2 0 0 1 -2 2a16 16 0 0 1 -15 -15a2 2 0 0 1 2 -2"
                        />
                    </svg>
                    <div class="mt-1.5 sm:mt-0">
                        <p class="text-gray-500">Phone</p>

                        <p class="font-medium">
                            <xsl:value-of select="phone"/>
                        </p>
                    </div>
                </div>
            </xsl:if>
            <xsl:apply-templates select="location"/>
        </div>
    </xsl:template>

    <xsl:template match="location">
        <div class="sm:inline-flex sm:shrink-0 sm:items-center sm:gap-2">
            <svg
                    xmlns="http://www.w3.org/2000/svg"
                    width="24"
                    height="24"
                    viewBox="0 0 24 24"
                    fill="none"
                    stroke="currentColor"
                    stroke-width="2"
                    stroke-linecap="round"
                    stroke-linejoin="round"
                    class="size-6 text-indigo-700"
            >
                <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                <path d="M9 11a3 3 0 1 0 6 0a3 3 0 0 0 -6 0"/>
                <path
                        d="M17.657 16.657l-4.243 4.243a2 2 0 0 1 -2.827 0l-4.244 -4.243a8 8 0 1 1 11.314 0z"
                />
            </svg>
            <div class="mt-1.5 sm:mt-0">
                <p class="text-gray-500">Address</p>

                <p class="font-medium">
                    <xsl:value-of
                            select="concat(address,', ',city,', ',country)"
                    />
                </p>
            </div>
        </div>
    </xsl:template>
</xsl:stylesheet>
