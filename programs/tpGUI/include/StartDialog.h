#ifndef STARTDIALOG_H_
#define STARTDIALOG_H_

#include <QDialog>
#include "ui_startDialog.h"
#include "Pattern.h"
#include "Pendulum.h"

class StartDialog : public QDialog
{
  Q_OBJECT
public:
  StartDialog ();
  ~StartDialog ();
  
  Pattern getPattern () const;
  Pendulum getPendulum () const;
  QString getExpFileName () const;
private slots:
  void selectFile ();
  void fileNameTextChanged ( const QString & text );
private:
  void saveDialog ();
  void loadDialog ();
private:
  Ui_StartDialog ui;
};

#endif /*STARTDIALOG_H_*/
