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

#include "modulemanager.h"


namespace fight {


ModuleManager::ModuleManager(gfx::TextureManager &texMan) :
    m_textureManager(texMan)
{

}


Module ModuleManager::get(const QString &name)
{
    if (m_modules.contains(name))
        return m_modules.value(name);

    Module module(m_textureManager, "vfx:module/" + name);
    m_modules.insert(name, module);
    return module;
}


} // namespace fight
