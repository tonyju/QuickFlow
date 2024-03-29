#ifndef WINDOW_LINEPROPERTIES_H
#define WINDOW_LINEPROPERTIES_H

#include <QDialog>
#include <QMap>
#include <QLineEdit>
#include "unit.h"
#include "project.h"
#include "models/line.h"
#include "models/bar.h"

namespace Ui
{
class LineProperties;
}

class LineProperties : public QDialog
{
  Q_OBJECT

public:
  explicit LineProperties(QWidget *parent = 0);
  ~LineProperties();

  bool setOptions(Project *project, Line *line);

  Line *line();

private slots:
  void on_buttonBox_accepted();

  void on_buttonBox_rejected();

private:
  Ui::LineProperties *ui;
  Project *project_;
  Line *line_;
  bool isNew;

  bool validImpedance(QLineEdit *input);
};

#endif // LINEPROPERTIES_H
