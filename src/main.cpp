#include<vector>
#include <thread>
#include "LS3D/LSE.h"
#include "LS3D/components/System/Window.h"
#include "LS3D/components/System/Input.h"
#include "LS3D/components/System/Debugger.h"
#include "LS3D/components/System/Time.h"
#include "LS3D/components/Utility/Math.h"
#include "LS3D/components/Visual/Scene.h"
#include "LS3D/components/Visual/SceneObject.h"
#include "LS3D/components/Visual/Camera.h"
#include "LS3D/components/Visual/GeometryCreator.h"
#include "LS3D/components/Interaction/FPController.h"
#include "LS3D/components/Utility/FPSCounter.h"
#include "LS3D/components/Visual/Texture.h"
#include "LS3D/components/Visual/Skybox.h"


int main(void)
{
    System::Window Window;
    //Window.SetSize(1024.0f, 768.0f);
    Window.SetSize(1920.0f, 1080.0f);
    Window.SetTitle("LS3D");
    Window.SetBackground(0.0f, 0.0f, 0.0f);
    Window.Open();
    Window.SetVSync(false);

    System::Time Time;
    LSE Engine(&Time);
    Engine.AddComponent(&Time);

    System::Input Input(&Window);
    Engine.AddComponent(&Input);

    System::Debugger Debug;

    Visual::Scene Scene;
    Engine.AddComponent(&Scene);

    Visual::Shader::SetDefaultPath("../src/LS3D/components/Visual/Shaders/");

    // textures
    Visual::Texture stoneTexture;
    stoneTexture.Load("../res/textures/StoneFloor.jpg", 1000, 1000);

    Visual::Texture stone2Texture;
    stone2Texture.Load("../res/textures/StoneBricks.jpg", 1000, 1000);

    Visual::Texture crateTexture;
    crateTexture.Load("../res/textures/Crate.jpg", 600, 600);

    Visual::GeometryCreator GeometryCreator;

    // cube
    Visual::SceneObject cube;

    GeometryCreator.Cuboid (&cube.mesh, 1.0f, 1.0f, 1.0f);
    cube.TranslateY(2.0f);
    cube.SetTexture(&crateTexture);

    cube.mesh.uv.AddMultible({ 0.0f, 0.0f,
                               1.0f, 0.0f,
                               1.0f, 1.0f,
                               0.0f, 1.0f }, 6);

    cube.mesh.Push();
    Scene.AddObject(&cube);

    // floor
    Visual::SceneObject floor;
    floor.SetTexture(&stoneTexture);

    GeometryCreator.PlaneXZUp(&floor.mesh, 20.0f, 30.0f);

    floor.mesh.uv.Add({ 0.0f, 0.0f,
                        4.0f, 0.0f,
                        4.0f, 4.0f,
                        0.0f, 4.0f });
    floor.mesh.Push();
    Scene.AddObject(&floor);

    // wall back
    Visual::SceneObject wallBack;
    wallBack.SetTexture(&stone2Texture);

    GeometryCreator.PlaneXYFront(&wallBack.mesh, 20.0f, 10.0f);
    wallBack.Translate(0.0f, 5.0, -15.0f);

    wallBack.mesh.uv.Add({ 0.0f, 0.0f,
                           2.0f, 0.0f,
                           2.0f, 2.0f,
                           0.0f, 2.0f });

    wallBack.mesh.Push();
    Scene.AddObject(&wallBack);

     // wall front
    Visual::SceneObject wallFront;
    wallFront.SetTexture(&stone2Texture);

    GeometryCreator.PlaneXYBack(&wallFront.mesh, 20.0f, 10.0f);
    wallFront.Translate(0.0f, 5.0, 15.0f);

    wallFront.mesh.uv.Add({ 0.0f, 0.0f,
                            2.0f, 0.0f,
                            2.0f, 2.0f,
                            0.0f, 2.0f });

    wallFront.mesh.Push();
    Scene.AddObject(&wallFront);

     // wall left
    Visual::SceneObject wallLeft;
    wallLeft.SetTexture(&stone2Texture);

    GeometryCreator.PlaneYZRight(&wallLeft.mesh, 10.0f, 30.0f);
    wallLeft.Translate(-10.0f, 5.0f, 0.0f);

    wallLeft.mesh.uv.Add({ 0.0f, 0.0f,
                            2.0f, 0.0f,
                            2.0f, 2.0f,
                            0.0f, 2.0f });

    wallLeft.mesh.Push();
    Scene.AddObject(&wallLeft);


    Visual::Camera Camera(&Window);

    Interaction::FPController Controller(&Camera, &Input, &Time);
    Engine.AddComponent(&Controller);

    Camera.TranslateY(2.0f);

    Utility::FPSCounter FPS(&Time);
    Engine.AddComponent(&FPS);

    Visual::Texture SkyboxTexture;

    SkyboxTexture.Load("../res/textures/skyboxes/Space.png", 2048, 1436);

    Visual::Skybox Skybox(&Camera, &SkyboxTexture, &GeometryCreator, 256.0f);
    Scene.AddObject(&Skybox);

    // Window Loop

    bool wireframe = false;

    //cube.SetPositionY(2.0f);

    Camera.TranslateY(3);

    Input.AddKeyCallback([&] () {
        if (Input.KeyPressed(GLFW_KEY_ENTER))
            Window.Close();
        if (Input.KeyDown(GLFW_KEY_F1))
            Scene.SetWireframeMode(wireframe = !wireframe);
    });

    while (Window.Running())
    {
        Camera.Render();
        Scene.Render();
        //cube.RotateZ(Time.deltaTime);
        //cube.SetPositionY(sin(Time.time * 4) * 0.8f + 3.0f);
        //cube.RotateY(Time.deltaTime * 0.5);
        //Debug.Log(FPS.Get());
        Engine.Update();
    }

    return 0;
}
