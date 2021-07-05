#ifndef mainwindow_h
#define mainwindow_h

#include <QMainWindow>
#include <QScopedPointer>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextCodec>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

public slots:
	void onOKBtnClick();
	void onReplyFinished(QNetworkReply *reply);

private:
    QScopedPointer<Ui::MainWindow> ui;
	QPushButton* m_btnOK = nullptr;
	QLineEdit* m_editIP = nullptr;
	QLabel* m_lbResult = nullptr;
	QNetworkAccessManager *manager = nullptr;
};

#endif
