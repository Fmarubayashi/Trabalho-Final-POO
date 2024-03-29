#include "imprimiraluno.h"
#include "ui_imprimiraluno.h"
#include "Sistema.h"
#include <QMessageBox>

imprimirAluno::imprimirAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::imprimirAluno)
{
    ui->setupUi(this);
}

imprimirAluno::~imprimirAluno()
{
    delete ui;
}

void imprimirAluno::on_pushButton_clicked()
{
    Sistema sist("aluno", "materias", "professores");
    QString nome = ui->lineEdit->text();
    char nomeC[50];
    strcpy(nomeC, nome.toStdString().c_str());

    //Recebe o texto que deverá ser impresso de .imprimirAluno
    //e utiliza a message box para mostrar-lo na tela.
    QString texto = QString::fromStdString(sist.imprimirAluno(nomeC));
    QMessageBox::about(this, "Aluno", texto);
    this->close();
}
