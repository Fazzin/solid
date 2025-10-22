#include <iostream>

class inputDevices {
    public: 
        virtual ~inputDevices() = default;
        virtual std::string getInput() const = 0;
};

class Keyboard : public inputDevices {
    std::string getInput() const override {
        return "User input from keyboard";
    }
};

class Mouse : public inputDevices {
public:
    std::string getInput() const override {
        return "User input from mouse";
    }
};

// Future new input device
// class Headphone : public inputDevices {}

// Right now this code assumes that input will come from the keyboard, 
// but we would like to be able to create an InputProcessor that 
// accepts input from the mouse (and potentially other input devices
// in the future). Note that each InputProcessor only needs to deal
// with one device.
class InputProcessor {
public:
    explicit InputProcessor(const inputDevices& device) : device_(device) {}
    void processInput() const {
        std::string input = device_.getInput();
        std::cout << "Processing: " << input << "\n";
    }

private:
    const inputDevices& device_;
};

// For demonstration
int main() {

    Keyboard keyboard;
    Mouse mouse;
    InputProcessor keyboardInput(keyboard);
    InputProcessor mouseInput(mouse);

    keyboardInput.processInput();
    mouseInput.processInput();
}
