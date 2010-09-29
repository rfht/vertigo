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


namespace gfx {


class Font
{
public:
    Font();
    Font(const QString &filename, const QVector<QRgb> &colorTable);

public:
    void load(const QString &filename, const QVector<QRgb> &colorTable);
    void draw(const QString &text, float x, float y);
    int height() const { return m_height; }

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


} // namespace gfx


#endif // GFX_FONT_H
