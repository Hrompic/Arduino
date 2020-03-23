//Hrompic 2020
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::Widget)
{
	ui->setupUi(this);
	sp = new QSerialPort(QSerialPortInfo::availablePorts()[0]);
	sp->setBaudRate(QSerialPort::Baud9600);
	sp->open(QIODevice::ReadWrite);

	connect(sp, SIGNAL(readyRead()), this, SLOT(getData()));
	connect(ui->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(writeData(int)));
	connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(writeDataS(double)));

}

Widget::~Widget()
{
	delete ui;
}

void Widget::getData()
{

//	qDebug() <<s0.open(QIODevice::ReadWrite) <<s0.error();

//	ui->label->setText(QString::number((float)val/255*5)+QString("V"));

	//sp->waitForReadyRead(201);
	//while(!sp->bytesAvailable())
	QByteArray mass = sp->readLine();
	sp->clear(QSerialPort::Input);
	ui->lcdNumber->display(mass.toFloat());;
	qDebug() << mass;// <<val;// <<lb->text();
	//update();

}

void Widget::writeData(int d)
{
	ui->label->setText(QString("%1V").arg((float)d/255*5, 0, 'f', 2));
	if(!sync)
		ui->doubleSpinBox->setValue((double)d/255*5);
	else
		ui->verticalSlider->setValue(d);
	sync = false;
	sp->write((char*)&d);
	qDebug() <<d;
}

void Widget::writeDataS(double d)
{
	sync = true;
	qDebug() <<d;
	writeData((int)(d/5.0*255.0));
}

