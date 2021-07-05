#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httpbody.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	m_btnOK = ui->OK;
	m_editIP = ui->IP;
	m_lbResult = ui->Result;
	manager = new QNetworkAccessManager(this);
	connect(m_btnOK, &QPushButton::clicked, this, &MainWindow::onOKBtnClick);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onReplyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::onOKBtnClick() {
	auto ip = m_editIP->text();
	manager->get(QNetworkRequest(QUrl("https://ip.michaelapp.com/query?ip=" + ip)));
}

void MainWindow::onReplyFinished(QNetworkReply * reply)
{
	QTextCodec *codec = QTextCodec::codecForName("utf8");
	auto all = codec->toUnicode(reply->readAll()).toStdString();
	resp::respresult reqpost = nlohmann::json::parse(all);
	m_lbResult->setText(QString::fromStdString(reqpost.result));
	reply->deleteLater();
}