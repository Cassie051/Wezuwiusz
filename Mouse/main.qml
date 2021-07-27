import QtQuick 2.12 as QQ2
import QtQuick.Window 2.12
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
Entity {
    id: root

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer{
                id: renderer
                camera: mainCamera
            }
        },
        InputSettings{ }
    ]

    Camera {
        id: mainCamera
        position: Qt.vector3d( 0.0, 0.0, 15.0 )
    }
    FirstPersonCameraController { camera: mainCamera }

    }
