/***************************************************************************
 *  Copyright (C) 2010  Philipp Nordhus                                    *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#include "widget.h"
#include <QDebug>


namespace ui {


Widget::Widget() :
    m_visible(true)
{

}


Widget::~Widget()
{
    qDeleteAll(m_children);
}


void Widget::setVisible(bool visible)
{
    m_visible = visible;
}


void Widget::hide()
{
    m_visible = false;
}


void Widget::show()
{
    m_visible = true;
}


void Widget::addChild(Widget *widget)
{
    m_children.append(widget);
}


void Widget::doDraw()
{
    if (m_visible) {
        draw();
        foreach (Widget *widget, m_children)
            widget->doDraw();
    }
}


void Widget::doMousePressEvent(const QPointF &pos, Qt::MouseButton button)
{
    if (m_visible && m_rect.contains(pos)) {
        mousePressEvent(pos, button);
        foreach (Widget *widget, m_children)
            widget->doMousePressEvent(pos, button);
    }
}


void Widget::doMouseReleaseEvent(const QPointF &pos, Qt::MouseButton button)
{
    if (m_visible) {
        mouseReleaseEvent(pos, button);
        foreach (Widget *widget, m_children)
            widget->doMouseReleaseEvent(pos, button);
    }
}


void Widget::doMouseMoveEvent(const QPointF &pos)
{
    if (m_visible) {
        mouseMoveEvent(pos);
        foreach (Widget *widget, m_children)
            widget->doMouseMoveEvent(pos);
    }
}


} // namespace ui