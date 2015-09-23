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

#ifndef FIGHT_ACTIVEOBJECT_H
#define FIGHT_ACTIVEOBJECT_H


#include "object.h"


namespace fight {


class Scenario;


class ActiveObject : public Object
{
public:
    ActiveObject(Scenario *scenario);
    ActiveObject(Scenario *scenario, txt::DesFile &file, int iff, const QString &name, const QString &cargo);

public:
    ConditionEvent* eventDestroy() { return &m_eventDestroy; }
    ConditionEvent* eventAttack() { return &m_eventAttack; }
    ConditionEvent* eventIdentify() { return &m_eventIdentify; }
    ConditionEvent* eventParalyze() { return &m_eventParalyze; }
    ConditionEvent* eventFinish() { return &m_eventFinish; }
    ConditionEvent* eventBoard() { return &m_eventBoard; }

    int iff() const { return m_iff; }
    const QString& name() const { return m_name; }
    const QString& cargo() const { return m_cargo; }
    float noise() const { return m_noise; }
    bool isIdentified() const { return m_eventIdentify.isCompleted(); }

    int kineticShield() const { return m_kineticShield; };
    int shockShield() const { return m_shockShield; };
    int kineticShieldMax() const { return m_kineticShieldMax; };
    int shockShieldMax() const { return m_shockShieldMax; };
    int kineticStrength() const { return m_kineticStrength; };
    int shockStrength() const { return m_shockStrength; };

    const Vector3D& velocity() const { return m_velocity; }

public:
    virtual void damage(int kinetic, int shock, const Vector3D &position);
    virtual void destroy();
    void identify();

protected:
    ConditionEvent m_eventDestroy;
    ConditionEvent m_eventAttack;
    ConditionEvent m_eventIdentify;
    ConditionEvent m_eventParalyze;
    ConditionEvent m_eventFinish;
    ConditionEvent m_eventBoard;

    int m_iff;
    QString m_name;
    QString m_cargo;
    float m_noise;
    bool m_identified;

    int m_kineticShield;
    int m_shockShield;
    int m_kineticShieldMax;
    int m_shockShieldMax;
    int m_kineticStrength;
    int m_shockStrength;

    Vector3D m_velocity;
};


} // namespace fight


#endif // FIGHT_ACTIVEOBJECT_H
