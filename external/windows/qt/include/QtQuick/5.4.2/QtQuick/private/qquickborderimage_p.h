/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtQuick module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQUICKBORDERIMAGE_P_H
#define QQUICKBORDERIMAGE_P_H

#include "qquickimagebase_p.h"

QT_BEGIN_NAMESPACE

class QQuickScaleGrid;
class QQuickGridScaledImage;
class QQuickBorderImagePrivate;
class Q_AUTOTEST_EXPORT QQuickBorderImage : public QQuickImageBase
{
    Q_OBJECT
    Q_ENUMS(TileMode)

    Q_PROPERTY(QQuickScaleGrid *border READ border CONSTANT)
    Q_PROPERTY(TileMode horizontalTileMode READ horizontalTileMode WRITE setHorizontalTileMode NOTIFY horizontalTileModeChanged)
    Q_PROPERTY(TileMode verticalTileMode READ verticalTileMode WRITE setVerticalTileMode NOTIFY verticalTileModeChanged)
    // read-only for BorderImage
    Q_PROPERTY(QSize sourceSize READ sourceSize NOTIFY sourceSizeChanged)

public:
    QQuickBorderImage(QQuickItem *parent=0);
    ~QQuickBorderImage();

    QQuickScaleGrid *border();

    enum TileMode { Stretch = Qt::StretchTile, Repeat = Qt::RepeatTile, Round = Qt::RoundTile };

    TileMode horizontalTileMode() const;
    void setHorizontalTileMode(TileMode);

    TileMode verticalTileMode() const;
    void setVerticalTileMode(TileMode);

    void setSource(const QUrl &url);

Q_SIGNALS:
    void horizontalTileModeChanged();
    void verticalTileModeChanged();
    void sourceSizeChanged();

protected:
    virtual void load();
    virtual void pixmapChange();
    virtual QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

private:
    void setGridScaledImage(const QQuickGridScaledImage& sci);

private Q_SLOTS:
    void doUpdate();
    void requestFinished();
    void sciRequestFinished();

private:
    Q_DISABLE_COPY(QQuickBorderImage)
    Q_DECLARE_PRIVATE(QQuickBorderImage)
};

QT_END_NAMESPACE
QML_DECLARE_TYPE(QQuickBorderImage)

#endif // QQUICKBORDERIMAGE_P_H
