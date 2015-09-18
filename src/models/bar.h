/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 David Krepsky
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * \addtogroup Models
 * \{
 */

/*!
 * \file bar.h
 *
 * \brief Bar class definition.
 *
 * This file defines the Bar class.
 *
 * \author David Krepsky
 * \version 0.1
 * \date 09/2015
 * \copyright David Krepsky
 */

#ifndef MODELS_BAR_H
#define MODELS_BAR_H

#include <QJsonObject>
#include <QGraphicsObject>
#include <armadillo>
#include <complex>
#include <stdint.h>
#include "models/line.h"
#include "graphics/infobar.h"

QT_BEGIN_NAMESPACE
class Line;
class InfoBar;
QT_END_NAMESPACE

using arma::Col;
using arma::cx_double;

/*!
 * \class Bar
 * \brief Represents a busbar in power distribution systems.
 *
 * ### Overview
 * Bar class represents a bar in a power system, providing the data structure
 * and methods that model a real bar.
 * A bar with id equals to 0 is an alimentator (Slack bar).
 * The class provides graphical.
 *
 * ### Example
 * \code
 *
 * \endcode
 */
class Bar : public QGraphicsObject
{
  Q_OBJECT

public:
  /*!
   *  \brief Bar invalid ID.
   *
   * Any Bar with this id should be treated as invalid.
   */
  static const int32_t kInvalidId = -1;

  /*!
   * \brief iconSize
   */
  static double iconSize;

  /*!
   * \brief contourColor
   */
  static QColor contourColor;

  /*!
   * \brief slackFillColor
   */
  static QColor slackFillColor;

  /*!
   * \brief pqFillColor
   */
  static QColor pqFillColor;

  /*!
   * \brief selectionFillColor
   */
  static QColor selectionFillColor;

  /*!
   * \brief id
   */
  int32_t id;

  /*!
   * \brief lines
   */
  QVector<Line *> lines;

  /*!
   * \brief Bar constructor.
   *
   *
   */
  Bar();

  /*!
   * \brief Bar constructor with initial condiditons.
   *
   * \param initialV
   * \param initialSh
   * \param initialSi
   */
  Bar(cx_double initialV, cx_double initialSh = cx_double(0.0,0.0),
      cx_double initialSi = cx_double(0.0,0.0));

  /*!
   * \brief Destructor.
   */
  virtual ~Bar();

  // Input parameters.
  /*!
   * \brief V
   * \return
   */
  Col<cx_double> &V() const;

  /*!
   * \brief setV
   * \param VA
   * \param VB
   * \param VC
   */
  void setV(cx_double &VA, cx_double &VB, cx_double &VC);


  /*!
   * \brief V_pu
   * \param voltageBase
   * \return
   */
  Col<cx_double> V_pu(double voltageBase) const;

  /*!
   * \brief Sh
   * \return
   */
  Col<cx_double> &Sh() const;

  /*!
   * \brief setSh
   * \param ShuntA
   * \param ShuntB
   * \param ShuntC
   */
  void setSh(cx_double &ShuntA, cx_double &ShuntB, cx_double &ShuntC);

  /*!
   * \brief Sh_pu
   * \param powerBase
   * \return
   */
  Col<cx_double> Sh_pu(double powerBase) const;

  /*!
   * \brief Si
   * \return
   */
  Col<cx_double> &Si() const;

  /*!
   * \brief setSi
   * \param SinjectA
   * \param SinjectB
   * \param SinjectC
   */
  void setSi(cx_double &SinjectA, cx_double &SinjectB, cx_double &SinjectC);

  /*!
   * \brief Si_pu
   * \param powerBase
   * \return
   */
  Col<cx_double> Si_pu(double powerBase) const;

  // Output parameters.
  /*!
   * \brief rV
   * \return
   */
  Col<cx_double> &rV() const;

  /*!
   * \brief setrV
   * \param rVA
   * \param rVB
   * \param rVC
   */
  void setrV(cx_double &rVA, cx_double &rVB, cx_double &rVC);

  /*!
   * \brief rV_pu
   * \param voltageBase
   * \return
   */
  Col<cx_double> rV_pu(double voltageBase) const;

  /*!
   * \brief rSi
   * \return
   */
  Col<cx_double> &rSi() const;

  /*!
   * \brief setrSi
   * \param rSinjectA
   * \param rSinjectB
   * \param rSinjectC
   */
  void setrSi(cx_double &rSinjectA, cx_double &rSinjectB, cx_double &rSinjectC);

  /*!
   * \brief rSi_pu
   * \param powerBase
   * \return
   */
  Col<cx_double> rSi_pu(double powerBase) const;

  // Line manipulation.
  /*!
   * \brief addLine
   * \param line
   */
  void addLine(Line *line);

  /*!
   * \brief removeLine
   * \param line
   */
  void removeLine(Line *line);

  /*!
   * \brief removeLines
   */
  void removeLines();

  // Conversion.
  /*!
   * \brief toJson
   * \return
   */
  QJsonObject toJson();

  /*!
   * \brief fromJson
   * \param jsonBar
   */
  void fromJson(QJsonObject &jsonBar);

  // Graphics.
  /*!
   * \brief
   *
   * \return
   */
  QRectF boundingRect() const Q_DECL_OVERRIDE;

signals:
  /*!
   * \brief eventDoubleClick
   */
  void eventDoubleClick();

protected:
  /*!
   * \brief mouseDoubleClickEvent
   * \param event
   */
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

  /*!
   * \brief
   *
   * \return
   */
  QVariant itemChange(GraphicsItemChange change,
                      const QVariant &value) Q_DECL_OVERRIDE;

  /*!
   * \brief
   *
   */
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) Q_DECL_OVERRIDE;

private:
  /*!
   * \brief V_
   */
  Col<cx_double> V_;

  /*!
   * \brief Sh_
   */
  Col<cx_double> Sh_;

  /*!
   * \brief Si_
   */
  Col<cx_double> Si_;

  /*!
   * \brief rV_
   */
  Col<cx_double> rV_;

  /*!
   * \brief rSi_
   */
  Col<cx_double> rSi_;

  /*!
   * \brief infoBar
   */
  InfoBar *infoBar;

  /*!
   * \brief drawSlack
   * \param painter
   */
  void drawSlack(QPainter *painter);

  /*!
   * \brief drawPq
   * \param painter
   */
  void drawPq(QPainter *painter);
};

#endif  // MODELS_BAR_H

/*!
 * \}
 */