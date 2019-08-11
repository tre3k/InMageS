#ifndef SIDEBARUNIT_H
#define SIDEBARUNIT_H

#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QMouseEvent>
#include <QPropertyAnimation>

class SideBarUnit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:
    explicit SideBarUnit(QString text="", QString image_path="", QWidget *parent = nullptr);
    void setText(QString text);
    void setImage(QString filepath);

    void setColor(QColor color);
    QColor color();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QLabel *label;
    QVBoxLayout *layout;
    QLabel *label_image;
    QPropertyAnimation *pAnimation;


signals:

public slots:
    void setPalleteNormal();
    void setPalleteSelected();
    void setPalleteEnabled();

};

#endif // SIDEBARUNIT_H
