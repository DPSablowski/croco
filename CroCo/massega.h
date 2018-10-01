#ifndef MASSEGA_H
#define MASSEGA_H

#include <QDebug>
#include <QMetaType>
#include <QStringList>

class Message
{
public:
    Message();
    Message(const Message &other);
    ~Message();

    Message(const QString &body, const QStringList &headers);

    QString body() const;
    QStringList headers() const;

private:
    QString m_body;
    QStringList m_headers;
};

Q_DECLARE_METATYPE(Message);

QDebug operator<<(QDebug dbg, const Message &message);

#endif // MASSEGA_H
