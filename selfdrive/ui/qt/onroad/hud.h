#pragma once

#include <QtWidgets>

#include "selfdrive/common/params.h"
#include "selfdrive/ui/ui.h"


class StatusIcon : public QWidget {
  Q_OBJECT

public:
  StatusIcon(const QString &path, QWidget *parent = 0);

protected:
  void paintEvent(QPaintEvent *e) override;

private:
  float opacity;
  QColor background;
  QImage img;

  const int radius = 180;
  const int img_size = 135;

public slots:
  void setBackground(const QColor bg, const float op = 1.0);
};

class VisionOverlay : public QWidget {
  Q_OBJECT

public:
  VisionOverlay(QWidget *parent = 0);

private:
  QLabel *speed;
  QLabel *speed_unit;
  QLabel *maxspeed;
  StatusIcon *wheel;
  StatusIcon *monitoring;

  QColor bg;
  QVBoxLayout *layout;

  bool metric;
  Params params;

public slots:
  void update(const UIState &s);
  void offroadTransition(bool offroad);
};
