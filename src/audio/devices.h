/*
    Copyright © 2014-2016 by The qTox Project

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QTOX_AUDIO_H
#define QTOX_AUDIO_H

#include <QObject>
#include <QSharedData>

namespace qTox {
namespace Audio {

class Device
{
    class Private;

public:
    typedef QExplicitlySharedDataPointer<Private> PrivatePtr;

public:
    Device(Private* dev);
    Device(Device&&) = default;

    Device& operator=(Device& other);

public:
    bool isValid() const;
    QString name() const;

private:
    PrivatePtr d;
};

class Devices : public QObject
{
    Q_OBJECT
public:
    static Devices& self();
    inline static Devices& getInstance()
    {
        return self();
    }

private:
    Devices();
    ~Devices();

private:
    class Private;
    Private* d;
};

}
}

#endif