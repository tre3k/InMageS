/*
 * This class discribe of buttons on left panel
 */

#ifndef SIDEBARUNIT_H
#define SIDEBARUNIT_H

#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QMouseEvent>
#include <QPropertyAnimation>

#define BACKGROUND_COLOR "#434343"
#define HIGHLIGHTED_COLOR "#575757"   // RESERVATION
#define BACKLIGHT_COLOR "#232323"

#define DURATION_ANIMATION 300          // in ms

class SideBarUnit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:
    explicit SideBarUnit(QString text="", QString image_path_normal="",QString image_path_active="", QWidget *parent = nullptr);
    void setText(QString text);
    void setImage(QString filepath);
    void setIndex(int index);
    int getIndex(void);

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

    QString image_file_normal, image_file_active;

    int n_index = 0;

signals:
    void clicked(int);

public slots:
    void setPalleteNormal();
    void setPalleteSelected();
    void setPalleteSelectedWithoutAnimation();
    void setPalleteEnabled();

};

#endif // SIDEBARUNIT_H
