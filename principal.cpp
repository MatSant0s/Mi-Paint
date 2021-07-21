#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //instancia del objeto imagen

    m_imagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied); //tamaño y la imagen

    //Rellenar de blanco

    m_imagen->fill(Qt::white);

    //instanciamos el objeto painter

    m_painter = new QPainter(m_imagen);

    //opcion por defecto
    m_opcion = 1;
}

Principal::~Principal()
{
    delete ui;
}
/**
 * @brief Principal::paintEvent Se ejecuta cada vez que se redibuja la interfaz
 * @param event
 */
void Principal::paintEvent(QPaintEvent *event)
{
    //Creamos un painter local

    QPainter painter (this); //Le mandamos la ventana como principal

    //dibujar la imagen

    painter.drawImage(0,0,*m_imagen);

    //Aceptamos el evento

    event->accept();

}

void Principal::mousePressEvent(QMouseEvent *event)
{
    if(m_opcion == 1){
            m_ptInicial = event->pos();
        }else if(m_opcion == 2){
            if(m_toogle){
                m_ptInicial = event->pos();
            }else{
                m_ptFinal = event->pos();
                QPen pincel;
                m_painter->setPen(pincel);
                m_painter->drawLine(m_ptInicial, m_ptFinal);
                // Redibujar la inter   faz gráfica
                update();
            }
        }else if(m_opcion == 3){    //opcion para rectangulos
            if(m_toogle){
                m_ptInicial = event->pos();
            }else{
                m_ptFinal = event->pos();
                // Dibujar rectangulo
                int ancho = m_ptFinal.x() - m_ptInicial.x();
                int alto = m_ptFinal.y() - m_ptInicial.y();

                QPen pincel;
                m_painter->setPen(pincel);
                m_painter->drawRect(m_ptInicial.x(), m_ptInicial.y(), ancho, alto);
                // Redibujar la interfaz gráfica
                update();
            }
        }else if(m_opcion == 4){    //Opcion para circulos
            if(m_toogle){
                m_ptInicial = event->pos();
            }else{
                m_ptFinal = event->pos();

                //Dibujar el circulo

                int m_ancho = m_ptFinal.x() - m_ptInicial.x();
                int m_alto = m_ptFinal.y() - m_ptInicial.y();

                QPen pincel;    //creamos un pincel

                m_painter->setPen(pincel);
                QRectF rectangle(m_ptInicial.x(),m_ptInicial.y(),m_ancho,m_alto);
                m_painter->drawEllipse(rectangle);
                update(); // Redibujar la interfaz gráfica



            }
        }
        m_toogle = !m_toogle;

}

void Principal::mouseMoveEvent(QMouseEvent *event)
{
   if(m_opcion == 1){
    m_ptFinal = event->pos();

    //creamos pincel

    QPen pincel ;

    //selciionamos el color

    pincel.setColor(Qt::red);

    //escribimso el pincel

    m_painter->setPen(pincel);

    //Dibujar un alinea

    m_painter->drawLine(m_ptInicial, m_ptFinal);

    }

    //Redibujar ya que no mostraba nada en pantalla

    update();

    m_ptInicial  = m_ptFinal; //nos ayuda a resolver el error del mismo punto de inciio
}


void Principal::on_actionLibre_triggered()
{
    m_opcion = 1;
}

void Principal::on_actionLineas_triggered()
{
    m_opcion = 2;
}

void Principal::on_actionRectangulos_triggered()
{
    m_opcion = 3;
}

void Principal::on_actionCincurferencias_triggered()
{
    m_opcion = 4;
}

void Principal::on_actionGuardar_triggered()
{
    QDir directorio = QDir::home();

    QString pathArchivo = directorio.absolutePath()+"sin nombre.jpg";

    QString fileName = QFileDialog::getSaveFileName(this, "Ventana",
                                                    pathArchivo,
                                                  + "Archivo imagen (*jpg)");
    m_imagen->save(fileName);
}

void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_actionColor_triggered()
{
   m_color = QColorDialog::getColor(m_color, this, "Color del pincel",QColorDialog::ColorDialogOptions());
}

void Principal::on_actionAncho_triggered()
{

      m_ancho = QInputDialog::getInt(this, "Ancho del pincel", "Ingrese el ancho del pincel", m_ancho, 1, 100);

}
