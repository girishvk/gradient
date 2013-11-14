#include <QPalette>
#include "ColorSelect.h"
#include "ui_ColorSelect.h"

ColorSelect::ColorSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSelect)
{
    ui->setupUi(this);
    connect(ui->redslider,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    connect(ui->greenslider,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    connect(ui->blueslider,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    onColorChanged();
}

ColorSelect::~ColorSelect()
{
    delete ui;
}

void ColorSelect::onColorChanged()
{
    m_color.setRgb(ui->redslider->value(),ui->greenslider->value(),ui->blueslider->value());
    QPalette pal=ui->displaywidget->palette();
    pal.setColor(QPalette::Window,m_color);
    ui->displaywidget->setPalette(pal);
    emit colorChanged(m_color);

}
