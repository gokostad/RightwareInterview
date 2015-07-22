<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <body>

                <h2>StartupTime Measurement Test Result:</h2>
                <table border="1">
                    <tr bgcolor="#9acd32">
                        <th>Time (sec)</th>
                    </tr>
                    <xsl:for-each select="RightwareSolutionTesting/StartupTimeTest/StartupTimeMeasurement">
                        <tr>
                            <td><xsl:value-of select="Time"/></td>
                        </tr>
                    </xsl:for-each>
                </table>

                <h2>FPS Measurement Test Results:</h2>
                <table border="1">
                    <tr bgcolor="#9acd32">
                        <th>Test number</th>
                        <th>Geometry count</th>
                        <th>FPS</th>
                    </tr>
                    <xsl:for-each select="RightwareSolutionTesting/FPSTest/FPSMeasurement">
                        <tr>
                            <td><xsl:value-of select="TestNumber"/></td>
                            <td><xsl:value-of select="GeometryCount"/></td>
                            <td><xsl:value-of select="FPS"/></td>
                        </tr>
                    </xsl:for-each>
                </table>

            </body>

        </html>
    </xsl:template>
</xsl:stylesheet>
