#include <iostream>
#include <string>

using namespace std;

class ICharacter {
public:

    virtual string getAbilities() const = 0;

    virtual ~ICharacter() {} 

};


class Mario : public ICharacter {
public:

    string getAbilities() const override {
        return "Mario";
    }

    ~Mario() {
        cout << "Destroying Mario" << endl;
    }

};
class CharacterDecorator : public ICharacter {

protected:
    
    ICharacter* character;  // wrapped

public:

    CharacterDecorator(ICharacter* c){
        this->character = c;
    }
    
};

class HeightUp : public CharacterDecorator {
public:

    HeightUp(ICharacter* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with HeightUp";
    }

    ~HeightUp() {
        cout << "Destroying HeightUp Decorator" << endl;
    }
    
};

class GunPowerUp : public CharacterDecorator {
public:

    GunPowerUp(ICharacter* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Gun";
    }

    ~GunPowerUp() {
        cout << "Destroying GunPowerUp Decorator" << endl;
    }

};

class StarPowerUp : public CharacterDecorator {
public:

    StarPowerUp(ICharacter* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Star Power (Limited Time)";
    }
    
    ~StarPowerUp() {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

// The Decorator Pattern allows you to add responsibilities 
// to objects dynamically, without altering their structure or
// modifying their original code.

int main() {

    ICharacter* mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    // Decorate Mario with a HeightUp power-up.
    mario = new HeightUp(mario);
    cout << "After HeightUp: " << mario->getAbilities() << endl;

    // Decorate Mario further with a GunPowerUp.
    mario = new GunPowerUp(mario);
    cout << "After GunPowerUp: " << mario->getAbilities() << endl;

    ICharacter* tmario = mario;

    // Finally, add a StarPowerUp decoration.
    mario = new StarPowerUp(mario);
    cout << "After StarPowerUp: " << mario->getAbilities() << endl;

    delete mario;
    delete tmario;

    return 0;
}

// Note here at last moment , mario is having reference to
// starPowerUp so only its destructor is called.

// check when declared without new and statically then how things work.