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

        void Move() {
            // Dummy logic to simulate movement
            x += speed;
            y += speed;
            z += speed;
        }
    };

    // Constructor to initialize the vector with a specific number of particles
    ParticleSystem(size_t count) {
        m_particles.resize(count); // Creates 'count' default-initialized Particles
    }

    void Simulation() {
        for (size_t i = 0; i < m_particles.size(); ++i)
            m_particles[i].Move();
    }

    size_t Size() const {
        return m_particles.size();
    }

private:
    std::vector<Particle> m_particles;
};

int main() {
    ParticleSystem::Particle individualParticle; // Creating an individual particle

    size_t particleCount = 10; // Set the number of particles here
    ParticleSystem p(particleCount); // Creating a ParticleSystem with 10 particles

    std::cout << "Initial particle count: " << p.Size() << std::endl;
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
