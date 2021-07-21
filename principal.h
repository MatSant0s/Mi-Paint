#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QColorDialog>
#include <QDir>
#include <QFileDialog>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:

    void paintEvent(QPaintEvent *event ) override;

    void mousePressEvent(QMouseEvent *event )override;

    void mouseMoveEvent(QMouseEvent *event) override; //metodo para mantener presionado y mover


private slots:
    void on_actionLibre_triggered();

    void on_actionLineas_triggered();

    void on_actionRectangulos_triggered();

    void on_actionCincurferencias_triggered();

    void on_actionGuardar_triggered();

    void on_actionSalir_triggered();

    void on_actionColor_triggered();

    void on_actionAncho_triggered();

private:
    Ui::Principal *ui;

    QImage *m_imagen;       //es la imagen sobre la cual se va adibujar
    QPainter *m_painter;    //objeto painter

    QPoint m_ptInicial;     //Punto inicial para dibujar
    QPoint m_ptFinal;       //Puto final para dibujar
    int m_opcion;           //opcion de dibujo
    bool m_toogle = true;

    QColor m_color;         //miembrro para colorear
    QPen pincel;            //establecemos el pincel
    int m_ancho;            //modificaremos el cancho

};
#endif // PRINCIPAL_H
