#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
        {
            std::cout << "Copied " << std::endl;
        }
};

int main()
{
    std::vector<Vertex> vertices;
    vertices.reserve(2);
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(5, 6, 7);
    std::cout << vertices.size() << std::endl;
    return 0;
}