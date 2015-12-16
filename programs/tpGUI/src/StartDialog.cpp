#include "StartDialog.h"
#include "tpGlobal.h"
#include <QFileDialog>
#include <QFileInfo>

StartDialog::StartDialog ()
  : QDialog ()
{
  ui.setupUi (this);
  setModal (true);
  
  connect(ui.tbSelectFile, SIGNAL(clicked()), this, SLOT(selectFile()));
  connect(ui.leFileName, SIGNAL(textChanged (const QString&)), this, SLOT(fileNameTextChanged (const QString&)));
  ui.buttonBox -> buttons ().first () -> setEnabled ( false );
  loadDialog ();
}

StartDialog::~StartDialog ()
{
  saveDialog ();
}

void StartDialog::selectFile ()
{
  QString dir = QFileInfo (ui.leFileName -> text ()).absolutePath () + QDir::separator ();
  QString fileName = 
      QFileDialog::getSaveFileName (this, tr("Выберете файл эксперимента"),
          dir, tr("Текстовый файл (*.txt *.*)"));
  
  if (fileName.isEmpty ()) ui.leFileName -> setText ( dir );
  else
    ui.leFileName -> setText ( fileName );
}

void StartDialog::fileNameTextChanged ( const QString & text )
{
  ui.buttonBox -> buttons ().first () -> setEnabled ( ! QFileInfo (text).isDir () );
}

Pattern StartDialog::getPattern () const
{
  Pattern pattern;
  pattern.thickness () = ui.dsbThickness -> value () / 1000.0;
  pattern.width () = ui.dsbWidth -> value () / 1000.0;
  pattern.height () = ui.dsbLenght -> value () / 1000.0;
  return pattern;
}

Pendulum StartDialog::getPendulum () const
{
  Pendulum pend;
  pend.setM1 (ui.dsbM1 -> value () / 1000.0);
  pend.setM2 (ui.dsbM2 -> value () / 1000.0);
  pend.setR1 (ui.dsbRadius -> value () / 1000.0);
  pend.setR2 (ui.dsbRadius -> value () / 1000.0);

  tpSettings ().beginGroup (tr("КРУТИЛЬНЫЙ_МАЯТНИК"));
  pend.setKb  (tpSettings ().value(tr("Kb")).toDouble ());
  pend.setJp (tpSettings ().value(tr("Jp")).toDouble ());
  pend.setQp (tpSettings ().value(tr("Qp")).toDouble ());
  tpSettings ().endGroup ();  
    
  if (ui.cbSoftBracket -> isChecked ()) pend.setKb (0.0);
  return pend;
}

QString StartDialog::getExpFileName () const
{
  return ui.leFileName -> text ();
}

void StartDialog::saveDialog ()
{
  tpSettings ().beginGroup (tr("Образец-StartDialog"));  
  tpSettings ().setValue( tr("Толщина"), ui.dsbThickness -> value ());
  tpSettings ().setValue( tr("Ширина"), ui.dsbWidth -> value ());
  tpSettings ().setValue( tr("Длина"), ui.dsbLenght -> value ());
  tpSettings ().endGroup (); 
  
  tpSettings ().beginGroup (tr("Маятник-StartDialog"));
  tpSettings ().setValue( tr("M1"), ui.dsbM1 -> value ());  
  tpSettings ().setValue( tr("M2"), ui.dsbM2 -> value ());  
  tpSettings ().setValue( tr("MРадиус"), ui.dsbRadius -> value ());
  tpSettings ().setValue( tr("Мягкий_подвес"), ui.cbSoftBracket -> isChecked ());
  tpSettings ().setValue( tr("Последний файл"), ui.leFileName -> text ());
  tpSettings ().endGroup ();
}

void StartDialog::loadDialog ()
{
  double buf = 0.0;
  
  tpSettings ().beginGroup (tr("Образец-StartDialog"));  
  buf = tpSettings ().value( tr("Толщина"), 0.0).toDouble ();
  ui.dsbThickness -> setValue (buf);  
  buf = tpSettings ().value( tr("Ширина"), 0.0).toDouble ();
  ui.dsbWidth -> setValue (buf);  
  buf = tpSettings ().value( tr("Длина"), 0.0).toDouble ();
  ui.dsbLenght -> setValue (buf);  
  tpSettings ().endGroup ();
  
  tpSettings ().beginGroup (tr("Маятник-StartDialog"));
  buf = tpSettings ().value( tr("M1"), 0.0).toDouble ();
  ui.dsbM1 -> setValue (buf);  
  buf = tpSettings ().value( tr("M2"), 0.0).toDouble ();
  ui.dsbM2 -> setValue (buf);  
  buf = tpSettings ().value( tr("MРадиус"), 0.0).toDouble ();
  ui.dsbRadius -> setValue (buf);  
  ui.cbSoftBracket -> setChecked (
      tpSettings ().value( tr("Мягкий_подвес"), true).toBool ()
      );
  
  QString lastFile = tpSettings ().value( tr("Последний файл")).toString ();
  ui.leFileName -> setText ( QFileInfo (lastFile).absolutePath () + QDir::separator () );
  tpSettings ().endGroup ();  
}
