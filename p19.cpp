// Interfaces in C++(Pure Virtual Function)
// This will make sure that derived class has a structured and consistent use of Interfaces in Abstract class
#include <iostream>

class IRenderer
{
public:
    // pure Virtual Function, i.e, they have to have definitions in derived classes
    // You must implement these 2 classes in any of the derived classes
    virtual void Draw() = 0;
    virtual void Update() = 0;
    // Now this will be a abstract class as it just provides interfaces and not their implementations
};

class OpenGL : public IRenderer
{
public:
    void Draw() override
    {
        std::cout << "OpenGL::Draw()" << std::endl;
    }

    void Update() override
    {
        std::cout << "OpenGL::Update()" << std::endl;
    }
};

class Vulkan : public IRenderer
{
public:
    void Draw() override
    {
        std::cout << "Vulkan::Draw()" << std::endl;
    }

    void Update() override
    {
        std::cout << "Vulkan::Update()" << std::endl;
    }
    /*
        // Now if we want to have some custom function in Vulkan or OpenGL, we just cannot directly implement them in respective classes
        // before declaring that as interface in the base clas i.e. IRenderer
        // This way we will have consistency
        void DrawOptimizedVk() {    // if you create this function it will throw an error: 'class Irenderer' has no member named 'DrawOptimizedVk'
        }
    */
};

int main()
{
    IRenderer *myRenderer = new Vulkan; // We can make myRenderer as OpenGl or Vulkan (as seen in previous parts)

    // We cannot create an IRenderer object since it has a pure virtual function. So we need to either provide the implementation of
    // the functions in IRenderer or use the functions in derived class
    // IRenderer *myRenderer = new IRenderer; //This will throw "invalid new expression of absrtact class type"
    myRenderer->Update();
    myRenderer->Draw();

    return 0;
}