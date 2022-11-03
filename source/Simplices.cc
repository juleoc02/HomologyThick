#include "../include/Simplices.h"
#include <cmath>

//*************************VERTICES********************************

const std::vector<double> 
Vertex::get_coordinates() const
{
    std::vector<double> coordinates = {x, y, z};
    return coordinates;
}

const bool
Vertex::is_valid() const
{
    if (isfinite(x) && isfinite(y) && isfinite(z))
    {
        return true;
    }
    else
    {
        return false;
    }
}

const bool
Vertex::operator== (const Vertex& vertex_1) const
{
    if (this->get_coordinates() == vertex_1.get_coordinates())
    {
        return true;
    }
    else
    {
        return false;
    }
}

const bool
Vertex::operator!= (const Vertex& vertex_1) const
{
    if (this->get_coordinates() != vertex_1.get_coordinates())
    {
        return true;
    }
    else
    {
        return false;
    }
}


//*************************EDGES********************************

const std::vector<Vertex>
Edge::get_vertices() const
{
    std::vector<Vertex> vertices = {vertex_1, vertex_2};
    return vertices;
}

const bool
Edge::is_valid() const
{
    if (vertex_1.is_valid() && vertex_2.is_valid())
    {
        if (vertex_1.get_coordinates() != vertex_2.get_coordinates())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

const bool
Edge::operator== (const Edge& edge_1) const
{
    if (this->get_vertices() == edge_1.get_vertices())
    {
        return true;
    }
    else
    {
        return false;
    }
}

const bool
Edge::operator!= (const Edge& edge_1) const
{
    if (this->get_vertices() != edge_1.get_vertices())
    {
        return true;
    }
    else
    {
        return false;
    }
}


//*************************FACES********************************

const std::vector<Edge>
Face::get_edges() const
{
    std::vector<Edge> edges = {edge_1, edge_2, edge_3};
    return edges;
}

const bool
Face::is_valid() const
{
    if (edge_1.is_valid() && edge_2.is_valid() && edge_3.is_valid())
    {
        if (edge_1.get_vertices()[1].get_coordinates() == edge_2.get_vertices()[0].get_coordinates() && edge_2.get_vertices()[1] == edge_3.get_vertices()[0] && edge_3.get_vertices()[1] == edge_1.get_vertices()[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

const bool
Face::operator== (const Face& face_1) const
{
    if (this->get_edges() == face_1.get_edges())
    {
        return true;
    }
    else
    {
        return false;
    }
}

const bool
Face::operator!= (const Face& face_1) const
{
    if (this->get_edges() != face_1.get_edges())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*************************TETS********************************

const std::vector<Face>
Tetrahedron::get_faces() const
{
    std::vector<Face> faces = {face_1, face_2, face_3, face_4};
    return faces;
}

const bool
Tetrahedron::is_valid() const
{
    if (face_1.is_valid() && face_2.is_valid() && face_3.is_valid() && face_4.is_valid())
    {
        if (face_1.get_edges() != face_2.get_edges() && face_1.get_edges() != face_3.get_edges() && face_1.get_edges() != face_4.get_edges() && face_2.get_edges() != face_3.get_edges() && face_2.get_edges() != face_4.get_edges() && face_3.get_edges() != face_4.get_edges())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

const bool
Tetrahedron::operator== (const Tetrahedron& tetrahedron_1) const
{
    if (this->get_faces() == tetrahedron_1.get_faces())
    {
        return true;
    }
    else
    {
        return false;
    }
}

const bool
Tetrahedron::operator!= (const Tetrahedron& tetrahedron_1) const
{
    if (this->get_faces() != tetrahedron_1.get_faces())
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Path: src/TriangulationSimplex.cc