#include "tpGlobal.h"

QSettings settings (QSettings::IniFormat, QSettings::UserScope, "Lab5", "TPSimple");

QSettings& tpSettings ()
{
  return settings;
}
