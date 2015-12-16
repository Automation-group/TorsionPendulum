#include <QtGui>

#include "ConfigDialog.h"
#include "ConfigPages.h"

ConfigDialog::ConfigDialog()
{
  ui.setupUi (this);
  
  ui.contentWidget -> setViewMode (QListView::IconMode);
  ui.contentWidget -> setIconSize (QSize (96, 84));
  ui.contentWidget -> setMovement (QListView::Static);
  ui.contentWidget -> setMaximumWidth (128);
  ui.contentWidget -> setSpacing (12);

  ui.stackedWidget -> removeWidget (ui.stackedWidget -> currentWidget ());
  
  QWidget* settingsWidget = new MetakonConfigPage ();
  ui.stackedWidget -> addWidget(settingsWidget);
  connect (ui.pbApplay, SIGNAL(clicked()), settingsWidget, SLOT(saveSettings()));
  connect (ui.pbCancel, SIGNAL(clicked()), settingsWidget, SLOT(loadSettings()));
  
  settingsWidget = new TornPendConfigPage ();
  ui.stackedWidget -> addWidget(settingsWidget);
  connect (ui.pbApplay, SIGNAL(clicked()), settingsWidget, SLOT(saveSettings()));
  connect (ui.pbCancel, SIGNAL(clicked()), settingsWidget, SLOT(loadSettings()));

  createIcons ();
  ui.contentWidget -> setCurrentRow (0);
  
  connect (ui.pbApplay, SIGNAL(clicked()), this, SLOT(close()));
}

void ConfigDialog::createIcons()
{
  
  QListWidgetItem *configButton = new QListWidgetItem (ui.contentWidget);
  configButton->setIcon (QIcon (":/images/metakoncfg.png"));
  configButton->setText (tr("ПИКРТ"));
  configButton->setTextAlignment (Qt::AlignHCenter);
  configButton->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);

  QListWidgetItem *updateButton = new QListWidgetItem (ui.contentWidget);
  updateButton->setIcon (QIcon (":/images/tornpendcfg.png"));
  updateButton->setText (tr("АЗК"));
  updateButton->setTextAlignment (Qt::AlignHCenter);
  updateButton->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);

  connect(ui.contentWidget,
      SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
      this, SLOT(changePage(QListWidgetItem *, QListWidgetItem*)));
      
}

void ConfigDialog::changePage(QListWidgetItem *current,
    QListWidgetItem *previous)
{
  if (!current)
    current = previous;

  ui.stackedWidget -> setCurrentIndex (ui.contentWidget -> row (current));
}
