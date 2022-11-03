#include 'Simplices.h'

class Triangulation
{
public:
    Triangulation() = default;
    ~Triangulation() = default;

    void add_vertex(TriangulationVertex &vertex_in);
    void add_edge(TriangulationEdge &edge_in);
    void add_face(TriangulationFace &face_in);
    void add_tetrahedron(TriangulationTetrahedron &tetrahedron_in);

    void remove_vertex(TriangulationVertex &vertex_in);
    void remove_edge(TriangulationEdge &edge_in);
    void remove_face(TriangulationFace &face_in);
    void remove_tetrahedron(TriangulationTetrahedron &tetrahedron_in);

private:
    std::vector<TriangulationVertex> vertices;
    std::vector<TriangulationEdge> edges;
    std::vector<TriangulationFace> faces;
    std::vector<TriangulationTetrahedron> tetrahedra;
};