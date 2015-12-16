#ifndef CONFIGDIALOG_H_
#define CONFIGDIALOG_H_

#include <QDialog>
#include "ui_configDialog.h"

class ConfigDialog : public QDialog
{
  Q_OBJECT
public:
  ConfigDialog ();

public slots:
  void changePage (QListWidgetItem* current, QListWidgetItem* previous);
private:
  void createIcons();
  //QListWidget *contentsWidget;
  //QStackedWidget *pagesWidget;
private:
  Ui_ConfigDialog ui;
};

#endif /*CONFIGDIALOG_H_*/
