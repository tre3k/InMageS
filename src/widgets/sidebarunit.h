#ifndef SIDEBARUNIT_H
#define SIDEBARUNIT_H

#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

class SideBarUnit : public QWidget
{
    Q_OBJECT
public:
    explicit SideBarUnit(QString text="", QString image_path="", QWidget *parent = nullptr);
    void setText(QString text);
    void setImage(QString filepath);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QLabel *label;
    QVBoxLayout *layout;
    QLabel *label_image;


signals:

public slots:
    void setPalleteNormal();
    void setPalleteSelected();
    void setPalleteEnabled();

};

#endif // SIDEBARUNIT_H
