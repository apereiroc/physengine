//
// Created by Asier Pereiro Castro on 31/8/23.
//

#include <memory>
#include "SimBase.h"

//**
// * This game is just a race among cars.
// * When some car reaches the finish line, the animation ends
// **

#define FINISH_LINE (0.75*SCREEN_WIDTH)

class MyGame: public SimBase {
private:
    const double delta;
public:
    explicit MyGame(const double& delta)
    : delta(delta) {

        // Add the cars
        const double carWidth = 50, carHeight = 20;

        const std::string name0 = "Car1";
        const double x0 = 10;
        const double y0 = 250;
        const double vx0 = 5;
        const double vy0 = 0;

        const std::string name1 = "Car2";
        const double x1 = x0;
        const double y1 = y0 + 2 * carHeight;
        const double vx1 = 5.2;
        const double vy1 = 0.2;

        const std::string name2 = "Car3";
        const double x2 = x0;
        const double y2 = y1 + 2 * carHeight;
        const double vx2 = 4.8;
        const double vy2 = -0.2;

        addShape(Rectangle, name0, xStart0, yStart0, carWidth, carHeight);
        addShape(Rectangle, name1, xStart1, yStart1, carWidth, carHeight);
        addShape(Rectangle, name2, xStart2, yStart2, carWidth, carHeight);

        // Add velocities
        phys->setVelocity(name0, vx0, vy0);
        phys->setVelocity(name1, vx1, vy1);
        phys->setVelocity(name2, vx2, vy2);

        // Add finish line
        const double xLine = FINISH_LINE;
        const double widthLine = 5, heightLine = 25;
        double yLine = 0;

        while (yLine < SCREEN_HEIGHT){
            addShape(Rectangle, "Line " + std::to_string(yLine),
                     xLine, yLine, widthLine, heightLine, Colors::White);
            // Leave space among them
            yLine += heightLine + 30.0;
        }

        std::cout << phys->getNumObjects() << " objects initialised. " << std::endl;
    }

    void Run() const override {
        // Create event (mandatory for macOS, SDL based on Cocoa)
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            exit(0);

        // Clear the screen
        SDL_SetRenderDrawColor(rend->getRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(rend->getRenderer());

        // Integrate and render all objects in the engine
        const auto f =
                [this](const std::unique_ptr<PhysicsObject>& obj)
                {
                    obj->Integrate(delta);
                    obj->Render(rend->getRenderer());
                };

        phys->applyToObjects(f);

        // Update the screen
        SDL_RenderPresent(rend->getRenderer());
    }

    [[nodiscard]] bool endCondition() const override {
        bool win = false;
        std::string winner;
        const auto f =
                [this, &win, &winner](const std::unique_ptr<PhysicsObject>& obj)
                {
                        const std::string& name = obj->getName();

                        // Skip finishing lines objects
                        if (name.find("Line") == 0)
                            return;

                        // Rectangle position measured from upper left corner
                        // Need to sum its width
                        const double w = dynamic_cast<class Rectangle*>(obj.get())->getWidth();
                        const double actualX = obj->getPosition().x()+w;

                        if (actualX > FINISH_LINE){
                            win = true;
                            winner = name;
                        }
                };
        phys->applyToObjects(f);

        if (win)
            std::cout << "And the winner was... " << winner << std::endl;
        return win;
    }
};

int main() {
    const double FPS = 60;
    const double dt = 1.0/FPS;

    std::unique_ptr<MyGame> g(new MyGame(dt));

    while (!g->endCondition())
        g->Run();

    return 0;
}