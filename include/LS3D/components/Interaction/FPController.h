#include "../EngineComponent.h"
#include "../Visual/Camera.h"
#include "../System/Input.h"
#include "../System/Time.h"
#include "../Utility/Math.h"

namespace Interaction
{
class FPController: public EngineComponent
{
public:
    FPController(Visual::Camera* camera, System::Input* input, System::Time* time);
    void Update();
    void FixedUpdate();
    struct KeyConfig
    {
        int Forward  = GLFW_KEY_W,
            Left     = GLFW_KEY_A,
            Backward = GLFW_KEY_S,
            Right    = GLFW_KEY_D,
            Up       = GLFW_KEY_SPACE,
            Down     = GLFW_KEY_LEFT_SHIFT;

    } Keys;
    float moveSpeed,
          mouseSpeed;
private:
    Visual::Camera* camera;
    System::Input* input;
    System::Time* time;
    Vector2 lastMousePosition;
    float firstMouseMovement;
};
}
