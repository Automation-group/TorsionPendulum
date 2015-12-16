#ifndef CONFIGPAGES_H_
#define CONFIGPAGES_H_

#include <QWidget>
#include "ui_metakoncfg.h"
#include "ui_tornpendcfg.h"

class MetakonConfigPage : public QWidget
{
  Q_OBJECT
public:
  MetakonConfigPage (QWidget* parent = 0);
public slots:
  void loadSettings ();
  void saveSettings ();
private:
  Ui_MetakonCfgForm ui;
};

class TornPendConfigPage : public QWidget
{
  Q_OBJECT
public:
  TornPendConfigPage (QWidget* parent = 0);
public slots:
  void loadSettings ();
  void saveSettings ();
private:
  Ui_TornPendCfgForm ui;
};
/*
class UpdatePage : public QWidget
{
public:
  UpdatePage (QWidget* parent = 0);
};
 */
#endif /*CONFIGPAGES_H_*/
