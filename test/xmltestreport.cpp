/****************************************************************************
**
** class XmlTestReport
**
** Description:
** Implementation of XmlTestReport class. Used for generation test result as
** xml and html files.
**
****************************************************************************/
#include <QTest>
#include <QString>
#include <QFileInfo>
#include <QXmlQuery>
#include <exception>

#include "XmlTestReport.h"

XmlTestReport xmlReport;

XmlTestReport::XmlTestReport() :
    xmlFileName(""),
    htmlFileName("")
{}

XmlTestReport::~XmlTestReport()
{
    closeReport();
}

QString XmlTestReport::getNewXmlFileName()
{
    xmlFileName = applicationPath + "/" + QDateTime::currentDateTime().toString("yyMMddhhmmss") + "_ApplicationTestResult";
    htmlFileName = xmlFileName + ".html";
    xmlFileName += ".xml";
    return xmlFileName;
}

QString XmlTestReport::getXslFileName() const
{
    return "./ApplicationTestResult.xsl";
}

void XmlTestReport::openReport()
{
    if (!file.isOpen())
    {
        try
        {
            //lets open xml reporter file, with current date time extension on file name
            file.setFileName(getNewXmlFileName());

            if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
                QFAIL(QString("Can not open result output file "+file.fileName()).toLatin1().data());

            xmlReport.setDevice(&file);

            xmlReport.writeStartDocument();
            addElement("RightwareSolutionTesting");
        }
        catch (...)
        {
            QWARN("Error happened while generating xml output file");
        }
    }
}

void XmlTestReport::closeReport()
{
    if (file.isOpen())
    {
        closeElement();
        xmlReport.writeEndDocument();
        //flush and close report
        file.flush();
        try
        {
            generateHTMLReport();
        }
        catch (...)
        {
            QWARN("Error happened while generating html output file");
        }
    }
    file.close();
}

void XmlTestReport::generateHTMLReport()
{
    //read xsl file
    QFile xsl(getXslFileName());
    if (xsl.open(QIODevice::ReadOnly))
    {
        //read xsl data
        QString xlsData(xsl.readAll());

        try
        {
            //start making html output
            QXmlQuery query(QXmlQuery::XSLT20);

            //go back to begging of xml file
            file.seek(0);

            //set focus and query
            query.setFocus(&file);
            query.setQuery(xlsData);

            //write html
            QFile htmlFile(htmlFileName);
            if (htmlFile.open(QIODevice::WriteOnly))
            {
                query.evaluateTo(&htmlFile);
                htmlFile.flush();
                htmlFile.close();
            }
            else
                QWARN("Can not open test html output file");
        }
        catch (std::exception& e)
        {
            QWARN(e.what());
        }
        catch (...)
        {
            QWARN("Error happened while generating html output file");
        }
    }
}

void XmlTestReport::addElement(QString elementName)
{
    xmlReport.writeStartElement(elementName);
}

void XmlTestReport::closeElement()
{
    xmlReport.writeEndElement();
}

void XmlTestReport::addElementAndAttribute(QString elementName, QString attributeName, float value, int decimalNumber, bool closeAttribute)
{
    addElement(elementName);
    addAttribute(attributeName, value, decimalNumber);
    if (closeAttribute)
        closeElement();
}

void XmlTestReport::addElementAndAttribute(QString elementName, QString attributeName, qint64 value, bool closeAttribute)
{
    addElement(elementName);
    addAttribute(attributeName, value);
    if (closeAttribute)
        closeElement();
}

void XmlTestReport::addElementAndAttribute(QString elementName, QString attributeName, int value, bool closeAttribute)
{
    addElement(elementName);
    addAttribute(attributeName, value);
    if (closeAttribute)
        closeElement();
}

void XmlTestReport::addElementAndAttribute(QString elementName, QString attributeName, QString value, bool closeAttribute)
{
    addElement(elementName);
    addAttribute(attributeName, value);
    if (closeAttribute)
        closeElement();
}

void XmlTestReport::addAttribute(QString attributeName, float value, int decimalNumber)
{
    xmlReport.writeAttribute(attributeName, QString::number(value, 'f', decimalNumber));
}

void XmlTestReport::addAttribute(QString attributeName, qint64 value)
{
    xmlReport.writeAttribute(attributeName, QString::number(value));
}

void XmlTestReport::addAttribute(QString attributeName, int value)
{
    xmlReport.writeAttribute(attributeName, QString::number(value));
}

void XmlTestReport::addAttribute(QString attributeName, QString value)
{
    xmlReport.writeAttribute(attributeName, value);
}

void XmlTestReport::addCharacters(float value, int decimalNumber)
{
    xmlReport.writeCharacters(QString::number(value, 'f', decimalNumber));
}

void XmlTestReport::addCharacters(qint64 value)
{
    xmlReport.writeCharacters(QString::number(value));
}

void XmlTestReport::addCharacters(int value)
{
    xmlReport.writeCharacters(QString::number(value));
}

void XmlTestReport::addCharacters(QString value)
{
    xmlReport.writeCharacters(value);
}

void XmlTestReport::addElementAndCharacters(QString elementName, float value, int decimalNumber)
{
    addElement(elementName);
    addCharacters(value, decimalNumber);
    closeElement();
}

void XmlTestReport::addElementAndCharacters(QString elementName, qint64 value)
{
    addElement(elementName);
    addCharacters(value);
    closeElement();
}

void XmlTestReport::addElementAndCharacters(QString elementName, int value)
{
    addElement(elementName);
    addCharacters(value);
    closeElement();
}

void XmlTestReport::addElementAndCharacters(QString elementName, QString value)
{
    addElement(elementName);
    addCharacters(value);
    closeElement();
}
