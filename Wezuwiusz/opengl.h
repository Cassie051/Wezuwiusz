#ifndef OPENGL_H
#define OPENGL_H

#include <QOpenGLWidget>
#include <qopenglfunctions.h>

class OpenGL : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGL(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
private:
    void qColorToRGB(const QColor &C, float &r, float &g, float &b);
    float normalize_0_1(float val, float min, float max) const;
};

#endif // OPENGL_H
