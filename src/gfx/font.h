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

#ifndef GFX_FONT_H
#define GFX_FONT_H


#include "texture.h"
#include <QExplicitlySharedDataPointer>


namespace gfx {


class FontPrivate : public QSharedData
{
public:
    FontPrivate();

public:
    void load(const QString &filename, const QVector<QRgb> &colorTable, bool scale);
    QRect draw(const QString &text, int x, int y, int w, int h, bool alignHCenter = false, bool alignVCenter = false);
    int height() const { return m_height; }
    int width(const QString &text) const;

private:
    struct Symbol
    {
        QRectF rect;
        int width;
        int height;
    };

    Texture m_texture;
    QVector<Symbol> m_symbols;
    int m_height;
};


class Font
{
public:
    Font();
    Font(const QString &filename, const QVector<QRgb> &colorTable, bool scale = false);

public:
    void load(const QString &filename, const QVector<QRgb> &colorTable, bool scale = false);
    QRect draw(const QString &text, int x, int y);
    QRect draw(const QString &text, const QPoint &pos);
    QRect draw(const QString &text, const QPoint &pos, const QSize &size, bool alignHCenter, bool alignVCenter);
    QRect draw(const QString &text, const QSize &size, bool alignHCenter, bool alignVCenter);
    int height() const;
    int width(const QString &text) const;

private:
    QExplicitlySharedDataPointer<FontPrivate> d;
};


inline Font::Font() :
    d(new FontPrivate)
{

}


inline Font::Font(const QString &filename, const QVector<QRgb> &colorTable, bool scale) :
    d(new FontPrivate)
{
    load(filename, colorTable, scale);
}


inline void Font::load(const QString &filename, const QVector<QRgb> &colorTable, bool scale)
{
    d->load(filename, colorTable, scale);
}


inline QRect Font::draw(const QString &text, int x, int y)
{
    return d->draw(text, x, y, -1, -1);
}


inline QRect Font::draw(const QString &text, const QPoint &pos)
{
    return draw(text, pos.x(), pos.y());
}


inline QRect Font::draw(const QString &text, const QPoint &pos, const QSize &size, bool alignHCenter, bool alignVCenter)
{
    return d->draw(text, pos.x(), pos.y(), size.width(), size.height(), alignHCenter, alignVCenter);
}


inline QRect Font::draw(const QString &text, const QSize &size, bool alignHCenter, bool alignVCenter)
{
    return d->draw(text, 0, 0, size.width(), size.height(), alignHCenter, alignVCenter);
}


inline int Font::height() const
{
    return d->height();
}


inline int Font::width(const QString &text) const
{
    return d->width(text);
}


} // namespace gfx


#endif // GFX_FONT_H
