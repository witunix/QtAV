/******************************************************************************
    QtAV:  Media play library based on Qt and FFmpeg
    Copyright (C) 2013 Wang Bin <wbsecg1@gmail.com>
    theoribeiro <theo@fictix.com.br>

*   This file is part of QtAV

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
******************************************************************************/

#ifndef QTAV_QML_QQUICKRENDERER_H
#define QTAV_QML_QQUICKRENDERER_H

#include <QmlAV/Export.h>
#include <QtAV/VideoRenderer.h>
#include <QtQuick/QQuickItem>

namespace QtAV
{
extern QMLAV_EXPORT VideoRendererId VideoRendererId_QQuickItem;

class QQuickItemRendererPrivate;
class QMLAV_EXPORT QQuickItemRenderer : public QQuickItem, public VideoRenderer
{
    DPTR_DECLARE_PRIVATE(QQuickItemRenderer)
public:
    explicit QQuickItemRenderer(QQuickItem *parent = 0);
    ~QQuickItemRenderer() {}
    virtual VideoRendererId id() const;
    
signals:
    
public slots:
    

protected:
    virtual void drawFrame();

    // QQuickItem interface
protected:
    virtual QSGNode *updatePaintNode(QSGNode *node, UpdatePaintNodeData *data);

    // AVOutput interface
protected:
    virtual void convertData(const QByteArray &data);
    virtual bool write();

private:

};
typedef QQuickItemRenderer VideoRendererQQuickItem;
}

#endif // QTAV_QML_QQUICKRENDERER_H
