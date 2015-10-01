#include "infobar.h"

#include <QPainter>

InfoBar::InfoBar(Bar *bar) :
  bar_(bar)
{
  setZValue(2);
  qreal px = bar->x();
  qreal py = bar->y() - bar->boundingRect().height() / 2;

  setPos(px,py);
}

InfoBar::~InfoBar() {}

void InfoBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  // Draw main rectangle.
  painter->setPen(QPen(Qt::black, kLineWidth, Qt::SolidLine));
  painter->setBrush(Qt::white);
  QRectF main_rect =
    QRectF(-kBoxWidth / 2, -kBoxHeight - kBoxBaseHeight, kBoxWidth, kBoxHeight);
  painter->drawRect(main_rect);

  // Set Head font size.
  QFont font;
  font.setPointSize(font.pointSize() * 1.25);
  painter->setFont(font);

  // Draw Head separation.
  qreal headHeight = kMarginHeadTop + kMarginHeadBot + font.pointSize();

  painter->drawLine(QPointF(-kBoxWidth/2,
                            -kBoxHeight - kBoxBaseHeight + headHeight),
                    QPointF(kBoxWidth/2, -kBoxHeight - kBoxBaseHeight + headHeight));

  // Head Text.
  QString head = "Bar " + QString::number(bar_->id);

  // Draw Head Text.
  painter->drawText(-kBoxWidth/2, -kBoxHeight - kBoxBaseHeight + kMarginHeadTop,
                    kBoxWidth, font.pointSize(), Qt::AlignCenter, head );

  // Revert font size.
  font.setPointSize(font.pointSize() / 1.25);

  // Table points.
  qreal tableXi = -kBoxWidth/2.0 + kMarginLeft;
  qreal tableYi = -kBoxHeight - kBoxBaseHeight + headHeight + kMarginTop;

  qreal tableXf = kBoxWidth/2.0 - kMarginRight;
  qreal tableYf = - kBoxBaseHeight - kMarginBot;

  qreal tableDx = (tableXf - tableXi);
  qreal tableDy = (tableYf - tableYi);

  // Set table pen.
  painter->setPen(QPen(Qt::lightGray, kTableLineWidth, Qt::SolidLine));

  // Draw table colums.
  for(int i=1; i<kTableColums; i++) {
    qreal x = tableXi + tableDx*static_cast<qreal>(i)/static_cast<qreal>
              (kTableColums);
    painter->drawLine(x, tableYi, x, tableYf);
  }

  // Draw table rows.
  for(int i=1; i<kTableRows; i++) {
    qreal y = tableYi + tableDy*static_cast<qreal>(i)/static_cast<qreal>
              (kTableRows);
    painter->drawLine(tableXi,
                      y,
                      tableXf,
                      y);
  }

  // Table text is gray.
  painter->setPen(QPen(Qt::gray, kTableLineWidth, Qt::SolidLine));

  // Draw table 0-1 text.
  // Voltage.
  qreal x = tableXi + tableDx/static_cast<qreal>(kTableColums);
  qreal y = tableYi;
  qreal w = tableDx/static_cast<qreal>(kTableColums);
  qreal h = tableDy/static_cast<qreal>(kTableRows);
  painter->drawText(x,y,w,h, Qt::AlignCenter, "Voltage [V]");

  //Draw table 0-2 text
  // Current.
  x = tableXi + 2*tableDx/static_cast<qreal>(kTableColums);
  painter->drawText(x,y,w,h, Qt::AlignCenter, "Injected [VA]");

  //Draw table 1-0 text
  // Phase A.
  x = tableXi;
  y = tableYi + tableDy/static_cast<qreal>(kTableRows);
  painter->drawText(x,y,w,h, Qt::AlignCenter, "Phase A");

  QString buffer; // buffer used to hold numeric values.

  //Draw table 1-1 text
  // Va.
  x = tableXi + tableDx/static_cast<qreal>(kTableColums);
  buffer = QString::number(abs(bar_->rVa)) + " / " + QString::number(arg(
             bar_->rVa)*180.0/M_PI) + "°";
  painter->drawText(x,y,w,h, Qt::AlignCenter, buffer);

  //Draw table 1-2 text
  // Ia.
  x = tableXi + 2*tableDx/static_cast<qreal>(kTableColums);
  buffer = QString::number(abs(bar_->rSia)) + " / " + QString::number(arg(
             bar_->rSia)*180.0/M_PI) + "°";
  painter->drawText(x,y,w,h, Qt::AlignCenter, buffer);

  //Draw table 2-0 text
  // Phase B.
  x = tableXi;
  y = tableYi + 2*tableDy/static_cast<qreal>(kTableRows);
  painter->drawText(x,y,w,h, Qt::AlignCenter, "Phase B");

  //Draw table 2-1 text
  // Vb.
  x = tableXi + tableDx/static_cast<qreal>(kTableColums);
  buffer = QString::number(abs(bar_->rVb)) + " / " + QString::number(arg(
             bar_->rVb)*180.0/M_PI) + "°";
  painter->drawText(x,y,w,h, Qt::AlignCenter, buffer);

  //Draw table 2-2 text
  // Ib.
  x = tableXi + 2*tableDx/static_cast<qreal>(kTableColums);
  buffer = QString::number(abs(bar_->rSib)) + " / " + QString::number(arg(
             bar_->rSib)*180.0/M_PI) + "°";
  painter->drawText(x,y,w,h, Qt::AlignCenter, buffer);

  //Draw table 3-0 text
  // Phase C.
  x = tableXi;
  y = tableYi + 3*tableDy/static_cast<qreal>(kTableRows);
  painter->drawText(x,y,w,h, Qt::AlignCenter, "Phase C");

  //Draw table 3-1 text
  // Vc.
  x = tableXi + tableDx/static_cast<qreal>(kTableColums);
  buffer = QString::number(abs(bar_->rVc)) + " / " + QString::number(arg(
             bar_->rVc)*180.0/M_PI) + "°";
  painter->drawText(x,y,w,h, Qt::AlignCenter, buffer);

  //Draw table 3-2 text
  // Ic.
  x = tableXi + 2*tableDx/static_cast<qreal>(kTableColums);
  buffer = QString::number(abs(bar_->rSic)) + " / " + QString::number(arg(
             bar_->rSic)*180.0/M_PI) + "°";
  painter->drawText(x,y,w,h, Qt::AlignCenter, buffer);

  // Draw base.
  painter->setPen(QPen(Qt::black, kLineWidth, Qt::SolidLine));
  painter->setBrush(Qt::black);
  QPolygonF pol_base;
  pol_base << QPointF(-kBoxBaseWidth/2, -kBoxBaseHeight) << QPointF(0.0, 0.0)
           << QPointF(kBoxBaseWidth/2, -kBoxBaseHeight);
  painter->drawPolygon(pol_base);

}

QRectF InfoBar::boundingRect() const
{
  return QRectF(-kBoxWidth / 2, -kBoxHeight - kBoxBaseHeight, kBoxWidth,
                kBoxHeight + kBoxBaseHeight);
}
