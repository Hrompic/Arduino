//Hrompic 2020
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QLineEdit>
#include <QDebug>
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = nullptr);
	~Widget();
public slots:
	void getData();
	void writeData(int);
	void writeDataS(double);

private:
	Ui::Widget *ui;
	QSerialPort* sp;
	bool sync;
};
#endif // WIDGET_H
