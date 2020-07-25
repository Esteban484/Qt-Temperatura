#include "temperatura.h"
#include "ui_temperatura.h"

#include <QDebug>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    connect(ui->dialCent,SIGNAL(valueChanged(int)),
            this,SLOT(cent2Fahr(int)));
    //Conexion del de Fahr y cambie el valor con la respectiva formula
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this,SLOT(fahr2Cent(int)));
    connect(ui->dialKel,SIGNAL(valueChanged(int)),
            this,SLOT(cent2Kel(int)));
    connect(ui->dialCent,SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    connect(ui->dialFahr,SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    connect(ui->dialKel,SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    //Establecer el valor inicial de Fahrenheit
    ui->dialFahr->setValue(32);
    ui->dialKel->setValue(273);


}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Fahr(int valor)
{
   //Si esta seleccionando el dial de cent se realizar la formula correspondientete
    if(ui->dialCent->hasFocus()){

        float f= valor * 9.0/5 +32;
        ui->dialFahr->setValue(f);

        float k= valor+273;
        ui->dialKel->setValue(k);
   }
}


void Temperatura::fahr2Cent(int valor)
{
    //Si esta seleccionando el dial de Fahr se realizar la formula correspondiente
    if(ui->dialFahr->hasFocus()){
        float c=(valor -32)+5.0/9;
        ui->dialCent->setValue(c);

        float k=(valor-32) * 5/9 + 273.15;
        ui->dialKel->setValue(k);
    }

}

void Temperatura::cent2Kel(int valor)
{
    if(ui->dialKel->hasFocus()){
        float c=valor-273;
        ui->dialCent->setValue(c);

        float f=(valor -273) * 9/5 + 32;
        ui->dialFahr->setValue(f);
    }
}

void Temperatura::cambioCursor()
{
    if(ui->dialCent->hasFocus()){
        if(ui->dialCent->cursor()==Qt::OpenHandCursor){
            ui->dialCent->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialCent->setCursor(Qt::OpenHandCursor);
        }
    }

    if(ui->dialFahr->hasFocus()){
        if(ui->dialFahr->cursor()==Qt::OpenHandCursor){
            ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialFahr->setCursor(Qt::OpenHandCursor);
        }
    }

    if(ui->dialKel->hasFocus()){
        if(ui->dialKel->cursor()==Qt::OpenHandCursor){
            ui->dialKel->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialKel->setCursor(Qt::OpenHandCursor);
        }
    }

}

