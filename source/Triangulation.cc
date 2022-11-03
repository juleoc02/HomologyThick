#include "../include/Triangulation.h"

Triangulation::add_vertex(Vertex &vertex_in)
{
    vertices.push_back(vertex_in);
}

Triangulation::add_edge(Edge &edge_in)
{
    edges.push_back(edge_in);
}

Triangulation::add_face(Face &face_in)
{
    faces.push_back(face_in);
}

Triangulation::add_tetrahedron(Tetrahedron &tetrahedron_in)
{
    tetrahedra.push_back(tetrahedron_in);
}