#include <SDL.h>
#include <vector>

// 2D vector
struct Vector2D {
    float x; // stores x coordinate value
    float y; // stores y coordinate value
};

class Character {
    public:
        // state of the character
        enum State {
            EActive,
            EPaused,
            EInactive
        };

        // constructor
        Character (class Game* game);
        // destructor
        virtual ~Character();

        // function called every frame to update the character
        void Update(float deltaTime);
        // function called every frame to update every components on the character
        void UpdateComponents(float deltaTime);
        // update function for specific characters
        virtual void UpdateCharacter(float deltaTime);
        
        void AddComponent(class Component* component);
        void RemoveComponent(class Component* component);

    private:
        State mState; // state of the character
        Vector2D mPosition; // position of the character
        float mScale; // scale of the character (100% == 1.0f)
        float mRotation; // rotation angle of the character (in radians)
        // components of the character
        std::vector<class Component*> mComponents; 
        class Game* mGame;

};