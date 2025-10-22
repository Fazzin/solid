#include <iostream>
#include <string>

class Bird {
public:
    explicit Bird(std::string name) : name_(std::move(name)) {}
    
    void lay_egg() const {
        std::cout << name_ << " is laying an Egg.\n";
    }
    const std::string& name() const { return name_;}
private:
    std::string name_;
};

class Ostrich : public Bird {
public:
    Ostrich() : Bird("Ostrich") {}
};

class Eagle: public Bird {
    public:
        Eagle() : Bird("Eagle") {}
        void fly() const {
            std::cout << name() << " flys insanely fast.\n";
        }
};

// For demonstration
int main() {
    Eagle eagle;
    Ostrich ostrich;
    
    eagle.lay_egg();
    eagle.fly();

    ostrich.lay_egg();
}
