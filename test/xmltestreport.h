/****************************************************************************
**
** class XmlTestReport
**
** Description:
** Declaration of XmlTestReport class. Used for generation test result as
** xml and html files.
**
****************************************************************************/
#ifndef XMLTESTRREPORT_H
#define XMLTESTRREPORT_H

#include <QXmlStreamWriter>
#include <QFile>

#include "libmain.h"

class XmlTestReport
{
public:
    XmlTestReport();
    virtual ~XmlTestReport();

    virtual void addElement(QString elementName);
    virtual void closeElement();

    virtual void addElementAndAttribute(QString elementName, QString attributeName, float attr, int decimalNumber = 2, bool closeAttribute = true);
    virtual void addElementAndAttribute(QString elementName, QString attributeName, qint64 attr, bool closeAttribute = true);
    virtual void addElementAndAttribute(QString elementName, QString attributeName, int attr, bool closeAttribute = true);
    virtual void addElementAndAttribute(QString elementName, QString attributeName, QString attr, bool closeAttribute = true);

    virtual void addAttribute(QString attributeName, float value, int decimalNumber = 2);
    virtual void addAttribute(QString attributeName, qint64 value);
    virtual void addAttribute(QString attributeName, int value);
    virtual void addAttribute(QString attributeName, QString value);

    virtual void addCharacters(float value, int decimalNumber = 2);
    virtual void addCharacters(qint64 value);
    virtual void addCharacters(int value);
    virtual void addCharacters(QString value);

    virtual void addElementAndCharacters(QString elementName, float value, int decimalNumber = 2);
    virtual void addElementAndCharacters(QString elementName, qint64 value);
    virtual void addElementAndCharacters(QString elementName, int value);
    virtual void addElementAndCharacters(QString elementName, QString value);

    virtual void openReport();
    virtual void closeReport();

protected:
    virtual QString getNewXmlFileName();
    virtual QString getXslFileName() const;

    virtual void generateHTMLReport();

private:
    QXmlStreamWriter xmlReport;
    QFile file;
    QString xmlFileName;
    QString htmlFileName;
};

#endif // XMLTESTRREPORT_H
