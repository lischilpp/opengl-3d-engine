# OpenGL-3D-Engine
### A 3D engine written in C++ using OpenGL

## 🗺️ Navigation 
- [<code>🖼️ Screenshots</code>](#-screenshots)
- [<code>📋 Features</code>](#-features)
- [<code>🗄 Dependencies</code>](#-dependencies)
- [<code>📦 Getting started</code>](#-getting-started)
- [<code>📐 Design goals</code>](#-design-goals)
- [<code>📝 License</code>](#-license)
- [<code>❤️ Credits</code>](#-credits)

## 🖼️ Screenshots
<!--<p>
  <img src="screenshot1.png" width="500px" alt="screenshot1" />
</p>-->
  
## 📋 Features
- GameObject and scene management
- Transformations
- Skybox
- First person controller
- Keyboard event callbacks

## 🗄 Dependencies
libsoil-dev, libglm-dev, libglfw3-dev, libglew-dev

## 📦 Getting started
The engines code can be found [here](https://github.com/lischilpp/opengl-3d-engine/tree/master/src/LS3D)

This is an [example main.cpp](https://github.com/lischilpp/opengl-3d-engine/tree/master/src/main.cpp) for using the engine.

## 📐 Design goals
This engine aims to simplify and enhance the readability of 3D graphics code,
while preserving the flexibility to choose between using the provided abstractions and writing custom code.
To achieve this, it is designed with the maximum degree of modularity in mind.

## 📝 License
This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details

## ❤️ Credits
Some parts of the code are inspired by this great OpenGL Tutorial: https://learnopengl.com/

The textures are public domain images from https://texture.ninja.

The skybox is also public domain and can be found here: https://opengameart.org/content/space-skyboxes-0.

Loading of texture images is done using the public domain library stb.
