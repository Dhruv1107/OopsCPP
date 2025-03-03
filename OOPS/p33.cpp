// Episode - 98
// Nested classes in C++
#include <iostream>
#include <vector>

class ParticleSystem {
public:
    struct Particle {
        float x{0.0f};
        float y{0.0f};
        float z{0.0f};
        float speed{1.0f};
        float lifetime{50.0f};

        void Move() { /* move particles */ }
    };

    void Simulation() {
        for (size_t i = 0; i < m_particles.size(); ++i)
            m_particles[i].Move();
    }

private:
    std::vector<Particle> m_particles;
};

int main() {
    ParticleSystem::Particle individualParticle; // Creating an individual particle
    ParticleSystem p; // Creating a ParticleSystem object
    p.Simulation(); // Running the simulation

    return 0;
}

/*
Nested Classes Overview:
    A nested class is a class defined within another class.
    The Particle struct is nested inside ParticleSystem.

Accessing Nested Class:
    The Particle struct is a public member of ParticleSystem, so it can be accessed using ParticleSystem::Particle.

Code Explanation:
    Particle struct contains properties like x, y, z, speed, and lifetime.
    Move() function is a placeholder for movement logic.
    Simulation() function iterates over a vector of particles and calls Move() on each.
    The m_particles vector is declared private to store multiple Particle objects.
*/
