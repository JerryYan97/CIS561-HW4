#include "mainwindow.h"
#include <ui_mainwindow.h>
#include <cameracontrolshelp.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionLoad_Scene_triggered()
{
    ui->mygl->SceneLoadDialog();
}

void MainWindow::slot_ResizeToCamera(int w, int h)
{
    setFixedWidth(w);
    setFixedWidth(h);
}

void MainWindow::on_actionRender_triggered()
{
    /*glm::vec4 col1(1.f, 0.f, 0.f, 0.f);
    glm::vec4 col2(0.f, 1.f, 0.f, 0.f);
    glm::vec4 col3(0.f, 0.f, 1.f, 0.f);
    glm::vec4 col4(1.f, 2.f, 3.f, 1.f);
    glm::mat4 tMat(col1, col2, col3, col4);
    glm::vec4 point(0.f, 0.f, 0.f, 1.f);
    glm::vec4 res = tMat * point;*/

    ui->mygl->RenderScene();
}

void MainWindow::on_actionCamera_Controls_triggered()
{
    help.show();
}
void MainWindow::slot_DisableGUI(bool b)
{
    ui->integratorSpinBox->setEnabled(!b);
    ui->samplesSpinBox->setEnabled(!b);
    ui->recursionSpinBox->setEnabled(!b);
    ui->checkBox_Progressive->setEnabled(!b);
}
